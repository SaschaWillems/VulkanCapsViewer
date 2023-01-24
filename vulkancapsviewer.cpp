/*
*
* Vulkan hardware capability viewer
*
* Copyright (C) 2016-2022 by Sascha Willems (www.saschawillems.de)
*
* This code is free software, you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License version 3 as published by the Free Software Foundation.
*
* Please review the following information to ensure the GNU Lesser
* General Public License version 3 requirements will be met:
* http://opensource.org/licenses/lgpl-3.0.html
*
* The code is distributed WITHOUT ANY WARRANTY; without even the
* implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE.  See the GNU LGPL 3.0 for more details.
*
*/

#include "vulkancapsviewer.h"
#include "vulkanresources.h"
#include "vulkansurfaceinfo.hpp"
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include <type_traits>
#include <QMessageBox>
#include <QFileDialog>
#include <QStyleFactory>
#include <QDesktopServices>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QVariant>
#include <QInputDialog>
#include <QSysInfo>
#include <QDebug>
#include <QScroller>
#include <QEasingCurve>
#include <QSet>
#include <QWindow>
#include <QApplication>
#include <qnamespace.h>
#include <assert.h>
#include <settingsDialog.h>
#include "submitDialog.h"

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <sys/utsname.h>
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
#include <QX11Info>
#endif

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#include <wayland-client.h>
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#endif

#ifdef VK_USE_PLATFORM_IOS_MVK
extern "C" const char *getWorkingFolderForiOS(void);
#endif

using std::to_string;

const QString VulkanCapsViewer::version = "3.28";
const QString VulkanCapsViewer::reportVersion = "3.2";

OSInfo getOperatingSystem()
{
    // QSysInfo works for all supported operating systems
    OSInfo osInfo = {};
    osInfo.name = QSysInfo::productType().toStdString();
    osInfo.architecture = QSysInfo::buildCpuArchitecture().toStdString();
    osInfo.version = QSysInfo::productVersion().toStdString();
    // The Qt version used does not detect Windows 11, so we use Win32 API to detect it via the build version
#if defined(_WIN32)
    HMODULE hModule = LoadLibrary(TEXT("ntdll.dll"));
    if (hModule) {
        typedef NTSTATUS(WINAPI* RtlGetVersionFN)(PRTL_OSVERSIONINFOW);
        RtlGetVersionFN RtlGetVersion = reinterpret_cast<RtlGetVersionFN>(GetProcAddress(hModule, "RtlGetVersion"));
        if (RtlGetVersion) {
            RTL_OSVERSIONINFOW osVersionInfo = { 0 };
            osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
            if (RtlGetVersion(&osVersionInfo) == S_OK) {
                if (osVersionInfo.dwBuildNumber >= 22000) {
                    osInfo.version = "11";
                }
            }
        }
        FreeLibrary(hModule);
    }
#endif
    return osInfo;
}

// Convert a list variant into an imploded string
QString arrayToStr(QVariant value) {
    QList<QVariant> list = value.toList();
    QString imploded;
    for (auto i = 0; i < list.size(); i++) {
        imploded += list[i].toString();
        if (i < list.size() - 1)
            imploded += ", ";
    }
    return "[" + imploded + "]";
}


#if defined(VK_USE_PLATFORM_IOS_MVK) || defined(VK_USE_PLATFORM_ANDROID_KHR)
void setTouchProps(QWidget *widget) {
    QScroller *scroller = QScroller::scroller(widget);
    QScrollerProperties properties = scroller->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    properties.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy, overshootPolicy);
    properties.setScrollMetric(QScrollerProperties::DragVelocitySmoothingFactor, 0.6);
    properties.setScrollMetric(QScrollerProperties::MinimumVelocity, 0.0);
    properties.setScrollMetric(QScrollerProperties::MaximumVelocity, 0.5);
    properties.setScrollMetric(QScrollerProperties::AcceleratingFlickMaximumTime, 0.4);
    properties.setScrollMetric(QScrollerProperties::AcceleratingFlickSpeedupFactor, 1.2);
    properties.setScrollMetric(QScrollerProperties::SnapPositionRatio, 0.2);
    properties.setScrollMetric(QScrollerProperties::MaximumClickThroughVelocity, 0);
    properties.setScrollMetric(QScrollerProperties::DragStartDistance, 0.001);
    properties.setScrollMetric(QScrollerProperties::MousePressEventDelay, 0.5);
    scroller->grabGesture(widget, QScroller::LeftMouseButtonGesture);
    scroller->setScrollerProperties(properties);
}
#endif

VulkanCapsViewer::VulkanCapsViewer(QWidget *parent)
    : QMainWindow(parent)
{
    // Set current working directory to writable document folder
#if defined(VK_USE_PLATFOROM_IOS_MVK)
    setWorkingFolderForiOS();
#endif

    ui.setupUi(this);
    setWindowTitle("Vulkan Hardware Capability Viewer " + version);
    // Connect slots
    connect(ui.comboBoxGPU, SIGNAL(currentIndexChanged(int)), this, SLOT(slotComboBoxGPUIndexChanged(int)));
    connect(ui.toolButtonUpload, SIGNAL(pressed()), this, SLOT(slotUploadReport()));
    connect(ui.toolButtonSave, SIGNAL(pressed()), this, SLOT(slotSaveReport()));
    connect(ui.toolButtonOnlineDevice, SIGNAL(pressed()), this, SLOT(slotDisplayOnlineReport()));
    connect(ui.toolButtonOnlineDataBase, SIGNAL(pressed()), this, SLOT(slotBrowseDatabase()));
    connect(ui.toolButtonAbout, SIGNAL(pressed()), this, SLOT(slotAbout()));
    connect(ui.toolButtonExit, SIGNAL(pressed()), this, SLOT(slotClose()));
    connect(ui.toolButtonSettings, SIGNAL(pressed()), this, SLOT(slotSettings()));
    connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotComboTabChanged(int)));

    qApp->setStyle(QStyleFactory::create("Fusion"));
    boldFont.setBold(true);

    ui.label_header_top->setText(ui.label_header_top->text() + " " + version);
    
    
#ifdef ANDROID
    // Load Vulkan libraries on Android manually
    if (!loadVulkanLibrary()) {
        QMessageBox::warning(this, "Error", "Could not initialize Vulkan!\n\nPlease make sure that this device actually supports the Vulkan API.");
        exit(EXIT_FAILURE);
    }
#endif
    
#if defined(VK_USE_PLATFORM_IOS_MVK) || defined(VK_USE_PLATFORM_ANDROID_KHR)
    // Adjust toolbar to better fit mobile devices
    foreach (QToolButton *toolButton, findChildren<QToolButton *>()) {
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }
    ui.toolButtonSave->setVisible(false);
    // Touch scrolling
    foreach (QTreeView *widget, findChildren<QTreeWidget  *>()) {
        setTouchProps(widget);
        widget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget->setSelectionMode(QAbstractItemView::NoSelection);
        widget->setFrameStyle(QFrame::NoFrame);
    }

    foreach (QTreeView *widget, findChildren<QTreeView *>()) {
        setTouchProps(widget);
        widget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        widget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget->setSelectionMode(QAbstractItemView::NoSelection);
        widget->setFrameStyle(QFrame::NoFrame);
    }

    // No identation
    for (int i = 0; i < ui.tabWidgetDevice->count(); i++) {
        ui.tabWidgetDevice->widget(i)->layout()->setMargin(0);
    }

    QTabBar *tabBar = ui.tabWidgetDevice->findChild<QTabBar *>();
    tabBar->hide();
    ui.comboBox->setVisible(true);
#else
    ui.comboBox->setVisible(false);
#endif

    if (!initVulkan())
    {
        QMessageBox::warning(this, "Error", "Could not initialize Vulkan!\n\nMake sure that at least one installed device supports Vulkan and supports at least Version 1.1.");
        exit(EXIT_FAILURE);
    }

    if (QSysInfo::buildCpuArchitecture() == "i386")
    {
        QMessageBox::warning(this, "Warning", "You are running a 32-bit version of the application. Some Vulkan implementations may not support all GPU capabilities when running in 32-bit mode.");
    }

    // Models and filters
    // Core 1.0 properties
    ui.treeViewDeviceProperties->setModel(&filterProxies.propertiesCore10);
    connectFilterAndModel(models.propertiesCore10, filterProxies.propertiesCore10);
    connect(ui.filterLineEditProperties, SIGNAL(textChanged(QString)), this, SLOT(slotFilterPropertiesCore10(QString)));
    // Core 1.1 properties
    ui.treeViewDevicePropertiesCore11->setModel(&filterProxies.propertiesCore11);
    connectFilterAndModel(models.propertiesCore11, filterProxies.propertiesCore11);
    connect(ui.filterLineEditPropertiesCore11, SIGNAL(textChanged(QString)), this, SLOT(slotFilterPropertiesCore11(QString)));
    // Core 1.2 properties
    ui.treeViewDevicePropertiesCore12->setModel(&filterProxies.propertiesCore12);
    connectFilterAndModel(models.propertiesCore12, filterProxies.propertiesCore12);
    connect(ui.filterLineEditPropertiesCore12, SIGNAL(textChanged(QString)), this, SLOT(slotFilterPropertiesCore12(QString)));
    // Core 1.3 properties
    ui.treeViewDevicePropertiesCore13->setModel(&filterProxies.propertiesCore13);
    connectFilterAndModel(models.propertiesCore13, filterProxies.propertiesCore13);
    connect(ui.filterLineEditPropertiesCore13, SIGNAL(textChanged(QString)), this, SLOT(slotFilterPropertiesCore13(QString)));
    // Extension properties
    ui.treeViewDevicePropertiesExtensions->setModel(&filterProxies.propertiesExtensions);
    connectFilterAndModel(models.propertiesExtensions, filterProxies.propertiesExtensions);
    connect(ui.filterLineEditPropertiesExtensions, SIGNAL(textChanged(QString)), this, SLOT(slotFilterPropertiesExtensions(QString)));
    // Core 1.0 features
    ui.treeViewDeviceFeatures->setModel(&filterProxies.featuresCore10);
    connectFilterAndModel(models.featuresCore10, filterProxies.featuresCore10);
    connect(ui.filterLineEditFeatures, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeatures(QString)));
    // Core 1.1 features
    ui.treeViewDeviceFeaturesCore11->setModel(&filterProxies.featuresCore11);
    connectFilterAndModel(models.featuresCore11, filterProxies.featuresCore11);
    connect(ui.filterLineEditFeaturesCore11, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeaturesCore11(QString)));
    // Core 1.2 features
    ui.treeViewDeviceFeaturesCore12->setModel(&filterProxies.featuresCore12);
    connectFilterAndModel(models.featuresCore12, filterProxies.featuresCore12);
    connect(ui.filterLineEditFeaturesCore12, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeaturesCore12(QString)));
    // Core 1.3 features
    ui.treeViewDeviceFeaturesCore13->setModel(&filterProxies.featuresCore13);
    connectFilterAndModel(models.featuresCore13, filterProxies.featuresCore13);
    connect(ui.filterLineEditFeaturesCore13, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeaturesCore13(QString)));
    // Extension features
    ui.treeViewDeviceFeaturesExtensions->setModel(&filterProxies.featuresExtensions);
    connectFilterAndModel(models.featuresExtensions, filterProxies.featuresExtensions);
    connect(ui.filterLineEditFeaturesExtensions, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeaturesExtensions(QString)));
    // Extensions
    ui.treeViewDeviceExtensions->setModel(&filterProxies.extensions);
    connectFilterAndModel(models.extensions, filterProxies.extensions);
    connect(ui.filterLineEditExtensions, SIGNAL(textChanged(QString)), this, SLOT(slotFilterExtensions(QString)));
    // Formats
    ui.treeViewFormats->setModel(&filterProxies.formats);
    connectFilterAndModel(models.formats, filterProxies.formats);
    connect(ui.filterLineEditFormats, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFormats(QString)));
    // Profiles
    ui.treeViewDeviceProfiles->setModel(&filterProxies.profiles);
    connectFilterAndModel(models.profiles, filterProxies.profiles);
    connect(ui.filterLineEditProfiles, SIGNAL(textChanged(QString)), this, SLOT(slotFilterProfiles(QString)));

    getGPUs();
}

VulkanCapsViewer::~VulkanCapsViewer()
{    
    // Free up hidden window used on Apple platforms
#if defined(VK_USE_PLATFORM_IOS_MVK) || defined(VK_USE_PLATFORM_MACOS_MVK)
    if(pMetalSurrogate != nullptr)
        delete pMetalSurrogate;
#endif

    for (VulkanDeviceInfo &gpu : vulkanGPUs) {
        if (gpu.dev != VK_NULL_HANDLE) {
            vkDestroyDevice(gpu.dev, nullptr);
        }
    }
    if (vulkanContext.surface != VK_NULL_HANDLE) {
        vkDestroySurfaceKHR(vulkanContext.instance, vulkanContext.surface, nullptr);
    }
    if (vulkanContext.instance != VK_NULL_HANDLE) {
        vkDestroyInstance(vulkanContext.instance, nullptr);
    }
}

void VulkanCapsViewer::slotClose()
{
    close();
}

void VulkanCapsViewer::slotBrowseDatabase()
{
    QString link = "https://vulkan.gpuinfo.org/";
    QDesktopServices::openUrl(QUrl(link));
}

void VulkanCapsViewer::slotDisplayOnlineReport()
{
    int reportId = database.getReportId(vulkanGPUs[selectedDeviceIndex]);
    QUrl url(database.databaseUrl + "displayreport.php?id=" + QString::number(reportId));
    QDesktopServices::openUrl(url);
}

std::string apiVersionText(uint32_t apiVersion)
{
    return to_string(VK_VERSION_MAJOR(apiVersion)) + "." + to_string(VK_VERSION_MINOR(apiVersion)) + "." + to_string(VK_VERSION_PATCH(apiVersion));
}

void VulkanCapsViewer::slotAbout()
{
    std::stringstream aboutText;
    aboutText << "<p>Vulkan Hardware Capability Viewer " << version.toStdString() << "<br/><br/>"
        "Copyright (c) 2016-2023 by <a href='https://www.saschawillems.de'>Sascha Willems</a><br/><br/>"
        "This tool is <b>Free Open Source Software</b><br/><br/>"
        "For usage and distribution details refer to the readme<br/><br/>"
        "<a href='https://www.gpuinfo.org'>https://www.gpuinfo.org</a><br><br>"
        "Vulkan instance API version: " + apiVersionText(instanceApiVersion) + "<br/>"
        "Compiled against Vulkan header version: " + to_string(VK_HEADER_VERSION) + "<br/><br/>";
    aboutText << "</p>";
    QMessageBox::about(this, tr("About the Vulkan Hardware Capability Viewer"), QString::fromStdString(aboutText.str()));
}

void VulkanCapsViewer::slotComboBoxGPUIndexChanged(int index)
{
    if (index != selectedDeviceIndex)
    {
        displayDevice(index);
    }
}

void VulkanCapsViewer::slotSaveReport()
{
    VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];

#ifndef VK_USE_PLATFORM_IOS_MVK
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Report to disk"), device.properties["deviceName"].toString() + ".json", tr("json (*.json)"));

    if (!fileName.isEmpty()) {
        saveReport(fileName, "", "");
    }

#else
    // On iOS, you cannot choose where to save the file, but we need some sort of
    // acknowledgement to the end user that the save has occured. It also seems
    // rather disingenuous to say it's saved if we don't actually check for an error.
    QString fileName = getWorkingFolderForiOS();
    fileName += "/";
    fileName += device.properties["deviceName"].toString();
    fileName += ".json";

    QMessageBox msgBox;
    if (!saveReport(fileName, "", "")) {
        msgBox.setText("Report saved to the iTunes file sharing folder.");
    } else {
        msgBox.setText("Error writing to iTunes file sharing folder.");
    }
    msgBox.exec();

#endif
}

void VulkanCapsViewer::slotUploadReport()
{
    VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];

    if (device.hasFeaturModifyingTool) {
        QMessageBox::warning(this, "Upload disabled", "A feature modifying tool was detected (e.g. an active profiles layer)! Report uploads are disabled. Please disable any feature modifying tool and restart the application.");
        return;
    }

    QString error;
    if (!database.checkServerConnection(error))
    {
        QMessageBox::warning(this, "Error", "Could not connect to database:<br>" + error);
        return;
    }
    // Upload new report
    if (reportState == ReportState::not_present) {
        SubmitDialog dialog(settings.submitterName, "Submit new report");
        if (dialog.exec() == QDialog::Accepted) {
            QString message;
            QJsonObject reportJson;
            reportToJson(dialog.getSubmitter(), dialog.getComment(), reportJson);
            if (database.uploadReport(reportJson, message))
            {
                QMessageBox::information(this, "Report submitted", "Your report has been uploaded to the database!\n\nThank you for your contribution!");
                checkReportDatabaseState();
            }
            else
            {
                QMessageBox::warning(this, "Error", "The report could not be uploaded : \n" + message);
            }
        }
        return;
    }

    // Update existing report
    if (reportState == ReportState::is_updatable) {
        SubmitDialog dialog(settings.submitterName, "Update existing report");
        if (dialog.exec() == QDialog::Accepted) {
            int reportId = database.getReportId(device);
            QApplication::setOverrideCursor(Qt::WaitCursor);
            QString updateLog;
            bool updateResult = database.postReportForUpdate(device, reportId, updateLog);
            QApplication::restoreOverrideCursor();
            if (updateResult)
            {
                QMessageBox::information(this, "Report updated", "The report has been updated with the following information:\n\n" + updateLog + "\nThank you for your contribution!");
            }
            else
            {
                QMessageBox::warning(this, "Error", "The report could not be updated");
            }
            checkReportDatabaseState();
        }
        return;
    }

    // Show link to database for existing reports
    if (reportState == ReportState::is_present) {
        int reportId = database.getReportId(device);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Device already present", "A report for the selected device is already present in the database.\n\nDo you want to open the report in your browser?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QUrl url(database.databaseUrl + "displayreport.php?id=" + QString::number(reportId));
            QDesktopServices::openUrl(url);
        }
        return;
    }
}

void VulkanCapsViewer::slotSettings()
{
    settingsDialog dialog(settings);
    dialog.setModal(true);
    dialog.exec();
    settings.restore();
    checkReportDatabaseState();
}

void VulkanCapsViewer::slotFilterPropertiesCore10(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.propertiesCore10.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterPropertiesCore11(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.propertiesCore11.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterPropertiesCore12(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.propertiesCore12.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterPropertiesCore13(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.propertiesCore13.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterPropertiesExtensions(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.propertiesExtensions.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFeatures(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.featuresCore10.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFeaturesCore11(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.featuresCore11.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFeaturesCore12(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.featuresCore12.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFeaturesCore13(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.featuresCore13.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFeaturesExtensions(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.featuresExtensions.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterExtensions(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.extensions.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterFormats(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.formats.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotFilterProfiles(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.profiles.setFilterRegExp(regExp);
}

void VulkanCapsViewer::slotComboTabChanged(int index)
{
    ui.tabWidgetDevice->setCurrentIndex(index);
}

bool VulkanCapsViewer::initVulkan()
{
    VkResult vkRes;

    // Get the max. supported Vulkan Version if vkEnumerateInstanceVersion is available (loader version 1.1 and up)
    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = reinterpret_cast<PFN_vkEnumerateInstanceVersion>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
    if (vkEnumerateInstanceVersion) {
        vkEnumerateInstanceVersion(&instanceApiVersion);
    } else {
        instanceApiVersion = VK_API_VERSION_1_0;
    }

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "VulkanCapsViewer";
    appInfo.applicationVersion = 1;
    appInfo.pEngineName = "VulkanCapsViewer";
    appInfo.engineVersion = 1;
    appInfo.apiVersion = instanceApiVersion;

    // Create Vulkan instance
    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    // Get instance layers
    uint32_t layerCount = 0;
    std::vector<VkLayerProperties> instanceLayerProperties;
    do
    {
        vkRes = vkEnumerateInstanceLayerProperties(&layerCount, NULL);
        instanceLayerProperties.resize(layerCount);
        if (layerCount > 0) {
            vkRes = vkEnumerateInstanceLayerProperties(&layerCount, &instanceLayerProperties.front());
        }
    } while (vkRes == VK_INCOMPLETE);
    assert(!vkRes);

    for (auto& layerProperty : instanceLayerProperties) {
        VulkanLayerInfo layer;
        layer.properties = layerProperty;
        instanceLayers.push_back(layer);
    }

    // Platform specific surface extensions
    std::vector<std::string> possibleSurfaceExtensions = {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
      VK_KHR_ANDROID_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
      VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_WIN32_KHR)
      VK_KHR_WIN32_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
      VK_KHR_XCB_SURFACE_EXTENSION_NAME,
#endif
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    VK_MVK_MACOS_SURFACE_EXTENSION_NAME,
#endif

#if defined(VK_USE_PLATFORM_IOS_MVK)
   VK_MVK_IOS_SURFACE_EXTENSION_NAME,
#endif
    };

    std::vector<const char*> enabledExtensions = {};

    uint32_t availableExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, nullptr);
    std::vector<VkExtensionProperties> availableExtensions(availableExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, availableExtensions.data());

    if (availableExtensionCount != 0) {
        enabledExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
    }

    std::vector<std::string> surfaceExtensionsAvailable = {};

    for (const std::string& possibleExtension : possibleSurfaceExtensions) {
      for (const auto& availableExtension : availableExtensions) {
        if (possibleExtension == availableExtension.extensionName) {
          surfaceExtensionsAvailable.push_back(possibleExtension);
          enabledExtensions.push_back(possibleExtension.c_str());
          break;
        }
      }
    }

    // Get instance extensions
    instanceExtensions.clear();
    do {
        uint32_t extCount;
        vkRes = vkEnumerateInstanceExtensionProperties(NULL, &extCount, NULL);
        if (vkRes != VK_SUCCESS) {
            break;
        }
        std::vector<VkExtensionProperties> extensions(extCount);
        vkRes = vkEnumerateInstanceExtensionProperties(NULL, &extCount, &extensions.front());
        instanceExtensions.insert(instanceExtensions.end(), extensions.begin(), extensions.end());
    } while (vkRes == VK_INCOMPLETE);

    // Check support for new property and feature queries
    deviceProperties2Available = false;
    for (auto& ext : instanceExtensions) {
        if (strcmp(ext.extensionName, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
            deviceProperties2Available = true;
            enabledExtensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            break;
        }
    }

#if defined(VK_USE_PLATFORM_MACOS_MVK) && (VK_HEADER_VERSION >= 216)
    instanceCreateInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    enabledExtensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
    enabledExtensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
#endif

    instanceCreateInfo.ppEnabledExtensionNames = enabledExtensions.data();
    instanceCreateInfo.enabledExtensionCount = (uint32_t)enabledExtensions.size();

    // Create vulkan Instance
    vkRes = vkCreateInstance(&instanceCreateInfo, nullptr, &vulkanContext.instance);
    if (vkRes != VK_SUCCESS)
    {
        QString error;
        if (vkRes == VK_ERROR_INCOMPATIBLE_DRIVER)
        {
            error = "No compatible Vulkan driver found!\nThis version requires a Vulkan driver that is compatible with at least Vulkan 1.1";
        }
        else
        {
            error = "Could not create Vulkan instance!\nError: " + QString::fromStdString(vulkanResources::resultString(vkRes));
        }
        QMessageBox::warning(this, tr("Error"), error);
        return false;
    }

#ifdef ANDROID
    loadVulkanFunctions();
#endif

    // Function pointers for new features/properties
    if (deviceProperties2Available) {
        vulkanContext.vkGetPhysicalDeviceFeatures2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceFeatures2KHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceFeatures2KHR"));
        if (!vulkanContext.vkGetPhysicalDeviceFeatures2KHR) {
            deviceProperties2Available = false;
            QMessageBox::warning(this, tr("Error"), "Could not get function pointer for vkGetPhysicalDeviceFeatures2KHR (even though extension is enabled!)\nNew features and properties won't be displayed!");
        }
        vulkanContext.vkGetPhysicalDeviceProperties2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2KHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceProperties2KHR"));
        if (!vulkanContext.vkGetPhysicalDeviceProperties2KHR) {
            deviceProperties2Available = false;
            QMessageBox::warning(this, tr("Error"), "Could not get function pointer for vkGetPhysicalDeviceProperties2KHR (even though extension is enabled!)\nNew features and properties won't be displayed!");
        }
    }

    vulkanContext.vkGetPhysicalDeviceSurfaceSupportKHR = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceSurfaceSupportKHR"));

    // Create a surface
    for (auto surface_extension : surfaceExtensionsAvailable) {
        VkResult surfaceResult = VK_ERROR_INITIALIZATION_FAILED;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
        if (surface_extension == VK_KHR_WIN32_SURFACE_EXTENSION_NAME) {
            VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
            surfaceCreateInfo.hinstance = GetModuleHandle(nullptr);
            surfaceCreateInfo.hwnd = reinterpret_cast<HWND>(this->winId());
            surfaceResult = vkCreateWin32SurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface);
        }
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if (surface_extension == VK_KHR_ANDROID_SURFACE_EXTENSION_NAME) {

            // Get a native window via JNI
            // Qt doesn't offer access to this, so we have to do this manually
            // Note: Purely based on countless hours of trial-and-error, need to check on other devices
            // todo: cleanup, error checking

            // Get window
            QAndroidJniObject activity = QtAndroid::androidActivity();
            QAndroidJniObject window;
            if (activity.isValid())
            {
                window = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
            }

            if (window.isValid())
            {

                // Get a surface texture
                QAndroidJniObject surfaceTexture = QAndroidJniObject("android/graphics/SurfaceTexture", "(I)V", jint(0));
                qDebug() << surfaceTexture.isValid();

                // Get a surface based on the texture
                QAndroidJniObject surface("android/view/Surface", "(Landroid/graphics/SurfaceTexture;)V", surfaceTexture.object());
                qDebug() << surface.isValid();

                if (surfaceTexture.isValid())
                {
                    // Create a native window from our surface that can be used to create the Vulkan surface
                    QAndroidJniEnvironment qjniEnv;
                    nativeWindow = ANativeWindow_fromSurface(qjniEnv, surface.object());
                }
            }

            if (nativeWindow)
            {
                VkAndroidSurfaceCreateInfoKHR surfaceCreateInfo = {};
                surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
                surfaceCreateInfo.window = nativeWindow;
                surfaceResult = vkCreateAndroidSurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, NULL, &vulkanContext.surface);
            }
        }
#endif

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        if (surface_extension == VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME) {
            VkWaylandSurfaceCreateInfoKHR surfaceCreateInfo = {};
            surfaceCreateInfo.pNext = nullptr;
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
            surfaceCreateInfo.display = wl_display_connect(NULL);
            surfaceCreateInfo.surface = nullptr;
            surfaceResult = vkCreateWaylandSurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface);
        }
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
        if (surface_extension == VK_KHR_XCB_SURFACE_EXTENSION_NAME) {
            VkXcbSurfaceCreateInfoKHR surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            surfaceCreateInfo.connection = QX11Info::connection();
            surfaceCreateInfo.window = static_cast<xcb_window_t>(this->winId());
            surfaceResult = vkCreateXcbSurfaceKHR(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface);
        }
#endif

#if defined(VK_USE_PLATFORM_MACOS_MVK)
        if (surface_extension == VK_MVK_MACOS_SURFACE_EXTENSION_NAME) {
            VkMacOSSurfaceCreateInfoMVK surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
            pMetalSurrogate = new QVukanSurrogate();
            surfaceCreateInfo.pView = (void*)pMetalSurrogate->winId();
            surfaceResult = vkCreateMacOSSurfaceMVK(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface);
        }
#endif

#if defined(VK_USE_PLATFORM_IOS_MVK)
        if (surface_extension == VK_MVK_IOS_SURFACE_EXTENSION_NAME) {
            VkIOSSurfaceCreateInfoMVK surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
            pMetalSurrogate = new QVukanSurrogate();
            surfaceCreateInfo.pView = (void*)pMetalSurrogate->winId();
            surfaceResult = vkCreateIOSSurfaceMVK(vulkanContext.instance, &surfaceCreateInfo, nullptr, &vulkanContext.surface);
        }
#endif
        if (surfaceResult == VK_SUCCESS) {
            vulkanContext.surfaceExtension = surface_extension;
            break;
        } else {
            vulkanContext.surface = VK_NULL_HANDLE;
        }
    }

    displayInstanceLayers();
    displayInstanceExtensions();

    return true;
}

void VulkanCapsViewer::getGPUinfo(VulkanDeviceInfo *GPU, uint32_t id, VkPhysicalDevice device)
{
    VkResult vkRes;

    GPU->id = id;
    GPU->device = device;
    GPU->readExtensions();
    GPU->readPhysicalProperties();
    GPU->readLayers();
    GPU->readQueueFamilies();
    GPU->readPhysicalFeatures();
    GPU->readPhysicalLimits();
    GPU->readPhysicalMemoryProperties();
    GPU->readSurfaceInfo();
    GPU->readPlatformDetails();
    GPU->readProfiles();
    // Request all available queues
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    for (uint32_t i = 0; i < GPU->queueFamilies.size(); ++i)
    {
        float queuePriorities[1] = { 0.0f };
        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = i;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = queuePriorities;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    std::vector<const char*> enabledExtensions;
#if defined(VK_USE_PLATFORM_MACOS_MVK) && (VK_HEADER_VERSION >= 216)
    enabledExtensions.push_back(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME);
#endif

    // Init device

    VkDeviceCreateInfo info = {};
    info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    info.pQueueCreateInfos = queueCreateInfos.data();
    info.queueCreateInfoCount = (uint32_t)queueCreateInfos.size();
    info.enabledLayerCount = 0;
    if (enabledExtensions.size() > 0) {
        info.enabledExtensionCount = static_cast<uint32_t>(enabledExtensions.size());
        info.ppEnabledExtensionNames = enabledExtensions.data();
    };

    vkRes = vkCreateDevice(GPU->device, &info, nullptr, &GPU->dev);

    if (vkRes != VK_SUCCESS)
    {
        QString error = "Could not create a Vulkan device!\nError: " + QString::fromStdString(vulkanResources::resultString(vkRes));
        QMessageBox::warning(this, tr("Error"), error);
        exit(EXIT_FAILURE);
    }

    GPU->readSupportedFormats();
    GPU->os = getOperatingSystem();
    GPU->reportVersion = reportVersion;
    GPU->appVersion = version;

    // Check if any feature modifying tool is active for this device (e.g. profiles layer)
    // This information is used to disable uploads to the database
    GPU->hasFeaturModifyingTool = false;
    PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT{};
    vkGetPhysicalDeviceToolPropertiesEXT = reinterpret_cast<PFN_vkGetPhysicalDeviceToolPropertiesEXT>(vkGetInstanceProcAddr(vulkanContext.instance, "vkGetPhysicalDeviceToolPropertiesEXT"));
    if (vkGetPhysicalDeviceToolPropertiesEXT) {
        uint32_t numTools;
        vkGetPhysicalDeviceToolPropertiesEXT(vulkanGPUs[0].device, &numTools, nullptr);
        std::vector<VkPhysicalDeviceToolPropertiesEXT> toolProperties{};
        toolProperties.resize(numTools);
        vkGetPhysicalDeviceToolPropertiesEXT(vulkanGPUs[0].device, &numTools, toolProperties.data());
        for (auto& toolProps : toolProperties) {
            if (toolProps.purposes & VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT) {
                qWarning().nospace() << "Found feature modifying tool \"" << toolProps.description << "\" for \"" << GPU->props.deviceName << "\", uploads for this device will be disabled";
                GPU->hasFeaturModifyingTool = true;
            }
        }
    }
}

void VulkanCapsViewer::getGPUs()
{
    VkResult vkRes;
    uint32_t numGPUs;

    // Enumerate devices
    vkRes = vkEnumeratePhysicalDevices(vulkanContext.instance, &numGPUs, NULL);
    if (vkRes != VK_SUCCESS)
    {
        QMessageBox::warning(this, tr("Error"), "Could not enumerate device count!");
        return;
    }
    std::vector<VkPhysicalDevice> vulkanDevices;
    vulkanDevices.resize(numGPUs);

    vkRes = vkEnumeratePhysicalDevices(vulkanContext.instance, &numGPUs, &vulkanDevices.front());
    if (vkRes != VK_SUCCESS)
    {
        QMessageBox::warning(this, tr("Error"), "Could not enumerate physical devices!");
        return;
    }

    vulkanGPUs.resize(numGPUs);

    for (uint32_t i = 0; i < numGPUs; i++)
    {
        getGPUinfo(&vulkanGPUs[i], i, vulkanDevices[i]);
    }

    ui.comboBoxGPU->clear();
    for (auto& GPU : vulkanGPUs)
    {
        QString deviceName = QString::fromStdString("[GPU" + to_string(GPU.id) + "] " + GPU.props.deviceName);
        ui.comboBoxGPU->addItem(deviceName);
    }

    if (vulkanGPUs.size() > 0)
    {
        displayDevice(0);
    }
    else
    {
        QMessageBox::warning(this, tr("Error"), "Could not find a GPU with Vulkan support!");
    }

    // Only display device selection of more than once device is present (Android only)
#ifdef __ANDROID__
    ui.widgetDeviceSelection->setVisible(vulkanGPUs.size() > 1);
#endif
}

void VulkanCapsViewer::connectFilterAndModel(QStandardItemModel& model, TreeProxyFilter& filter)
{
    filter.setSourceModel(&model);
    filter.setFilterKeyColumn(-1);
    filter.setRecursiveFilteringEnabled(true);
}

QTreeWidgetItem *addTreeItem(QTreeWidgetItem *parent, const std::string& key, const std::string& value)
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem(parent);
    newItem->setText(0, QString::fromStdString(key));
    newItem->setText(1, QString::fromStdString(value));
    parent->addChild(newItem);
    return newItem;
}

QTreeWidgetItem *addTreeItemVkBool32(QTreeWidgetItem *parent, const std::string& key, const VkBool32 value)
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem(parent);
    newItem->setText(0, QString::fromStdString(key));
    newItem->setText(1, (value) ? "true" : "false");
    newItem->setForeground(1, (value) ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
    parent->addChild(newItem);
    return newItem;
}

void addTreeItemFlag(QTreeWidgetItem *parent, const QString& flagName, const bool flag)
{
    if (flag)
    {
        QTreeWidgetItem *newItem = new QTreeWidgetItem(parent);
        newItem->setText(0, flagName);
        parent->addChild(newItem);
    }
}

template<typename BitsType>
QTreeWidgetItem *addTreeItemFlags(QTreeWidgetItem *parent, const std::string& flagsName, const VkFlags flags, std::string(*const flagToString)(BitsType) )
{
    auto flagsItem = addTreeItem(parent, flagsName, flags ? vulkanResources::toHexString(flags) : std::string("none"));

    for (typename std::underlying_type<BitsType>::type bit = 0x1; bit != 0; bit <<= 1){
        const QString bitName = QString::fromStdString(flagToString(static_cast<BitsType>(bit)));
        addTreeItemFlag(flagsItem, bitName, flags & bit);
    }

    return flagsItem;
}

void addVkBool32Item(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(iterator.value().toBool() ? "true" : "false");
    item[1]->setForeground(iterator.value().toBool() ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
    parent->appendRow(item);
}

void addVkSampleCountFlagsItem(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    const auto samples = static_cast<VkSampleCountFlags>(iterator.value().toUInt());
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(vulkanResources::toQStringList(samples));
    parent->appendRow(item);
}

void addUUIDItem(QStandardItem* parent, const QString& key, uint8_t* UUID)
{
    std::ostringstream ss;
    ss << std::hex << std::noshowbase << std::uppercase;
    for (uint32_t i = 0; i < VK_UUID_SIZE; i++) {
        if (i == 4 || i == 6 || i == 8 || i == 10) ss << '-';
        ss << std::right << std::setw(2) << std::setfill('0') << static_cast<unsigned short>(UUID[i]);
    }
    QList<QStandardItem*> item;
    item << new QStandardItem(key);
    item << new QStandardItem(QString::fromStdString(ss.str()));
    parent->appendRow(item);
}

void addUUIDItem(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    const QJsonArray values = iterator.value().toJsonArray();
    std::ostringstream ss;
    ss << std::hex << std::noshowbase << std::uppercase << std::setfill('0');
    for (size_t i = 0; i < VK_UUID_SIZE; i++) {
        if (i == 4 || i == 6 || i == 8 || i == 10) ss << '-';
        ss << std::setw(2) << static_cast<unsigned short>(values[static_cast<int>(i)].toInt());
    }
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(QString::fromStdString(ss.str()));
    parent->appendRow(item);
}

void addLUIDItem(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    const QJsonArray values = iterator.value().toJsonArray();
    std::ostringstream ss;
    ss << std::hex << std::noshowbase << std::uppercase << std::setfill('0');
    for (size_t i = 0; i < VK_LUID_SIZE; i++) {
        if (i == 4) ss << '-';
        ss << std::setw(2) << static_cast<unsigned short>(values[static_cast<int>(i)].toInt());
    }
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(QString::fromStdString(ss.str()));
    parent->appendRow(item);
}

void addHexItem(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(vulkanResources::toHexQString(iterator.value().toULongLong()));
    parent->appendRow(item);
}

void addVariantListItem(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    QList<QStandardItem*> item;
    item << new QStandardItem(iterator.key());
    item << new QStandardItem(arrayToStr(iterator.value()));
    parent->appendRow(item);
}

template<typename BitsType>
void addBitFlagsItem(QStandardItem* parent, const QString& key, const VkFlags flags, std::string(* const flagToString)(BitsType))
{
    QList<QStandardItem*> flagsParentItem;
    flagsParentItem << new QStandardItem(key);
    flagsParentItem << new QStandardItem(QString::fromStdString(vulkanResources::toHexString(flags)));
    parent->appendRow(flagsParentItem);
    for (typename std::underlying_type<BitsType>::type bit = 0x1; bit != 0; bit <<= 1) {
        const QString bitName = QString::fromStdString(flagToString(static_cast<BitsType>(bit)));
        if (flags & bit) {
            QList<QStandardItem*> flagItem;
            flagItem << new QStandardItem(bitName);
            flagItem << new QStandardItem();
            flagsParentItem[0]->appendRow(flagItem);
        }
    }
    if (key == "subgroupSupportedStages") {
        if ((flags & VK_SHADER_STAGE_ALL_GRAPHICS) == VK_SHADER_STAGE_ALL_GRAPHICS) {
            QList<QStandardItem*> flagItem;
            flagItem << new QStandardItem(QString::fromStdString(vulkanResources::shaderStagesBitString(VK_SHADER_STAGE_ALL_GRAPHICS)));
            flagItem << new QStandardItem();
            flagsParentItem[0]->appendRow(flagItem);
        }
        if ((flags & VK_SHADER_STAGE_ALL) == VK_SHADER_STAGE_ALL) {
            QList<QStandardItem*> flagItem;
            flagItem << new QStandardItem(QString::fromStdString(vulkanResources::shaderStagesBitString(VK_SHADER_STAGE_ALL)));
            flagItem << new QStandardItem();
            flagsParentItem[0]->appendRow(flagItem);
        }
    }
}

void addPropertiesRow(QStandardItem* parent, const QVariantMap::const_iterator& iterator)
{
    QString key = iterator.key();

    if (vulkanResources::skipValueNames.contains(key)) {
        return;
    }

    if (vulkanResources::boolValueNames.contains(key)) {
        addVkBool32Item(parent, iterator);
        return;
    };
    if (vulkanResources::sampleFlagsValueNames.contains(key)) {
        addVkSampleCountFlagsItem(parent, iterator);
        return;
    }
    if (vulkanResources::uuidValueNames.contains(key)) {
        addUUIDItem(parent, iterator);
        return;
    }
    if (vulkanResources::luidValueNames.contains(key)) {
        addLUIDItem(parent, iterator);
        return;
    }
    if (vulkanResources::hexValueNames.contains(key)) {
        addHexItem(parent, iterator);
        return;
    }
    if (iterator.value().canConvert(QVariant::List)) {
        addVariantListItem(parent, iterator);
        return;
    }
    if (key == "subgroupSupportedOperations") {
        const VkSubgroupFeatureFlags flags = iterator.value().toUInt();
        addBitFlagsItem(parent, iterator.key(), flags, vulkanResources::subgroupFeatureBitString);
        return;
    }
    if (key == "subgroupSupportedStages") {
        const VkShaderStageFlags flags = iterator.value().toUInt();
        addBitFlagsItem(parent, iterator.key(), flags, vulkanResources::shaderStagesBitString);
        return;
    }

    if (vulkanResources::replaceKeyNames.contains(key)) {
        key = vulkanResources::replaceKeyNames[key];
    }

    QList<QStandardItem*> item;
    item << new QStandardItem(key);
    item << new QStandardItem(iterator.value().toString());
    parent->appendRow(item);
}

void VulkanCapsViewer::displayDevice(int index)
{
    assert(index < vulkanGPUs.size());

    VulkanDeviceInfo device = vulkanGPUs[index];
    selectedDeviceIndex = index;

    displayDeviceProperties(&device);
    displayDeviceMemoryProperties(&device);
    displayDeviceFeatures(&device);
    displayDeviceFormats(&device);
    displayDeviceExtensions(&device);
    displayDeviceQueues(&device);
    displayDeviceSurfaceInfo(device);
    displayOSInfo(device);
    displayDeviceProfiles(&device);

    checkReportDatabaseState();
}

void VulkanCapsViewer::displayDeviceProperties(VulkanDeviceInfo *device)
{
    // Core 1.0
    models.propertiesCore10.clear();
    QStandardItem* rootItem = models.propertiesCore10.invisibleRootItem();
    for (QVariantMap::const_iterator iter = device->properties.begin(); iter != device->properties.end(); ++iter) {
        addPropertiesRow(rootItem, iter);
    }
    addUUIDItem(rootItem, "pipelineCacheUUID", device->props.pipelineCacheUUID);
    // Core 1.0 limits
    QList<QStandardItem*> core10LimitsItem;
    core10LimitsItem << new QStandardItem("Limits");
    core10LimitsItem[0]->setFont(boldFont);
    rootItem->appendRow(core10LimitsItem);
    for (QVariantMap::const_iterator iter = device->limits.begin(); iter != device->limits.end(); ++iter) {
        addPropertiesRow(core10LimitsItem[0], iter);
    }
    // Core 1.0 sparse properties
    QList<QStandardItem*> core10SparseItem;
    core10SparseItem << new QStandardItem("Sparse properties");
    core10SparseItem[0]->setFont(boldFont);
    rootItem->appendRow(core10SparseItem);
    for (QVariantMap::const_iterator iter = device->sparseProperties.begin(); iter != device->sparseProperties.end(); ++iter) {
        addVkBool32Item(core10SparseItem[0], iter);
    }
#if !defined(__ANDROID__)
    ui.treeViewDeviceProperties->expandAll();
#endif
    ui.treeViewDeviceProperties->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Core 1.1
    models.propertiesCore11.clear();
    if (!(device->core11Properties.empty())) {
        ui.tabWidgetProperties->setTabEnabled(1, true);
        QStandardItem* rootItem = models.propertiesCore11.invisibleRootItem();
        for (QVariantMap::const_iterator iter = device->core11Properties.begin(); iter != device->core11Properties.end(); ++iter) {
            addPropertiesRow(rootItem, iter);
        }
        ui.treeViewDevicePropertiesCore11->expandAll();
        ui.treeViewDevicePropertiesCore11->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetProperties->setTabEnabled(1, false);
    }

    // Core 1.2
    models.propertiesCore12.clear();
    if (!(device->core12Properties.empty())) {
        ui.tabWidgetProperties->setTabEnabled(2, true);
        QStandardItem* rootItem = models.propertiesCore12.invisibleRootItem();
        for (QVariantMap::const_iterator iter = device->core12Properties.begin(); iter != device->core12Properties.end(); ++iter) {
            addPropertiesRow(rootItem, iter);
        }
        ui.treeViewDevicePropertiesCore12->expandAll();
        ui.treeViewDevicePropertiesCore12->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetProperties->setTabEnabled(2, false);
    }

    // Core 1.3
    models.propertiesCore13.clear();
    if (!(device->core13Properties.empty())) {
        ui.tabWidgetProperties->setTabEnabled(3, true);
        QStandardItem* rootItem = models.propertiesCore13.invisibleRootItem();
        for (QVariantMap::const_iterator iter = device->core13Properties.begin(); iter != device->core13Properties.end(); ++iter) {
            addPropertiesRow(rootItem, iter);
        }
        ui.treeViewDevicePropertiesCore13->expandAll();
        ui.treeViewDevicePropertiesCore13->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetProperties->setTabEnabled(3, false);
    }

    // Extensions
    models.propertiesExtensions.clear();
    if (!(device->properties2.empty())) {
        ui.tabWidgetProperties->setTabEnabled(4, true);
        QStandardItem* rootItem = models.propertiesExtensions.invisibleRootItem();
        for (auto& extension : device->extensions) {
            bool hasProperties = false;
            QList<QStandardItem*> extItem;
            for (auto& property : device->properties2) {
                if (strcmp(property.extension, extension.extensionName) == 0) {
                    if (!hasProperties) {
                        hasProperties = true;
                        extItem << new QStandardItem(QString::fromStdString(extension.extensionName));
                        extItem << new QStandardItem();
                    }
                    QList<QStandardItem*> propertyItem;
                    propertyItem << new QStandardItem(QString::fromStdString(property.name));

                    if (property.value.canConvert(QVariant::List)) {
                        propertyItem << new QStandardItem(arrayToStr(property.value));
                    }
                    else {
                        switch (property.value.type()) {
                        case QVariant::Bool: {
                            bool boolVal = property.value.toBool();
                            propertyItem << new QStandardItem(boolVal ? "true" : "false");
                            propertyItem[1]->setForeground(boolVal ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
                            break;
                        }
                        default:
                            propertyItem << new QStandardItem(property.value.toString());
                        }
                    }
                    extItem.first()->appendRow(propertyItem);
                }
            }
            if (hasProperties) {
                rootItem->appendRow(extItem);
            }
        }
        models.propertiesExtensions.sort(0);
        ui.treeViewDevicePropertiesExtensions->expandAll();
        ui.treeViewDevicePropertiesExtensions->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetProperties->setTabEnabled(4, false);
    }
}

void VulkanCapsViewer::displayDeviceMemoryProperties(VulkanDeviceInfo *device)
{
    using namespace vulkanResources;

    QTreeWidget *treeWidget = ui.treeWidgetDeviceMemory;
    treeWidget->clear();
    // Memory heaps
    for (uint32_t i = 0; i < device->memoryProperties.memoryHeapCount; i++)
    {
        QTreeWidgetItem* memoryHeapItem = new QTreeWidgetItem(treeWidget);
        memoryHeapItem->setText(0, QString::fromStdString("Memory heap " + std::to_string(i)));
        memoryHeapItem->setFont(0, boldFont);

        const VkMemoryHeap heapType = device->memoryProperties.memoryHeaps[i];
        addTreeItem(memoryHeapItem, "Device size", to_string(heapType.size));
        addTreeItemFlags(memoryHeapItem, "Flags", heapType.flags, memoryHeapBitString)->setExpanded(true);

        // Add memory types belonging to this heap
        QTreeWidgetItem* memoryTypesItem = addTreeItem(memoryHeapItem, "Memory types", "");
        uint32_t memTypeInHeapIndex = 0;
        for (uint32_t j = 0; j < device->memoryProperties.memoryTypeCount; ++j)
        {            
            const VkMemoryType memoryType = device->memoryProperties.memoryTypes[j];
            if (memoryType.heapIndex == i) {
                QTreeWidgetItem* memoryTypeItem = addTreeItem(memoryTypesItem, "Memory type " + std::to_string(memTypeInHeapIndex), "");
                memoryTypeItem->setFont(0, boldFont);
                memoryTypeItem->setExpanded(true);
                addTreeItemFlags(memoryTypeItem, "Property flags", memoryType.propertyFlags, memoryPropBitString)->setExpanded(true);
                memTypeInHeapIndex++;
            }
        }
        memoryTypesItem->setExpanded(true);
        memoryHeapItem->setExpanded(true);
    }
    for (int i = 0; i < treeWidget->columnCount(); i++)
        treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void VulkanCapsViewer::displayDeviceFeatures(VulkanDeviceInfo *device)
{
    // Core 1.0
    models.featuresCore10.clear();
    QStandardItem *rootItem = models.featuresCore10.invisibleRootItem();
    for(QVariantMap::const_iterator iter = device->features.begin(); iter != device->features.end(); ++iter) {
        addVkBool32Item(rootItem, iter);
    }
    ui.treeViewDeviceFeatures->expandAll();
    ui.treeViewDeviceFeatures->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Core 1.1
    models.featuresCore11.clear();
    if (!(device->core11Features.empty())) {
        ui.tabWidgetFeatures->setTabEnabled(1, true);
        QStandardItem *rootItem = models.featuresCore11.invisibleRootItem();
        for(QVariantMap::const_iterator iter = device->core11Features.begin(); iter != device->core11Features.end(); ++iter) {
            addVkBool32Item(rootItem, iter);
        }
        ui.treeViewDeviceFeaturesCore11->expandAll();
        ui.treeViewDeviceFeaturesCore11->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetFeatures->setTabEnabled(1, false);
    }

    // Core 1.2
    models.featuresCore12.clear();
    if (!(device->core12Features.empty())) {
        ui.tabWidgetFeatures->setTabEnabled(2, true);
        QStandardItem *rootItem = models.featuresCore12.invisibleRootItem();
        for(QVariantMap::const_iterator iter = device->core12Features.begin(); iter != device->core12Features.end(); ++iter) {
            addVkBool32Item(rootItem, iter);
        }
        ui.treeViewDeviceFeaturesCore12->expandAll();
        ui.treeViewDeviceFeaturesCore12->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetFeatures->setTabEnabled(2, false);
    }

    // Core 1.3
    models.featuresCore13.clear();
    if (!(device->core13Features.empty())) {
        ui.tabWidgetFeatures->setTabEnabled(3, true);
        QStandardItem* rootItem = models.featuresCore13.invisibleRootItem();
        for (QVariantMap::const_iterator iter = device->core13Features.begin(); iter != device->core13Features.end(); ++iter) {
            addVkBool32Item(rootItem, iter);
        }
        ui.treeViewDeviceFeaturesCore13->expandAll();
        ui.treeViewDeviceFeaturesCore13->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetFeatures->setTabEnabled(3, false);
    }

    // Extensions
    models.featuresExtensions.clear();
    if (!(device->features2.empty())) {
        ui.tabWidgetFeatures->setTabEnabled(4, true);
        QStandardItem* rootItem = models.featuresExtensions.invisibleRootItem();
        for (auto& extension : device->extensions) {
            bool hasFeatures = false;
            QList<QStandardItem*> extItem;
            for (auto& feature : device->features2) {
                if (strcmp(feature.extension, extension.extensionName) == 0) {
                    if (!hasFeatures) {
                        hasFeatures = true;
                        extItem << new QStandardItem(QString::fromStdString(extension.extensionName));
                        extItem << new QStandardItem();
                    }
                    QList<QStandardItem*> featureItem;
                    featureItem << new QStandardItem(QString::fromStdString(feature.name));
                    featureItem << new QStandardItem((feature.supported) ? "true" : "false");
                    featureItem[1]->setForeground((feature.supported) ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
                    extItem.first()->appendRow(featureItem);
                }
            }
            if (hasFeatures) {
                rootItem->appendRow(extItem);
            }
        }
        models.featuresExtensions.sort(0);
        ui.treeViewDeviceFeaturesExtensions->expandAll();
        ui.treeViewDeviceFeaturesExtensions->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
    else {
        ui.tabWidgetFeatures->setTabEnabled(4, false);
    }

}

void VulkanCapsViewer::displayInstanceLayers()
{
    ui.treeWidgetInstanceLayers->clear();
    for (auto& layer : instanceLayers) {
        QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui.treeWidgetInstanceLayers);
        treeItem->setText(0, QString::fromUtf8(layer.properties.layerName));
        treeItem->setText(1, QString::fromStdString(vulkanResources::versionToString(layer.properties.specVersion)));
        treeItem->setText(2, QString::fromStdString(vulkanResources::revisionToString(layer.properties.implementationVersion)));
        treeItem->setText(3, QString::fromStdString(to_string(layer.extensions.size())));
        treeItem->setText(4, layer.properties.description);
        for (auto& layerExt : layer.extensions) {
            addTreeItem(treeItem, layerExt.extensionName, vulkanResources::revisionToString(layerExt.specVersion));
        }
    }
    for (int i = 0; i < ui.treeWidgetInstanceLayers->columnCount(); i++)
        ui.treeWidgetInstanceLayers->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void VulkanCapsViewer::displayInstanceExtensions()
{
    ui.treeWidgetInstanceExtensions->clear();
    for (auto& ext : instanceExtensions) {
        QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui.treeWidgetInstanceExtensions);
        treeItem->setText(0, QString::fromUtf8(ext.extensionName));
        treeItem->setText(1, QString::fromStdString(vulkanResources::revisionToString(ext.specVersion)));
    }
    ui.treeWidgetInstanceExtensions->sortByColumn(0, Qt::SortOrder::AscendingOrder);
    for (int i = 0; i < ui.treeWidgetInstanceExtensions->columnCount(); i++) {
        ui.treeWidgetInstanceExtensions->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
}

void VulkanCapsViewer::displayOSInfo(VulkanDeviceInfo& device)
{
    ui.treeWidgetOS->clear();
    std::unordered_map<std::string, std::string> osInfo;
    osInfo["Name"] = device.os.name;
    osInfo["Version"] = device.os.version;
    osInfo["Architecture"] = device.os.architecture;
    for (auto& info : osInfo) {
        QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui.treeWidgetOS);
        treeItem->setText(0, QString::fromStdString(info.first));
        treeItem->setText(1, QString::fromStdString(info.second));
    }
    for (int i = 0; i < ui.treeWidgetOS->columnCount(); i++) {
        ui.treeWidgetOS->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }
    if (device.platformdetails.size() > 0) {
        QTreeWidgetItem* treeItemPlatformDetails = new QTreeWidgetItem(ui.treeWidgetOS);
        treeItemPlatformDetails->setText(0, "Platform details");
        for (auto& detail : device.platformdetails) {
            QTreeWidgetItem* treeItemDetail = new QTreeWidgetItem(treeItemPlatformDetails);
            treeItemDetail->setText(0, QString::fromStdString(detail.first));
            treeItemDetail->setText(1, QString::fromStdString(detail.second));
        }
        treeItemPlatformDetails->setExpanded(true);
    }
}

void addFlagModelItem(QStandardItem *parent, QString flagName, bool flag)
{
    if (flag)
    {
        QList<QStandardItem *> flagItems;
        flagItems << new QStandardItem(flagName);
        parent->appendRow(flagItems);
    }
}

void VulkanCapsViewer::displayDeviceFormats(VulkanDeviceInfo *device)
{
    models.formats.clear();
    QStandardItem *rootItem = models.formats.invisibleRootItem();
    for (auto const &format : device->formats)
    {
        QList<QStandardItem *> rowItems;
        rowItems << new QStandardItem(QString::fromStdString(vulkanResources::formatString(format.format)));

        std::vector<VkFormatFeatureFlags> featureFlags =
        {
            format.properties.linearTilingFeatures,
            format.properties.optimalTilingFeatures,
            format.properties.bufferFeatures
        };

        uint32_t i = 1;
        for (auto& featureFlag : featureFlags)
        {
            rowItems << new QStandardItem((featureFlag != 0) ? "true" : "false");
            rowItems[i]->setForeground((featureFlag != 0) ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
            ++i;
        }

        rootItem->appendRow(rowItems);

        struct featureSet {
            std::string name;
            VkFlags flags;
        };
        std::vector<featureSet> featureSets =
        {
            { "Linear tiling flags", format.properties.linearTilingFeatures },
            { "Optimal tiling flags", format.properties.optimalTilingFeatures },
            { "Buffer features flags", format.properties.bufferFeatures }
        };

        if (format.supported)
        {
            for (auto& featureSet : featureSets)
            {
                QList<QStandardItem *> flagItems;
                flagItems << new QStandardItem(QString::fromStdString(featureSet.name));

                if (featureSet.flags == 0)
                {
                    QList<QStandardItem *> flagItem;
                    flagItem << new QStandardItem("none");
                    flagItems[0]->appendRow(flagItem);
                }
                else
                {
                #define ADD_FLAG(flag) \
                    if (featureSet.flags & flag) \
                    { \
                        QList<QStandardItem *> flagItem; \
                        QString flagname(#flag); \
                        flagname = flagname.replace("VK_FORMAT_FEATURE_", ""); \
                        flagItem << new QStandardItem(flagname); \
                        flagItems[0]->appendRow(flagItem); \
                    }

                    // Core
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_BLIT_SRC_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_BLIT_DST_BIT)
                    // 1.1
                    ADD_FLAG(VK_FORMAT_FEATURE_TRANSFER_SRC_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_TRANSFER_DST_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_DISJOINT_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT)

                    // EXT
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT)
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG)
                }

                rowItems[0]->appendRow(flagItems);

            }
        }
    }

    QStringList formatHeaders;
    formatHeaders << "Format" << "Linear" << "Optimal" << "Buffer";
    models.formats.setHorizontalHeaderLabels(formatHeaders);

    ui.treeViewFormats->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    for (int32_t i = 1; i < models.formats.columnCount(); ++i)
    {
        ui.treeViewFormats->header()->setSectionResizeMode(i, QHeaderView::Fixed);
    }
    ui.treeViewFormats->sortByColumn(0, Qt::SortOrder::AscendingOrder);
}

void VulkanCapsViewer::displayDeviceExtensions(VulkanDeviceInfo *device)
{
    models.extensions.clear();
    QStandardItem *rootItem = models.extensions.invisibleRootItem();

    for (auto& extension : device->extensions) {
        QList<QStandardItem *> extItem;
        extItem << new QStandardItem(QString::fromStdString(extension.extensionName));
        extItem << new QStandardItem(QString::fromStdString(vulkanResources::revisionToString(extension.specVersion)));
        rootItem->appendRow(extItem);
    }
    models.extensions.sort(0);

    ui.treeViewDeviceExtensions->expandAll();
    ui.treeViewDeviceExtensions->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void VulkanCapsViewer::displayDeviceQueues(VulkanDeviceInfo *device)
{
    QTreeWidget* treeWidget = ui.treeWidgetQueues;
    treeWidget->clear();
    for (size_t i = 0; i < device->queueFamilies.size(); i++)
    {
        VulkanQueueFamilyInfo queueFamily = device->queueFamilies[i];
        QTreeWidgetItem *queueItem = new QTreeWidgetItem(treeWidget);
        queueItem->setText(0, QString::fromStdString("Queue family " + std::to_string(i)));
        queueItem->setFont(0, boldFont);
        // Support flags
        addTreeItemFlags(queueItem, "Flags", queueFamily.properties.queueFlags, vulkanResources::queueBitString)->setExpanded(true);
        // Queue properties
        addTreeItem(queueItem, "queueCount", to_string(queueFamily.properties.queueCount));
        addTreeItem(queueItem, "timestampValidBits", to_string(queueFamily.properties.timestampValidBits));
        addTreeItem(queueItem, "minImageTransferGranularity.width", to_string(queueFamily.properties.minImageTransferGranularity.width));
        addTreeItem(queueItem, "minImageTransferGranularity.height", to_string(queueFamily.properties.minImageTransferGranularity.height));
        addTreeItem(queueItem, "minImageTransferGranularity.depth", to_string(queueFamily.properties.minImageTransferGranularity.depth));
        addTreeItemVkBool32(queueItem, "Supports presentation", queueFamily.supportsPresent);
        queueItem->setExpanded(true);
    }
    for (int i = 0; i < treeWidget->columnCount(); i++)
        treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void VulkanCapsViewer::displayDeviceSurfaceInfo(VulkanDeviceInfo &device)
{
    using namespace vulkanResources;

    QTreeWidget *treeWidget = ui.treeWidgetDeviceSurface;
    treeWidget->clear();

    if (!device.surfaceInfo.validSurface)
    {
        QTreeWidgetItem *errorItem = addTreeItem(treeWidget->invisibleRootItem(), "Could not get a valid surface, no surface information available!", "");
        errorItem->setForeground(0, QColor::fromRgb(255, 0, 0));
        treeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        return;
    }

    // Surface extension used
    addTreeItem(treeWidget->invisibleRootItem(), "Surface extension", vulkanContext.surfaceExtension);

    // Surface capabilities
    QTreeWidgetItem *surfaceCapsItem = addTreeItem(treeWidget->invisibleRootItem(), "Surface Capabilities", "");
    surfaceCapsItem->setFont(0, boldFont);

    VkSurfaceCapabilitiesKHR surfaceCaps = device.surfaceInfo.capabilities;
    addTreeItem(surfaceCapsItem, "minImageCount", to_string(surfaceCaps.minImageCount));
    addTreeItem(surfaceCapsItem, "maxImageCount", to_string(surfaceCaps.maxImageCount));
    addTreeItem(surfaceCapsItem, "maxImageArrayLayers", to_string(surfaceCaps.maxImageArrayLayers));
    addTreeItem(surfaceCapsItem, "minImageExtent", to_string(surfaceCaps.minImageExtent.width) + " x " + to_string(surfaceCaps.minImageExtent.height));
    addTreeItem(surfaceCapsItem, "maxImageExtent", to_string(surfaceCaps.maxImageExtent.width) + " x " + to_string(surfaceCaps.maxImageExtent.height));
    addTreeItemFlags(surfaceCapsItem, "Supported usage flags", surfaceCaps.supportedUsageFlags, imageUsageBitString)->setExpanded(true);
    addTreeItemFlags(surfaceCapsItem, "Supported transforms", surfaceCaps.supportedTransforms, surfaceTransformBitString) ->setExpanded(true);
    addTreeItemFlags(surfaceCapsItem, "Composite alpha flags", surfaceCaps.supportedCompositeAlpha, compositeAlphaBitString) ->setExpanded(true);

    // Surface modes
    QTreeWidgetItem *modesItem = addTreeItem(treeWidget->invisibleRootItem(), "Present modes", arraySizeToString(device.surfaceInfo.presentModes.size()));
    modesItem->setFont(0, boldFont);
    if (!device.surfaceInfo.presentModes.empty())
    {
        for (auto presentMode : device.surfaceInfo.presentModes)
        {
            addTreeItem(modesItem, presentModeKHRString(presentMode), "");
        }
    } else {
        addTreeItem(modesItem, "none", "");
    }
    modesItem->setExpanded(true);

    // Surface formats
    QTreeWidgetItem *formatsItem = addTreeItem(treeWidget->invisibleRootItem(), "Surface formats", arraySizeToString(device.surfaceInfo.formats.size()));
    formatsItem->setFont(0, boldFont);
    if (!device.surfaceInfo.formats.empty())
    {
        uint32_t index = 0;
        for (auto surfaceFormat : device.surfaceInfo.formats)
        {
            QTreeWidgetItem *formatItem = addTreeItem(formatsItem, "Surface format " + std::to_string(index), "");
            addTreeItem(formatItem, "Format", (formatString(surfaceFormat.format)));
            addTreeItem(formatItem, "Color space", (colorSpaceKHRString(surfaceFormat.colorSpace)));
            formatItem->setExpanded(true);
            index++;
        }
    } else {
        addTreeItem(formatsItem, "none", "");
    }
    formatsItem->setExpanded(true);

    surfaceCapsItem->setExpanded(true);

    for (int i = 0; i < treeWidget->columnCount(); i++) {
        treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

}

void VulkanCapsViewer::displayDeviceProfiles(VulkanDeviceInfo* device)
{
    models.profiles.clear();
    QStandardItem* rootItem = models.profiles.invisibleRootItem();

    for (auto& profile : device->profiles) {
        QList<QStandardItem*> extItem;
        extItem << new QStandardItem(QString::fromStdString(profile.profileName));
        extItem << new QStandardItem(QString::fromStdString(vulkanResources::revisionToString(profile.specVersion)));
        extItem << new QStandardItem(profile.supported ? "true" : "false");
        extItem[2]->setForeground(profile.supported ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
        rootItem->appendRow(extItem);
    }
    models.profiles.sort(0, Qt::SortOrder::AscendingOrder);

    QStringList headers;
    headers << "Profile" << "Spec Version" << "Supported";
    models.profiles.setHorizontalHeaderLabels(headers);

    ui.treeViewDeviceProfiles->setHeaderHidden(false);
    ui.treeViewDeviceProfiles->expandAll();
    ui.treeViewDeviceProfiles->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void VulkanCapsViewer::reportToJson(QString submitter, QString comment, QJsonObject& jsonObject)
{
    VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];
    jsonObject = device.toJson(submitter, comment);

    // Add instance information
    QJsonObject jsonInstance;
    // Extensions
    QJsonArray jsonExtensions;
    for (auto& ext : instanceExtensions) {
        QJsonObject jsonExt;
        jsonExt["extensionName"] = ext.extensionName;
        jsonExt["specVersion"] = int(ext.specVersion);
        jsonExtensions.append(jsonExt);
    }
    jsonInstance["extensions"] = jsonExtensions;
    // Layers
    QJsonArray jsonLayers;
    for (auto& layer : instanceLayers) {
        QJsonObject jsonLayer;
        jsonLayer["layerName"] = layer.properties.layerName;
        jsonLayer["description"] = layer.properties.description;
        jsonLayer["specVersion"] =  int(layer.properties.specVersion);
        jsonLayer["implementationVersion"] =  int(layer.properties.implementationVersion);
        QJsonArray jsonLayerExtensions;
        for (auto& ext : layer.extensions) {
            QJsonObject jsonExt;
            jsonExt["extensionName"] = ext.extensionName;
            jsonExt["specVersion"] = int(ext.specVersion);
            jsonLayerExtensions.append(jsonExt);
        }
        jsonLayer["extensions"] = jsonLayerExtensions;
        jsonLayers.append(jsonLayer);
    }
    jsonInstance["layers"] = jsonLayers;

    jsonObject["instance"] = jsonInstance;
}

bool VulkanCapsViewer::saveReport(QString fileName, QString submitter, QString comment)
{
    QJsonObject jsonReport;
    reportToJson(submitter, comment, jsonReport);
    QJsonDocument doc(jsonReport);
    qint64 bytesWritten;
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    bytesWritten = jsonFile.write(doc.toJson(QJsonDocument::Indented));
    return (bytesWritten > -1);
}

void VulkanCapsViewer::checkReportDatabaseState()
{
    if (vulkanGPUs[selectedDeviceIndex].hasFeaturModifyingTool) {
        setReportState(ReportState::update_disabled);
        return;
    }

    ui.labelDevicePresent->setText("<font color='#000000'>Connecting to database...</font>");
    ui.toolButtonOnlineDevice->setEnabled(false);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QString message;
    if (!database.checkServerConnection(message))
    {
        ui.labelDevicePresent->setText("<font color='#FF0000'>Could not connect to the database!\n\nPlease check your internet connection and proxy settings!</font>");
        QApplication::restoreOverrideCursor();
        return;
    }

    int reportId;
    if (database.checkReportPresent(vulkanGPUs[selectedDeviceIndex], reportId))
    {
        // Check if report can be updated with new information not yet stored in the database
        if (database.checkCanUpdateReport(vulkanGPUs[selectedDeviceIndex], reportId)) {
            setReportState(ReportState::is_updatable);
        }
        else {
            setReportState(ReportState::is_present);
        }
    }
    else
    {
        setReportState(ReportState::not_present);
    }
    QApplication::restoreOverrideCursor();
}

// Upload a report without visual dialogs (e.g. from command line)
int VulkanCapsViewer::uploadReportNonVisual(int deviceIndex, QString submitter, QString comment)
{
    VulkanDeviceInfo device = vulkanGPUs[deviceIndex];

    if (vulkanGPUs[deviceIndex].hasFeaturModifyingTool) {
        qWarning() << "Feature modifying tool detected, upload disabled";
        return -4;
    }

    QString message;
    bool dbstatus = database.checkServerConnection(message);
    if (!dbstatus)
    {
        qWarning() << "Database unreachable";
        return -1;
    }

    int reportId = database.getReportId(device);
    if (reportId > -1)
    {
        qWarning() << "Device already present in database";
        return -2;
    }

    QJsonObject reportJson;
    reportToJson(submitter, comment, reportJson);
    if (database.uploadReport(reportJson, message))
    {
        qInfo() << "Report successfully submitted. Thanks for your contribution!";
        return 0;
    }
    else
    {
        qInfo() << "The report could not be uploaded : \n" << message;
        return -3;
    }
}

void VulkanCapsViewer::setReportState(ReportState state)
{
    reportState = state;
    switch (reportState) {
    case ReportState::is_present:
        ui.toolButtonUpload->setEnabled(false);
        ui.toolButtonOnlineDevice->setEnabled(true);
        ui.toolButtonUpload->setText("Upload");
        ui.labelDevicePresent->setText("<font color='#00cc63'>Device is already present in the database</font>");
        break;
    case ReportState::not_present:
        ui.toolButtonUpload->setEnabled(true);
        ui.toolButtonOnlineDevice->setEnabled(false);
        ui.toolButtonUpload->setText("Upload");
        ui.labelDevicePresent->setText("<font color='#80b3ff'>Device can be uploaded to the database</font>");
        break;
    case ReportState::is_updatable:
        ui.toolButtonUpload->setEnabled(true);
        ui.toolButtonOnlineDevice->setEnabled(true);
        ui.toolButtonUpload->setText("Update");
        ui.labelDevicePresent->setText("<font color='#ffcc00'>Device is already present in the database, but can be updated</font>");
        break;
    case ReportState::update_disabled:
        ui.toolButtonUpload->setEnabled(false);
        ui.toolButtonOnlineDevice->setEnabled(false);
        ui.toolButtonUpload->setText("Disabled");
        ui.labelDevicePresent->setText("<font color='#fc7703'>Feature modifying tool detected, upload disabled</font>");
        break;
    default:
        ui.toolButtonUpload->setEnabled(false);
        ui.toolButtonOnlineDevice->setEnabled(false);
        ui.toolButtonUpload->setText("n.a.");
        ui.labelDevicePresent->setText("<font color='#0000ff'>Could not get report state from database</font>");
    }
}

