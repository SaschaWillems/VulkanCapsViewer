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

#include "vulkanDeviceInfo.h"
#include "vulkanLayerInfo.hpp"
#include "vulkansurfaceinfo.hpp"
#include "vulkandatabase.h"
#include "vulkanandroid.h"

#include "vulkan/vulkan.h"

struct vulkanInstanceInfo {
	std::vector<VulkanLayerInfo> layers;
	std::vector<VkExtensionProperties> extensions;
};

struct vulkanGlobalInfo
{
	struct Features {
		bool deviceProperties2;
	} features;
};

class vulkanCapsViewer : public QMainWindow
{
	Q_OBJECT

public:
	static const std::string version;
	static const std::string reportVersion;
	std::vector<VulkanDeviceInfo> vulkanGPUs;
	vulkanInstanceInfo instanceInfo;
	vulkanGlobalInfo globalInfo;
	void checkReportDatabaseState();
	vulkanCapsViewer(QWidget *parent = 0);
	~vulkanCapsViewer();
	void exportReportAsJSON(std::string fileName, std::string submitter, std::string comment);
private:
	QString vulkanApiVersion;
	int selectedDeviceIndex = 0;
	VkInstance vkInstance = VK_NULL_HANDLE;
	VkSurfaceKHR surface;
	std::string surfaceExtension;
	VulkanDatabase databaseConnection;
	Ui::vulkanCapsViewerClass ui;
	settings appSettings;
	struct {
		TreeProxyFilter limits;
		TreeProxyFilter features;
		TreeProxyFilter formats;
		TreeProxyFilter extensions;
	} filterProxies;
	struct {
		QStandardItemModel limits;
		QStandardItemModel features;
		QStandardItemModel formats;
		QStandardItemModel extensions;
	} models;
#ifdef ANDROID
	ANativeWindow* nativeWindow = nullptr;
#endif
	bool initVulkan();
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
	void slotFilterExtensions(QString text);
	void slotFilterFormats(QString text);
	void slotComboTabChanged(int index);
};

#endif // VULKANCAPSVIEWER_H
