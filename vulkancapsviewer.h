#ifndef VULKANCAPSVIEWER_H
#define VULKANCAPSVIEWER_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QKeyEvent>
#include <treeproxyfilter.h>
#include "ui_vulkancapsviewer.h"
#include <settings.h>
#include <vector>

#include "vulkanDeviceInfo.hpp"
#include "vulkanLayerInfo.hpp"
#include "vulkansurfaceinfo.hpp"
#include "vulkandatabase.h"
#include "vulkanandroid.h"

#include "vulkan/vulkan.h"

struct vulkanInstanceInfo 
{
	std::vector<VulkanLayerInfo> globalLayers;
};

struct vulkanGlobalInfo
{
	std::vector<VkExtensionProperties> extensions;
};

class vulkanCapsViewer : public QMainWindow
{
	Q_OBJECT

public:
	std::vector<VulkanDeviceInfo> vulkanGPUs;
	vulkanInstanceInfo instanceInfo;
	vulkanGlobalInfo globalInfo;
    void checkReportDatabaseState();
	vulkanCapsViewer(QWidget *parent = 0);
	~vulkanCapsViewer();
private:
    std::string version = "1.3";
    QString vulkanApiVersion;
	int selectedDeviceIndex = 0;
	VkInstance vkInstance;
    VkSurfaceKHR surface;
    std::string surfaceExtension;
    VulkanDatabase databaseConnection;
	Ui::vulkanCapsViewerClass ui;
	settings appSettings;
	struct {
		TreeProxyFilter limits;
		TreeProxyFilter features;
		TreeProxyFilter formats;
	} filterProxies;
	struct {
		QStandardItemModel limits;
		QStandardItemModel features;
		QStandardItemModel formats;
	} models;
#ifdef ANDROID
    ANativeWindow* nativeWindow = nullptr;
#endif
	bool initVulkan();
	void getGlobalExtensions();
	void getGPUinfo(VulkanDeviceInfo *GPU, uint32_t id, VkPhysicalDevice device);
	void getGPUs();
	void displayDevice(int index);
	void displayDeviceProperties(VulkanDeviceInfo *device);
	void displayDeviceMemoryProperites(VulkanDeviceInfo *device);
	void displayDeviceLimits(VulkanDeviceInfo *device);
	void displayDeviceFeatures(VulkanDeviceInfo *device);
	void displayDeviceLayers(VulkanDeviceInfo *device);
	void displayDeviceFormats(VulkanDeviceInfo *device);
	void displayDeviceExtensions(VulkanDeviceInfo *device);
	void displayDeviceQueues(VulkanDeviceInfo *device);
    void displayDeviceSurfaceInfo(VulkanDeviceInfo &device);
    void displayGlobalLayers(QTreeWidget *tree);
	void displayGlobalExtensions();
	void exportReportAsJSON(std::string fileName, std::string submitter, std::string comment);
private Q_SLOTS:
	void slotClose();
	void slotBrowseDatabase();
	void slotDisplayOnlineReport();
	void slotRefresh();
	void slotAbout();
	void slotComboBoxGPUIndexChanged(int index);
	void slotSaveReport();
	void slotUploadReport();
	void slotSettings();
	void slotFilterLimits(QString text);
	void slotFilterFeatures(QString text);
	void slotFilterFormats(QString text);
};

#endif // VULKANCAPSVIEWER_H
