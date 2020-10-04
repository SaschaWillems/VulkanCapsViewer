/*
*
* Vulkan hardware capability viewer
*
* Copyright (C) 2016 by Sascha Willems (www.saschawillems.de)
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
#include <qnamespace.h>
#include <assert.h>
#include <settingsDialog.h>
#include "submitDialog.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __linux__
#include <sys/utsname.h>
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
#include <QtX11Extras/QX11Info>
#endif

#ifdef VK_USE_PLATFORM_ANDROID_KHR
#include <QtAndroid>
#include <QAndroidJniEnvironment>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#endif

#ifdef VK_USE_PLATFORM_MACOS_MVK
#import <Cocoa/Cocoa.h>
#endif

using std::to_string;

#define VK_API_VERSION VK_API_VERSION_1_1

const std::string vulkanCapsViewer::version = "2.21";
const std::string vulkanCapsViewer::reportVersion = "2.0";

/// <summary>
///	Returns operating system name
/// </summary>
OSInfo getOperatingSystem()
{
    // QSysInfo works for all supported operating systems
	OSInfo osInfo = {};
    osInfo.name = QSysInfo::productType().toStdString();
    osInfo.architecture = QSysInfo::currentCpuArchitecture().toStdString();
    osInfo.version = QSysInfo::productVersion().toStdString();
	return osInfo;
}

#ifdef __ANDROID__
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

vulkanCapsViewer::vulkanCapsViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    setWindowTitle("Vulkan Hardware Capability Viewer " + QString::fromStdString(version));
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

    vulkanApiVersion = QString::fromStdString(vulkanResources::versionToString(VK_API_VERSION));

    ui.label_header_top->setText(ui.label_header_top->text() + " " + QString::fromStdString(version));
#ifdef ANDROID
    // Load Vulkan libraries on Android manually
    if (!loadVulkanLibrary()) {
        QMessageBox::warning(this, "Error", "Could not initialize Vulkan!\n\nPlease make sure that this device actually supports the Vulkan API!");
        exit(EXIT_FAILURE);
    }
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
        QMessageBox::warning(this, "Error", "Could not initialize Vulkan!\nDevice must support Vulkan API version " + vulkanApiVersion + "!");
        exit(EXIT_FAILURE);
	}

	appSettings.restore();

	// Models and filters
	// Limits
	ui.treeViewDeviceLimits->setModel(&filterProxies.limits);
	filterProxies.limits.setSourceModel(&models.limits);
	connect(ui.filterLineEditLimits, SIGNAL(textChanged(QString)), this, SLOT(slotFilterLimits(QString)));
	// Features
	ui.treeViewDeviceFeatures->setModel(&filterProxies.features);
	filterProxies.features.setSourceModel(&models.features);
	connect(ui.filterLineEditFeatures, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFeatures(QString)));
    // Extensions
    ui.treeViewDeviceExtensions->setModel(&filterProxies.extensions);
    filterProxies.extensions.setSourceModel(&models.extensions);
    connect(ui.filterLineEditExtensions, SIGNAL(textChanged(QString)), this, SLOT(slotFilterExtensions(QString)));
    // Formats
	ui.treeViewFormats->setModel(&filterProxies.formats);
	filterProxies.formats.setSourceModel(&models.formats);
	connect(ui.filterLineEditFormats, SIGNAL(textChanged(QString)), this, SLOT(slotFilterFormats(QString)));

    getGPUs();
}

vulkanCapsViewer::~vulkanCapsViewer()
{
    for (VulkanDeviceInfo &gpu : vulkanGPUs) {
        if (gpu.dev != VK_NULL_HANDLE) {
            vkDestroyDevice(gpu.dev, nullptr);
        }
    }
    if (vkInstance != VK_NULL_HANDLE) {
        vkDestroyInstance(vkInstance, nullptr);
    }
}

/// <summary>
///	Close the application
/// </summary>
void vulkanCapsViewer::slotClose()
{
	close();
}

/// <summary>
///	Display database in default browser
/// </summary>
void vulkanCapsViewer::slotBrowseDatabase() 
{
    QString link = "https://vulkan.gpuinfo.org/";
	QDesktopServices::openUrl(QUrl(link));
}

/// <summary>
///	Display device report in default browser
/// </summary>
void vulkanCapsViewer::slotDisplayOnlineReport()
{
    int reportId = databaseConnection.getReportId(vulkanGPUs[selectedDeviceIndex], this->version);
	stringstream ss;
	ss << databaseConnection.getBaseUrl() << "displayreport.php?id=" << reportId;
	QDesktopServices::openUrl(QUrl(QString::fromStdString(ss.str())));
}

/// <summary>
///	Refresh GPU list
/// </summary>
void vulkanCapsViewer::slotRefresh()
{
	// getGPUs(); TODO : Clean up before refresh
}

/// <summary>
///	Display an about box
/// </summary>
void vulkanCapsViewer::slotAbout()
{
	std::stringstream aboutText;
    aboutText << "<p>Vulkan Hardware Capability Viewer " << version << "<br/><br/>"
        "Copyright (c) 2016-2020 by <a href='https://www.saschawillems.de'>Sascha Willems</a><br/><br/>"
        "Build against Vulkan API " + vulkanApiVersion.toStdString() +
        " header version " + to_string(VK_HEADER_VERSION) + "<br/><br/>"
		"This tool is <b>FREEWARE</b><br/><br/>"
		"For usage and distribution details refer to the readme<br/><br/><br/>"
        "<a href='https://www.gpuinfo.org'>https://www.gpuinfo.org</a><br><br>";
	aboutText << "</p>";
	QMessageBox::about(this, tr("About the Vulkan hardware capability viewer"), QString::fromStdString(aboutText.str()));
}

/// <summary>
///	GPU selection changed
/// </summary>
void vulkanCapsViewer::slotComboBoxGPUIndexChanged(int index)
{
	if (index != selectedDeviceIndex)
	{
		displayDevice(index);
	}
}

/// <summary>
///	Save report to disk (JSON)
/// </summary>
void vulkanCapsViewer::slotSaveReport()
{
    VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Report to disk"), device.properties["deviceName"].toString() + ".json", tr("json (*.json)"));
	if (!fileName.isEmpty())
	{
		exportReportAsJSON(fileName.toStdString(), "", "");
	}
}

/// <summary>
///	Upload report to online database
/// </summary>
void vulkanCapsViewer::slotUploadReport()
{
	VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];

	bool dbstatus = databaseConnection.checkServerConnection();
	if (!dbstatus)
	{
		QMessageBox::warning(this, "Error", "Database unreachable!");
		return;
	}

    int reportId = databaseConnection.getReportId(device, this->version);
	if (reportId > -1)
	{ 
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Device already present", "A report for the selected device is aleady present in the database.\n\nDo you want to open the report in your browser?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes) 
		{
            QString url = QString::fromStdString(databaseConnection.getBaseUrl() + "displayreport.php?id=" + to_string(reportId));
			QDesktopServices::openUrl(QUrl(url));
		}
		return;
	}

	submitDialog dialog(appSettings.submitterName);
	bool ok = (dialog.exec() == QDialog::Accepted);

	if (ok)
	{
		exportReportAsJSON("vulkanreport.json", dialog.getSubmitter(), dialog.getComment());
		std::ostringstream sstream(std::ios::out | std::ios::binary);
		std::ifstream inFile("vulkanreport.json");
		std::string line;
		while (std::getline(inFile, line)) sstream << line << "\r\n";

		string reply = databaseConnection.postReport(sstream.str());
		if (reply == "res_uploaded")
		{
			QMessageBox::information(this, "Report submitted", "Your report has been uploaded to the database!\n\nThanks for your contribution!");
			checkReportDatabaseState();
		}
		else
		{
			QMessageBox::warning(this, "Error", "The report could not be uploaded : \n" + QString::fromStdString(reply));
		}
	}
}

void vulkanCapsViewer::slotSettings()
{
	settingsDialog dialog(appSettings);
	dialog.setModal(true);
	dialog.exec();
	appSettings.restore();
}

void vulkanCapsViewer::slotFilterLimits(QString text)
{
	QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
	filterProxies.limits.setFilterRegExp(regExp);
}

void vulkanCapsViewer::slotFilterFeatures(QString text)
{
	QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
	filterProxies.features.setFilterRegExp(regExp);
}

void vulkanCapsViewer::slotFilterExtensions(QString text)
{
    QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
    filterProxies.extensions.setFilterRegExp(regExp);
}

void vulkanCapsViewer::slotFilterFormats(QString text)
{
	QRegExp regExp(text, Qt::CaseInsensitive, QRegExp::RegExp);
	filterProxies.formats.setFilterRegExp(regExp);
}

void vulkanCapsViewer::slotComboTabChanged(int index)
{
    ui.tabWidgetDevice->setCurrentIndex(index);
}

void vulkanCapsViewer::displayGlobalExtensions()
{
	QTreeWidget *tree = ui.treeWidgetGlobalExtenssions;

    for (auto& ext : instanceInfo.extensions) {
		QTreeWidgetItem *treeItem = new QTreeWidgetItem(tree);
        treeItem->setText(0, QString::fromUtf8(ext.extensionName));
        treeItem->setText(1, QString::fromStdString(vulkanResources::revisionToString(ext.specVersion)));
	}
    for (int i = 0; i < tree->columnCount(); i++) {
		tree->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
	}
}

/// <summary>
///	Initialize vulkan and dome some initial setup
/// </summary>
bool vulkanCapsViewer::initVulkan()
{
	VkResult vkRes;

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "VulkanCapsViewer";
    appInfo.applicationVersion = 1;
    appInfo.pEngineName = "VulkanCapsViewer";
    appInfo.engineVersion = 1;
    appInfo.apiVersion = VK_API_VERSION_1_0;

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
        instanceInfo.layers.push_back(layer);
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
    };

    std::vector<const char*> enabledExtensions = {};

    uint32_t availableExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, nullptr);
    std::vector<VkExtensionProperties> availableExtensions(availableExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, availableExtensions.data());

    if (availableExtensionCount != 0) {
        enabledExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
    };

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
    instanceInfo.extensions.clear();
    do {
        uint32_t extCount;
        vkRes = vkEnumerateInstanceExtensionProperties(NULL, &extCount, NULL);
        if (vkRes != VK_SUCCESS) {
            break;
        }
        std::vector<VkExtensionProperties> extensions(extCount);
        vkRes = vkEnumerateInstanceExtensionProperties(NULL, &extCount, &extensions.front());
        instanceInfo.extensions.insert(instanceInfo.extensions.end(), extensions.begin(), extensions.end());
    } while (vkRes == VK_INCOMPLETE);

    // Check support for new property and feature queries
    globalInfo.features.deviceProperties2 = false;
    for (auto& ext : instanceInfo.extensions) {
        if (strcmp(ext.extensionName, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
            globalInfo.features.deviceProperties2 = true;
            enabledExtensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            break;
        }
    }

    instanceCreateInfo.ppEnabledExtensionNames = enabledExtensions.data();
    instanceCreateInfo.enabledExtensionCount = (uint32_t)enabledExtensions.size();

	// Create vulkan Instance
    vkRes = vkCreateInstance(&instanceCreateInfo, nullptr, &vkInstance);
	if (vkRes != VK_SUCCESS) 
	{
		QString error;
		if (vkRes == VK_ERROR_INCOMPATIBLE_DRIVER)
		{
			error = "No compatible Vulkan driver found!\nThis version requires a Vulkan driver that is compatible with API Level " + QString::fromStdString(vulkanResources::versionToString(VK_API_VERSION));
		}
		else
		{
			error = "Could not create Vulkan instance!\nError: " + QString::fromStdString(vulkanResources::resultString(vkRes));
		}
		QMessageBox::warning(this, tr("Error"), error);
		return false;
	}

#ifdef ANDROID
    loadVulkanFunctions(vkInstance);
#endif

    // Function pointers for new features/properties
    if (globalInfo.features.deviceProperties2) {
        pfnGetPhysicalDeviceFeatures2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceFeatures2KHR>(vkGetInstanceProcAddr(vkInstance, "vkGetPhysicalDeviceFeatures2KHR"));
        if (!pfnGetPhysicalDeviceFeatures2KHR) {
            globalInfo.features.deviceProperties2 = false;
            QMessageBox::warning(this, tr("Error"), "Could not get function pointer for vkGetPhysicalDeviceFeatures2KHR (even though extension is enabled!)\nNew features and properties won't be displayed!");
        }
        pfnGetPhysicalDeviceProperties2KHR = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2KHR>(vkGetInstanceProcAddr(vkInstance, "vkGetPhysicalDeviceProperties2KHR"));
        if (!pfnGetPhysicalDeviceProperties2KHR) {
            globalInfo.features.deviceProperties2 = false;
            QMessageBox::warning(this, tr("Error"), "Could not get function pointer for vkGetPhysicalDeviceProperties2KHR (even though extension is enabled!)\nNew features and properties won't be displayed!");
        }
    }

    // Create a surface
    for (auto surface_extension : surfaceExtensionsAvailable) {
        VkResult surfaceResult = VK_ERROR_INITIALIZATION_FAILED;
        surface = VK_NULL_HANDLE;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
        if (surface_extension == VK_KHR_WIN32_SURFACE_EXTENSION_NAME) {
            VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
            surfaceCreateInfo.hinstance = GetModuleHandle(nullptr);
            surfaceCreateInfo.hwnd = reinterpret_cast<HWND>(this->winId());
            surfaceResult = vkCreateWin32SurfaceKHR(vkInstance, &surfaceCreateInfo, nullptr, &surface);
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
                surfaceResult = vkCreateAndroidSurfaceKHR(vkInstance, &surfaceCreateInfo, NULL, &surface);
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
            surfaceResult = vkCreateWaylandSurfaceKHR(vkInstance, &surfaceCreateInfo, nullptr, &surface);
        }
#endif

#if defined(VK_USE_PLATFORM_XCB_KHR)
        if (surface_extension == VK_KHR_XCB_SURFACE_EXTENSION_NAME) {
            VkXcbSurfaceCreateInfoKHR surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
            surfaceCreateInfo.connection = QX11Info::connection();
            surfaceCreateInfo.window = static_cast<xcb_window_t>(this->winId());
            surfaceResult = vkCreateXcbSurfaceKHR(vkInstance, &surfaceCreateInfo, nullptr, &surface);
        }
#endif

#if defined(VK_USE_PLATFORM_MACOS_MVK)
        if (surface_extension == VK_MVK_MACOS_SURFACE_EXTENSION_NAME) {
            VkMacOSSurfaceCreateInfoMVK surfaceCreateInfo = {};
            surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
            surfaceCreateInfo.pView = reinterpret_cast<NSView*>(this->winId());
            surfaceResult = vkCreateMacOSSurfaceMVK(vkInstance, &surfaceCreateInfo, nullptr, &surface);
        }
#endif

        if (surfaceResult == VK_SUCCESS) {
            surfaceExtension = surface_extension;
            break;
        }
        else
            surface = VK_NULL_HANDLE;
    }

    displayGlobalLayers(ui.treeWidgetGlobalLayers);
    displayGlobalExtensions();

	return true;
}

/// <summary>
///	Get details for the specificed vulkan GPU
/// </summary>
void vulkanCapsViewer::getGPUinfo(VulkanDeviceInfo *GPU, uint32_t id, VkPhysicalDevice device)
{
	VkResult vkRes;

	GPU->id = id;
	GPU->device = device;
	GPU->readLayers();
	GPU->readExtensions();
    GPU->readQueueFamilies();
    GPU->readPhysicalProperties();
    GPU->readPhysicalFeatures();
    GPU->readPhysicalLimits();
    GPU->readPhysicalMemoryProperties();
    GPU->readSurfaceInfo(surface, surfaceExtension);
    GPU->readPlatformDetails();
	// Request all available queues
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    for (uint32_t i = 0; i < GPU->queueFamilies.size(); ++i)
	{
        float queuePriorities[1] = { 0.0f };
		VkDeviceQueueCreateInfo queueCreateInfo = {};
		queueCreateInfo.queueFamilyIndex = i;
		queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = queuePriorities;
        queueCreateInfos.push_back(queueCreateInfo);
	}

	// Enable all available extensions
    /*
	std::vector<const char*> enabledExtensions;
	for (auto& ext : GPU->extensions)
	{
		enabledExtensions.push_back(ext.extensionName);
	}
    */

	// Init device

	VkDeviceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	info.pNext = NULL;
	info.pQueueCreateInfos = queueCreateInfos.data();
    info.queueCreateInfoCount = (uint32_t)queueCreateInfos.size();
	info.pEnabledFeatures = NULL;
	info.ppEnabledLayerNames = NULL;
    info.enabledLayerCount = 0;
//    info.enabledExtensionCount = enabledExtensions.size();
//    info.ppEnabledExtensionNames = enabledExtensions.data();

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
}

/// <summary>
///	Get list of all available GPUs that support Vulkan
/// </summary>
void vulkanCapsViewer::getGPUs()
{
	VkResult vkRes;
	uint32_t numGPUs;

	// Enumerate devices
	vkRes = vkEnumeratePhysicalDevices(vkInstance, &numGPUs, NULL);
	if (vkRes != VK_SUCCESS) 
	{
        QMessageBox::warning(this, tr("Error"), "Could not enumerate device count!");
        return;
	}
	std::vector<VkPhysicalDevice> vulkanDevices;
	vulkanDevices.resize(numGPUs);

	vkRes = vkEnumeratePhysicalDevices(vkInstance, &numGPUs, &vulkanDevices.front());
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
}

QTreeWidgetItem *addTreeItem(QTreeWidgetItem *parent, const std::string& key, const std::string& value)
{
	QTreeWidgetItem *newItem = new QTreeWidgetItem(parent);
	newItem->setText(0, QString::fromStdString(key));
	newItem->setText(1, QString::fromStdString(value));
	parent->addChild(newItem);
	return newItem;
}

enum ItemFormat {DEFAULT_FORMAT, HEX_FORMAT};
QTreeWidgetItem *addTreeItem(QTreeWidgetItem *parent, QVariantMap::const_iterator iter, const ItemFormat format = DEFAULT_FORMAT)
{
    // Map some key names to different display names
    QMap<QString, QString> replaceList;
    replaceList["apiVersionText"] = "apiVersion";
    replaceList["deviceTypeText"] = "deviceType";
    replaceList["driverVersionText"] = "driverVersion";

    QString keyName = iter.key();
    if (replaceList.contains(keyName)) {
        keyName = replaceList[keyName];
    }

    QTreeWidgetItem *newItem = new QTreeWidgetItem(parent);
    newItem->setText(0, keyName);
    if (format == HEX_FORMAT){
        newItem->setText(1, vulkanResources::toHexQString(iter.value().toULongLong()));
    } else {
        assert(format == DEFAULT_FORMAT);
        newItem->setText(1, iter.value().toString());
    }
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

/// <summary>
///	Display information on given device
/// </summary>
void vulkanCapsViewer::displayDevice(int index)
{
	assert(index < vulkanGPUs.size());

	VulkanDeviceInfo device = vulkanGPUs[index];
	selectedDeviceIndex = index;
	
	displayDeviceProperties(&device);
    displayDeviceMemoryProperites(&device);
	displayDeviceLimits(&device);
	displayDeviceFeatures(&device);
	displayDeviceLayers(&device);
	displayDeviceFormats(&device);
    displayDeviceExtensions(&device);
	displayDeviceQueues(&device);
    displayDeviceSurfaceInfo(device);

	checkReportDatabaseState();
}

void vulkanCapsViewer::displayDeviceProperties(VulkanDeviceInfo *device)
{
	QTreeWidget *treeWidget = ui.treeWidgetDeviceProperties;
    treeWidget->clear();
	QTreeWidgetItem *treeItem = treeWidget->invisibleRootItem();


    {
        // Some keys are doubled for raw and readable data for vkjson compatiblity, filter them out and display readable versions only
        const QSet<QString> skipList = {"apiVersion", "deviceType", "driverVersion", "headerversion"};

        // Some values look better as hex int
        const QSet<QString> hexList = {"vendorID", "deviceID"};

        // Basic properties
        for(QVariantMap::const_iterator iter = device->properties.begin(); iter != device->properties.end(); ++iter) {
            const QString& propName = iter.key();
            if (skipList.contains(propName)) continue;

            const ItemFormat itemFormat = hexList.contains(propName) ? HEX_FORMAT : DEFAULT_FORMAT;
            addTreeItem(treeItem, iter, itemFormat);
        }
    }

    // Sparse properties
    QTreeWidgetItem *parentItem = new QTreeWidgetItem(treeItem);
    parentItem->setText(0, "sparse properties");
    treeItem->addChild(parentItem);
    for(QVariantMap::const_iterator iter = device->sparseProperties.begin(); iter != device->sparseProperties.end(); ++iter) {
        addTreeItemVkBool32(parentItem, iter.key().toStdString(), iter.value().toBool());
    }

    // Subgroup operations properties
    if (device->hasSubgroupProperties) {
        QTreeWidgetItem *parentItem = new QTreeWidgetItem(treeItem);
        parentItem->setText(0, "subgroup properties");
        for(QVariantMap::const_iterator iter = device->subgroupProperties.begin(); iter != device->subgroupProperties.end(); ++iter) {
            QString keyName = iter.key();
            if (keyName == "quadOperationsInAllStages") {
                addTreeItemVkBool32(parentItem, iter.key().toStdString(), iter.value().toBool());
            }
            if (keyName == "subgroupSize") {
                addTreeItem(parentItem, iter);
            }
            if (keyName == "supportedOperations") {
                const VkSubgroupFeatureFlags flags = iter.value().toUInt();
                addTreeItemFlags(parentItem, iter.key().toStdString(), flags, vulkanResources::subgroupFeatureBitString);
            }
            if (keyName == "supportedStages") {
                VkShaderStageFlags flags = iter.value().toUInt();
                QTreeWidgetItem *stagesItem = addTreeItemFlags(parentItem, iter.key().toStdString(), flags, vulkanResources::shaderStagesBitString);
                addTreeItemFlag(stagesItem,
                                QString::fromStdString(vulkanResources::shaderStagesBitString(VK_SHADER_STAGE_ALL_GRAPHICS)),
                               (flags & VK_SHADER_STAGE_ALL_GRAPHICS) == VK_SHADER_STAGE_ALL_GRAPHICS);
                addTreeItemFlag(stagesItem,
                                QString::fromStdString(vulkanResources::shaderStagesBitString(VK_SHADER_STAGE_ALL)),
                                (flags & VK_SHADER_STAGE_ALL) == VK_SHADER_STAGE_ALL);
            }
        }
    }

    // Pipeline cache UUID
    std::ostringstream uuidSs;
    uuidSs << std::hex << std::noshowbase << std::nouppercase;
    assert(VK_UUID_SIZE == 16);
    for (uint32_t i = 0; i < VK_UUID_SIZE; ++i){
        uuidSs << std::right << std::setw(2) << std::setfill('0') << static_cast<unsigned short>(device->props.pipelineCacheUUID[i]);
        if (i == 3 || i == 5 || i == 7 || i == 9) uuidSs << '-';
    }
    addTreeItem(treeItem, "pipelineCacheUUID", uuidSs.str());

    // Operating system
    stringstream ss;
    ss << device->os.name << " " << device->os.version << " (" << device->os.architecture << ")";
    addTreeItem(treeItem, "operatingsystem", ss.str());

    // Platform specific info
    if (device->platformdetails.size() > 0) {
        QTreeWidgetItem *platformItem = new QTreeWidgetItem(treeItem);
        platformItem->setText(0, "Platform details");
        treeItem->addChild(platformItem);
        for (auto& detail : device->platformdetails) {
            addTreeItem(platformItem, detail.first, detail.second);
        }
    }

    ui.treeWidgetDeviceProperties->expandAll();

    for (int i = 0; i < treeWidget->columnCount(); i++)
		treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void vulkanCapsViewer::displayDeviceMemoryProperites(VulkanDeviceInfo *device)
{
    using namespace vulkanResources;

    QTreeWidget *treeWidget = ui.treeWidgetDeviceMemory;
    treeWidget->clear();
    QTreeWidgetItem *memTypeItem = addTreeItem(treeWidget->invisibleRootItem(), "Memory types", arraySizeToString(device->memoryProperties.memoryTypeCount));
    for (uint32_t i = 0; i < device->memoryProperties.memoryTypeCount; ++i)
    {
        QTreeWidgetItem *memTypeInfoItem = addTreeItem(memTypeItem, arrayIndexToString(i), "");
        memTypeInfoItem->setExpanded(true);

        const VkMemoryType memType = device->memoryProperties.memoryTypes[i];
        addTreeItem(memTypeInfoItem, "Heap index", arrayIndexToString(memType.heapIndex));
        addTreeItemFlags(memTypeInfoItem, "Property flags", memType.propertyFlags, memoryPropBitString)
            ->setExpanded(true);
    }
    memTypeItem->setExpanded(true);
    QTreeWidgetItem *heapTypeItem = addTreeItem(treeWidget->invisibleRootItem(), "Memory heaps", arraySizeToString(device->memoryProperties.memoryHeapCount));
    for (uint32_t i = 0; i < device->memoryProperties.memoryHeapCount; i++)
    {
        QTreeWidgetItem *memHeapInfoItem = addTreeItem(heapTypeItem, arrayIndexToString(i), "");

        const VkMemoryHeap heapType = device->memoryProperties.memoryHeaps[i];
        addTreeItem(memHeapInfoItem, "Device size", to_string(heapType.size));
        addTreeItemFlags(memHeapInfoItem, "Flags", heapType.flags, memoryHeapBitString)
            ->setExpanded(true);

        memHeapInfoItem->setExpanded(true);
    }
    heapTypeItem->setExpanded(true);
    for (int i = 0; i < treeWidget->columnCount(); i++)
        treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void vulkanCapsViewer::displayDeviceLimits(VulkanDeviceInfo *device)
{
    const QSet<QString> sampleFlagsLims = {
        "framebufferColorSampleCounts", "framebufferDepthSampleCounts", "framebufferStencilSampleCounts", "framebufferNoAttachmentsSampleCounts",
        "sampledImageColorSampleCounts", "sampledImageIntegerSampleCounts", "sampledImageDepthSampleCounts", "sampledImageStencilSampleCounts",
        "storageImageSampleCounts"
    };

    const QSet<QString> boolLims = {"timestampComputeAndGraphics", "strictLines", "standardSampleLocations"};

    models.limits.clear();
    QStandardItem *rootItem = models.limits.invisibleRootItem();
    for(QVariantMap::const_iterator iter = device->limits.begin(); iter != device->limits.end(); ++iter) {
        QList<QStandardItem *> rowItems;
        rowItems << new QStandardItem(iter.key());
        if (iter.value().canConvert(QVariant::List)) {
            QList<QVariant> list = iter.value().toList();
            QString listStr = "[";
            for (int i = 0; i < list.size(); i++) {
                listStr += list[i].toString();
                if (i < list.size() - 1)
                    listStr += ", ";
            }
            listStr += "]";
            rowItems << new QStandardItem(listStr);
        } else if (sampleFlagsLims.contains(iter.key())){
            const auto samples = static_cast<VkSampleCountFlags>(iter.value().toUInt());
            rowItems << new QStandardItem(vulkanResources::toQStringList(samples));
        } else if (boolLims.contains(iter.key())){
            rowItems << new QStandardItem(iter.value().toBool() ? "true" : "false");
            rowItems[1]->setForeground(iter.value().toBool() ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
        } else {
            rowItems << new QStandardItem(iter.value().toString());
        }
        rootItem->appendRow(rowItems);
    }
	ui.treeViewDeviceLimits->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void vulkanCapsViewer::displayDeviceFeatures(VulkanDeviceInfo *device)
{
    models.features.clear();
    QStandardItem *rootItem = models.features.invisibleRootItem();

    // Basic features
    for(QVariantMap::const_iterator iter = device->features.begin(); iter != device->features.end(); ++iter) {
        QList<QStandardItem *> rowItems;
        rowItems << new QStandardItem(iter.key());
        rowItems << new QStandardItem(iter.value().toBool() ? "true" : "false");
        rowItems[1]->setForeground(iter.value().toBool() ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
		rootItem->appendRow(rowItems);
	}

    ui.treeViewDeviceFeatures->expandAll();
    ui.treeViewDeviceFeatures->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui.treeViewDeviceFeatures->header()->setStretchLastSection(false);
}

void vulkanCapsViewer::displayGlobalLayers(QTreeWidget *tree)
{
    using namespace vulkanResources;

    tree->clear();
    for (auto& layer : instanceInfo.layers) {
		QTreeWidgetItem *treeItem = new QTreeWidgetItem(tree);
        treeItem->setText(0, QString::fromUtf8(layer.properties.layerName));
        treeItem->setText(1, QString::fromStdString(versionToString(layer.properties.specVersion)));
        treeItem->setText(2, QString::fromStdString(revisionToString(layer.properties.implementationVersion)));
        treeItem->setText(3, QString::fromStdString(to_string(layer.extensions.size())));
        treeItem->setText(4, layer.properties.description);
        for (auto& layerExt : layer.extensions) {
            addTreeItem(treeItem, layerExt.extensionName, revisionToString(layerExt.specVersion));
		}
	}
	for (int i = 0; i < tree->columnCount(); i++)
		tree->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
}

void vulkanCapsViewer::displayDeviceLayers(VulkanDeviceInfo *device)
{
    using namespace vulkanResources;

	QTreeWidget *treeWidget = ui.treeWidgetDeviceLayers;
    treeWidget->clear();
    ui.tabWidgetDevice->setTabText(5, "Layers (" + QString::number(device->getLayers().size()) + ")");
	for (auto& layer : device->getLayers())
	{
		QTreeWidgetItem *treeItem = new QTreeWidgetItem(treeWidget);
		treeItem->setText(0, QString::fromUtf8(layer.properties.layerName));
		treeItem->setText(1, QString::fromStdString(versionToString(layer.properties.specVersion)));
		treeItem->setText(2, QString::fromStdString(revisionToString(layer.properties.implementationVersion)));
        treeItem->setText(3, QString::fromStdString(to_string(layer.extensions.size())));
		treeItem->setText(4, layer.properties.description);
		for (auto& layerExt : layer.extensions)
		{
			addTreeItem(treeItem, layerExt.extensionName, revisionToString(layerExt.specVersion));
		}
	}
	for (int i = 0; i < treeWidget->columnCount(); i++)
		treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
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

void vulkanCapsViewer::displayDeviceFormats(VulkanDeviceInfo *device)
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
					ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_BLIT_SRC_BIT);
					ADD_FLAG(VK_FORMAT_FEATURE_BLIT_DST_BIT);
                    // 1.1
                    ADD_FLAG(VK_FORMAT_FEATURE_TRANSFER_SRC_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_TRANSFER_DST_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_DISJOINT_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT);

                    // EXT
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT);
                    ADD_FLAG(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG);
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

QString arrayToStr(QVariant value) {
    QList<QVariant> list = value.toList();
    QString listStr = "[";
    for (int i = 0; i < list.size(); i++) {
        listStr += list[i].toString();
        if (i < list.size() - 1)
            listStr += ", ";
    }
    listStr += "]";
    return listStr;
}

/*
    Fill extension tree model incudling extension features and properties
*/
void vulkanCapsViewer::displayDeviceExtensions(VulkanDeviceInfo *device)
{
    ui.tabWidgetDevice->setTabText(3, "Extensions (" + QString::number(device->extensions.size()) + ")");

    models.extensions.clear();
    QStandardItem *rootItem = models.extensions.invisibleRootItem();

    for (auto& extension : device->extensions) {
        QList<QStandardItem *> extItem;
        extItem << new QStandardItem(QString::fromStdString(extension.extensionName));
        extItem << new QStandardItem(QString::fromStdString(vulkanResources::revisionToString(extension.specVersion)));

        // Features
        bool hasFeatures = false;
        QList<QStandardItem *> featureRootItem;
        for (auto& feature : device->features2) {
            featureRootItem << new QStandardItem("Features");
            featureRootItem << new QStandardItem(" ");
            if (strcmp(feature.extension, extension.extensionName) == 0) {
                hasFeatures = true;
                QList<QStandardItem *> featureItem;
                featureItem << new QStandardItem(QString::fromStdString(feature.name));
                featureItem << new QStandardItem((feature.supported) ? "true" : "false");
                featureItem[1]->setForeground((feature.supported) ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
                featureRootItem.first()->appendRow(featureItem);
            }
        }
        if (hasFeatures) {
            extItem.first()->appendRow(featureRootItem);
        }

        // Properties
        bool hasProperties = false;
        QList<QStandardItem *> propertiesRootItem;
        for (auto& property : device->properties2) {
            propertiesRootItem << new QStandardItem("Properties");
            propertiesRootItem << new QStandardItem(" ");
            if (strcmp(property.extension, extension.extensionName) == 0) {
                hasProperties = true;
                QList<QStandardItem *> propertyItem;
                propertyItem << new QStandardItem(QString::fromStdString(property.name));

                if (property.value.canConvert(QVariant::List)) {
                    propertyItem << new QStandardItem(arrayToStr(property.value));
                } else {
                    switch (property.value.type()) {
                        case QMetaType::Bool: {
                            bool boolVal = property.value.toBool();
                            propertyItem << new QStandardItem(boolVal ? "true" : "false");
                            propertyItem[1]->setForeground(boolVal ? QColor::fromRgb(0, 128, 0) : QColor::fromRgb(255, 0, 0));
                            break;
                        }
                        default:
                            propertyItem << new QStandardItem(property.value.toString());
                    }
                }
                propertiesRootItem.first()->appendRow(propertyItem);
            }
        }
        if (hasProperties) {
            extItem.first()->appendRow(propertiesRootItem);
        }

        rootItem->appendRow(extItem);
    }

    ui.treeViewDeviceExtensions->expandAll();
    ui.treeViewDeviceExtensions->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void vulkanCapsViewer::displayDeviceQueues(VulkanDeviceInfo *device)
{
    ui.tabWidgetDevice->setTabText(6, "Queues Families (" + QString::number(device->queueFamilies.size()) + ")");
    QTreeWidget* treeWidget = ui.treeWidgetQueues;
    treeWidget->clear();
    for (auto& queueFamily : device->queueFamilies)
    {
        QTreeWidgetItem *queueItem = new QTreeWidgetItem(treeWidget);
        queueItem->setText(0, QString::fromStdString("Queue family"));
        // Support flags
        addTreeItemFlags(queueItem, "Flags", queueFamily.properties.queueFlags, vulkanResources::queueBitString)
            ->setExpanded(true);
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

void vulkanCapsViewer::displayDeviceSurfaceInfo(VulkanDeviceInfo &device)
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
    addTreeItem(treeWidget->invisibleRootItem(), "Surface extension", surfaceExtension);

    // Surface capabilities
    QTreeWidgetItem *surfaceCapsItem = addTreeItem(treeWidget->invisibleRootItem(), "Surface Capabilities", "");

    VkSurfaceCapabilitiesKHR surfaceCaps = device.surfaceInfo.capabilities;

    addTreeItem(surfaceCapsItem, "minImageCount", to_string(surfaceCaps.minImageCount));
    addTreeItem(surfaceCapsItem, "maxImageCount", to_string(surfaceCaps.maxImageCount));

    addTreeItem(surfaceCapsItem, "maxImageArrayLayers", to_string(surfaceCaps.maxImageArrayLayers));

    addTreeItem(surfaceCapsItem, "minImageExtent", to_string(surfaceCaps.minImageExtent.width) + " x " + to_string(surfaceCaps.minImageExtent.height));
    addTreeItem(surfaceCapsItem, "maxImageExtent", to_string(surfaceCaps.maxImageExtent.width) + " x " + to_string(surfaceCaps.maxImageExtent.height));

    // Usage flags
    addTreeItemFlags(surfaceCapsItem, "Supported usage flags", surfaceCaps.supportedUsageFlags, imageUsageBitString)
        ->setExpanded(true);

    // Transform flags
    addTreeItemFlags(surfaceCapsItem, "Supported transforms", surfaceCaps.supportedTransforms, surfaceTransformBitString)
        ->setExpanded(true);

    // Composite alpha
    addTreeItemFlags(surfaceCapsItem, "Composite alpha flags", surfaceCaps.supportedCompositeAlpha, compositeAlphaBitString)
        ->setExpanded(true);

    // Surface modes
    QTreeWidgetItem *modesItem = addTreeItem(treeWidget->invisibleRootItem(), "Present modes", arraySizeToString(device.surfaceInfo.presentModes.size()));
    if (!device.surfaceInfo.presentModes.empty())
    {
        for (auto presentMode : device.surfaceInfo.presentModes)
        {
            addTreeItem(modesItem, presentModeKHRString(presentMode), "");
        }
    }
    else
    {
        addTreeItem(modesItem, "none", "");
    }
    modesItem->setExpanded(true);

    // Surface formats
    QTreeWidgetItem *formatsItem = addTreeItem(treeWidget->invisibleRootItem(), "Surface formats", arraySizeToString(device.surfaceInfo.formats.size()));
    if (!device.surfaceInfo.formats.empty())
    {
        uint32_t index = 0;
        for (auto surfaceFormat : device.surfaceInfo.formats)
        {
            QTreeWidgetItem *formatItem = addTreeItem(formatsItem, arrayIndexToString(index), "");
            addTreeItem(formatItem, "Format", (formatString(surfaceFormat.format)));
            addTreeItem(formatItem, "Color space", (colorSpaceKHRString(surfaceFormat.colorSpace)));
            formatItem->setExpanded(true);
            index++;
        }
    }
    else
    {
        addTreeItem(formatsItem, "none", "");
    }
    formatsItem->setExpanded(true);

    surfaceCapsItem->setExpanded(true);

    // todo: move to function
    for (int i = 0; i < treeWidget->columnCount(); i++)
    {
        treeWidget->header()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

}

void vulkanCapsViewer::exportReportAsJSON(std::string fileName, std::string submitter, std::string comment)
{
	VulkanDeviceInfo device = vulkanGPUs[selectedDeviceIndex];
    QJsonObject report = device.toJson(fileName, submitter, comment);

    // Add instance information
    QJsonObject jsonInstance;
    // Extensions
    QJsonArray jsonExtensions;
    for (auto& ext : instanceInfo.extensions) {
        QJsonObject jsonExt;
        jsonExt["extensionName"] = ext.extensionName;
        jsonExt["specVersion"] = int(ext.specVersion);
        jsonExtensions.append(jsonExt);
    }
    jsonInstance["extensions"] = jsonExtensions;
    // Layers
    QJsonArray jsonLayers;
    for (auto& layer : instanceInfo.layers) {
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

    report["instance"] = jsonInstance;

    QJsonDocument doc(report);
    QFile jsonFile(QString::fromStdString(fileName));
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson(QJsonDocument::Indented));
}

/// <summary>
///	Display database state for the currently selected device
/// </summary>
void vulkanCapsViewer::checkReportDatabaseState()
{
	ui.labelDevicePresent->setText("<font color='#000000'>Connecting to database...</font>");
	ui.labelDevicePresent->setVisible(true);
    ui.toolButtonOnlineDevice->setEnabled(false);

	QApplication::setOverrideCursor(Qt::WaitCursor);
	if (!databaseConnection.checkServerConnection())
	{
		ui.labelDevicePresent->setText("<font color='#FF0000'>Could not connect to the database!\n\nPlease check your internet connection and proxy settings!</font>");
		ui.labelDevicePresent->setVisible(true);
		QApplication::restoreOverrideCursor();
		return;
	}

    if (databaseConnection.checkReportPresent(vulkanGPUs[selectedDeviceIndex], this->version))
	{
        ui.toolButtonOnlineDevice->setEnabled(true);
        ui.labelDevicePresent->setText("<font color='#00813e'>Device report already present in database</font>");
		// Report present, check if it can be updated
		// TODO : Update mechanics!
		/*
		int reportId = glhttp.getReportId(core.description);
		if (canUpdateReport(reportId)) {
			ui.labelDevicePresent->setText("<font color='#0000FF'>Device already present in database, but can be updated with missing values!</font>");
		}
		*/
	}
	else
	{
        ui.labelDevicePresent->setText("<font color='#bc0003'>Device report not present in database yet</font>");
	}
	ui.labelDevicePresent->setVisible(true);
	QApplication::restoreOverrideCursor();
}

// Upload a report without visual dialogs (e.g. from command line)
int vulkanCapsViewer::uploadReportNonVisual(int deviceIndex, QString submitter, QString comment)
{
    VulkanDeviceInfo device = vulkanGPUs[deviceIndex];

    bool dbstatus = databaseConnection.checkServerConnection();
    if (!dbstatus)
    {
        qWarning() << "Database unreachable";
        return -1;
    }

    int reportId = databaseConnection.getReportId(device, this->version);
    if (reportId > -1)
    {
        qWarning() << "Device already present in database";
        return -2;
    }

    exportReportAsJSON("vulkanreport.json", submitter.toStdString(), comment.toStdString());
    std::ostringstream sstream(std::ios::out | std::ios::binary);
    std::ifstream inFile("vulkanreport.json");
    std::string line;
    while (std::getline(inFile, line)) sstream << line << "\r\n";

    string reply = databaseConnection.postReport(sstream.str());
    if (reply == "res_uploaded")
    {
        qInfo() << "Report successfully submitted. Thanks for your contribution!";
        return 0;
    }
    else
    {
        qInfo() << "The report could not be uploaded : \n" + QString::fromStdString(reply);
        return -3;
    }

    return 0;
}
