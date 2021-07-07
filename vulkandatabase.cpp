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

#include "vulkandatabase.h"
#include <QNetworkProxy>
#include <sstream>
#include <string>
#include <QMessageBox>
#include <QEventLoop>
#include <QHttpMultiPart>
#include <QXmlStreamReader>

QString VulkanDatabase::username = "";
QString VulkanDatabase::password = "";
QString VulkanDatabase::databaseUrl = "http://vulkan.gpuinfo.org/";

bool VulkanDatabase::checkServerConnection(QString& message)
{
    manager = new QNetworkAccessManager(nullptr);
	QUrl qurl(databaseUrl + "api/v3/serverstate.php");
    if (username != "" && password != "")
    {
        qurl.setUserName(username);
        qurl.setPassword(password);
    }
	QNetworkReply* reply = manager->get(QNetworkRequest(qurl));
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);
	message = reply->errorString();
	return (reply->error() == QNetworkReply::NoError);
}

/// <summary>
/// Execute http get request 
/// </summary>
/// <param name="url">url for the http get request</param>
/// <returns>string of the http get request or empty string in case of failure</returns>
string VulkanDatabase::httpGet(string url)
{
	manager = new QNetworkAccessManager(NULL);

	QUrl qurl(QString::fromStdString(url));

    if (username != "" && password != "")
    {
        qurl.setUserName(username);
        qurl.setPassword(password);
    }

	QNetworkReply* reply = manager->get(QNetworkRequest(qurl));

	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);

	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString replyStr(bytes);
		delete(manager);
		return replyStr.toStdString();
	}
	else
	{
		QString err;
		err = reply->errorString();
		delete(manager);
		return "";
	}
}

/// <summary>
/// Encodes an url (or string) to make it comply to RFC2396 by replacing
/// illegal characters
/// Some device descriptions may include a "+" that needs to be replaced (e.g. GeForce 9800 GTX+/PCI/SSE2)
/// </summary>
/// <param name="url">Url (or string) to be encoded</param>
/// <returns></returns>
string VulkanDatabase::encodeUrl(string url)
{
	QString urlStr(QString::fromStdString(url));
	urlStr.replace("+", "%2B"); 
	return urlStr.toStdString();
}

int VulkanDatabase::getReportId(VulkanDeviceInfo device)
{
	string reply;
	stringstream urlss;
	urlss << databaseUrl.toStdString() << "api/v3/getreportid.php?"
		<< "devicename=" << device.props.deviceName
        << "&driverversion=" << device.getDriverVersion()
		<< "&osname=" << device.os.name
		<< "&osversion=" << device.os.version
        << "&osarchitecture=" << device.os.architecture
        << "&apiversion=" << vulkanResources::versionToString(device.props.apiVersion);
#ifdef __ANDROID__
	// Compare against platform info on Android, as driver version and device name (which is just the GPU name on android) are not sufficient to identify a single report
	urlss << "&androidproductmodel=" << device.platformdetails["android.ProductModel"];
	urlss << "&androidproductmanufacturer=" << device.platformdetails["android.ProductManufacturer"];
#endif
	string url = encodeUrl(urlss.str());
	reply = httpGet(url);
	return (!reply.empty()) ? atoi(reply.c_str()) : -1;
}

/// Checks if the report is present in the online database
bool VulkanDatabase::checkReportPresent(VulkanDeviceInfo device, int& reportId)
{
	reportId = getReportId(device);
	return (reportId > -1) ? true : false;
}

bool VulkanDatabase::uploadReport(QJsonObject json, QString& message)
{
	manager = new QNetworkAccessManager(nullptr);
	QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart httpPart;
	httpPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"data\"; filename=\"vulkanreport.json\""));
	QJsonDocument doc(json);
	httpPart.setBody(doc.toJson());
	multiPart->append(httpPart);
	QUrl qurl(databaseUrl + "api/v3/uploadreport.php");
	QNetworkRequest request(qurl);
	QNetworkReply* reply = manager->post(request, multiPart);
	multiPart->setParent(reply);
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);
	bool result = false;
	if (reply->error() == QNetworkReply::NoError)
	{
		result = true;
	}
	else {
		message = reply->errorString();
		result = false;
	}
	delete(manager);
	return result;
}

// Checks if the report stored in the database can be updated with missing data from the local report
bool VulkanDatabase::checkCanUpdateReport(VulkanDeviceInfo& device, int reportId)
{
	manager = new QNetworkAccessManager(nullptr);
	QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart jsonPart;
	jsonPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"data\"; filename=\"update_check_report.json\""));
	QJsonDocument doc(device.toJson("", ""));
	jsonPart.setBody(doc.toJson());
	multiPart->append(jsonPart);
	QUrl qurl(databaseUrl + "api/v3/checkcanupdatereport.php?reportid=" + QString::number(reportId));
	QNetworkRequest request(qurl);
	QNetworkReply* reply = manager->post(request, multiPart);
	multiPart->setParent(reply);
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);
	bool result = false;
	if (reply->error() == QNetworkReply::NoError)
	{
		QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
		bool canUpdate = response.isObject() ? response.object()["canupdate"].toBool() : false;
		result = canUpdate;
	}
	else
	{
		QString err(reply->errorString());
		result = false;
	}
	delete(manager);
	return result;
}

// Upload the current report for updating an existing report
bool VulkanDatabase::postReportForUpdate(VulkanDeviceInfo &device, int reportId, QString &updateLog)
{
	manager = new QNetworkAccessManager(nullptr);
	QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart jsonPart;
	jsonPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"data\"; filename=\"update_report.json\""));
	QJsonDocument doc(device.toJson("", ""));
	jsonPart.setBody(doc.toJson());
	multiPart->append(jsonPart);
	QUrl qurl(databaseUrl + "api/v3/updatereport.php?reportid=" + QString::number(reportId));
	QNetworkRequest request(qurl);
	QNetworkReply* reply = manager->post(request, multiPart);
	multiPart->setParent(reply);
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);
	bool result = false;
	if (reply->error() == QNetworkReply::NoError)
	{
		QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
		if (response.isObject() && response.object()["log"].isArray()) {
			QJsonArray logArray = response.object()["log"].toArray();
			foreach(const QJsonValue logEntry, logArray) {
				updateLog += logEntry.toString() + "\n";
			}
		}
		result = true;
	}
	else
	{
		QString err(reply->errorString());
		result = false;
	}
	delete(manager);
	return result;
}
