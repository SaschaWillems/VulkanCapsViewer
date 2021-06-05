/*
*
* Vulkan hardware capability viewer and database
*
* Database communication class implementation
*
* Copyright (C) 2016-2020 by Sascha Willems (www.saschawillems.de)
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

#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

#include "vulkanDeviceInfo.h"

using namespace std;

class VulkanDatabase :
	public QObject
{
	Q_OBJECT
private:
	QNetworkProxy *proxy;
	QNetworkAccessManager *manager;
	string httpGet(string url);
	string encodeUrl(string url);
public:
    static QString username;
    static QString password;
    static QString databaseUrl;
    int getReportId(VulkanDeviceInfo device);
    bool checkReportPresent(VulkanDeviceInfo device, int &reportId);
	bool checkCanUpdateReport(VulkanDeviceInfo &device, int reportId);
	bool checkServerConnection(QString& message);
	bool uploadReport(QJsonObject json, QString& message);
	bool postReportForUpdate(VulkanDeviceInfo &device, int reportId, QString &updateLog);
};

