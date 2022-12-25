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

#ifndef VULKANCAPSVIEWER_H
#define VULKANCAPSVIEWER_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QKeyEvent>
#include <QWindow>
#include <treeproxyfilter.h>
#include "ui_vulkancapsviewer.h"
#include <settings.h>
#include <vector>

#include "vulkanDeviceInfo.h"
#include "vulkanLayerInfo.hpp"
#include "vulkansurfaceinfo.hpp"
#include "vulkandatabase.h"
#include "vulkanandroid.h"
#include "VulkanContext.h"

#include "vulkan/vulkan.h"

#if defined(VK_USE_PLATFORM_IOS_MVK)
    // This sets the working folder on iOS to the designated shared
    // area. Safe to read/write from here.
    extern "C" void setWorkingFolderForiOS(void);
#endif

#if defined(VK_USE_PLATFORM_IOS_MVK) || defined(VK_USE_PLATFORM_MACOS_MVK)
// An unseen window for macOS and iOS that has a Metal surface
// attached.
class QVukanSurrogate: public QWindow
{
public:
    QVukanSurrogate() {
        QWindow((QWindow*)nullptr);
        setSurfaceType(QSurface::MetalSurface);
    }
};
#endif

enum ReportState { unknown, not_present, is_present, is_updatable, update_disabled };

class VulkanCapsViewer : public QMainWindow
{
    Q_OBJECT

public:
    static const QString version;
    static const QString reportVersion;
    ReportState reportState = ReportState::unknown;
    std::vector<VulkanDeviceInfo> vulkanGPUs;
    std::vector<VulkanLayerInfo> instanceLayers;
    std::vector<VkExtensionProperties> instanceExtensions;
    bool deviceProperties2Available = false;
    VulkanDatabase database;
    void checkReportDatabaseState();
    VulkanCapsViewer(QWidget *parent = 0);
    ~VulkanCapsViewer();
    void reportToJson(QString submitter, QString comment, QJsonObject& jsonObject);
    bool saveReport(QString fileName, QString submitter, QString comment);
    int uploadReportNonVisual(int deviceIndex, QString submitter, QString comment);
private:
    uint32_t instanceApiVersion;
    int selectedDeviceIndex = 0;
#if defined(VK_USE_PLATFORM_IOS_MVK) || defined(VK_USE_PLATFORM_MACOS_MVK)
    QVukanSurrogate *pMetalSurrogate = nullptr;
#endif    
    Ui::vulkanCapsViewerClass ui;
    struct {
        TreeProxyFilter propertiesCore10;
        TreeProxyFilter propertiesCore11;
        TreeProxyFilter propertiesCore12;
        TreeProxyFilter propertiesCore13;
        TreeProxyFilter propertiesExtensions;
        TreeProxyFilter featuresCore10;
        TreeProxyFilter featuresCore11;
        TreeProxyFilter featuresCore12;
        TreeProxyFilter featuresCore13;
        TreeProxyFilter featuresExtensions;
        TreeProxyFilter formats;
        TreeProxyFilter extensions;
        TreeProxyFilter profiles;
    } filterProxies;
    struct {
        QStandardItemModel propertiesCore10;
        QStandardItemModel propertiesCore11;
        QStandardItemModel propertiesCore12;
        QStandardItemModel propertiesCore13;
        QStandardItemModel propertiesExtensions;
        QStandardItemModel featuresCore10;
        QStandardItemModel featuresCore11;
        QStandardItemModel featuresCore12;
        QStandardItemModel featuresCore13;
        QStandardItemModel featuresExtensions;
        QStandardItemModel formats;
        QStandardItemModel extensions;
        QStandardItemModel profiles;
    } models;
    QFont boldFont;
#ifdef ANDROID
    ANativeWindow* nativeWindow = nullptr;
#endif
    bool initVulkan();
    void getGPUinfo(VulkanDeviceInfo *GPU, uint32_t id, VkPhysicalDevice device);
    void getGPUs();
    void connectFilterAndModel(QStandardItemModel& model, TreeProxyFilter& filter);
    void displayDevice(int index);
    void displayDeviceProperties(VulkanDeviceInfo *device);
    void displayDeviceMemoryProperties(VulkanDeviceInfo *device);
    void displayDeviceFeatures(VulkanDeviceInfo *device);
    void displayDeviceFormats(VulkanDeviceInfo *device);
    void displayDeviceExtensions(VulkanDeviceInfo *device);
    void displayDeviceQueues(VulkanDeviceInfo *device);
    void displayDeviceSurfaceInfo(VulkanDeviceInfo &device);
    void displayDeviceProfiles(VulkanDeviceInfo* device);
    void displayOSInfo(VulkanDeviceInfo& device);
    void displayInstanceLayers();
    void displayInstanceExtensions();
    void setReportState(ReportState state);
private Q_SLOTS:
    void slotClose();
    void slotBrowseDatabase();
    void slotDisplayOnlineReport();
    void slotAbout();
    void slotComboBoxGPUIndexChanged(int index);
    void slotSaveReport();
    void slotUploadReport();
    void slotSettings();
    void slotFilterPropertiesCore10(QString text);
    void slotFilterPropertiesCore11(QString text);
    void slotFilterPropertiesCore12(QString text);
    void slotFilterPropertiesCore13(QString text);
    void slotFilterPropertiesExtensions(QString text);
    void slotFilterFeatures(QString text);
    void slotFilterFeaturesCore11(QString text);
    void slotFilterFeaturesCore12(QString text);
    void slotFilterFeaturesCore13(QString text);
    void slotFilterFeaturesExtensions(QString text);
    void slotFilterExtensions(QString text);
    void slotFilterFormats(QString text);
    void slotFilterProfiles(QString text);
    void slotComboTabChanged(int index);
};

#endif // VULKANCAPSVIEWER_H
