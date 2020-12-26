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

/// <summary>
/// Checks if the online database can be reached
/// </summary>
bool VulkanDatabase::checkServerConnection()
{
    manager = new QNetworkAccessManager(nullptr);

	QUrl qurl(QString::fromStdString(getBaseUrl() + "/services/serverstate.php"));

    if (username != "" && password != "")
    {
        qurl.setUserName(username);
        qurl.setPassword(password);
    }

	QNetworkReply* reply = manager->get(QNetworkRequest(qurl));

	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec(QEventLoop::ExcludeUserInputEvents);

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
	loop.exec();

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
/// Execute http post
/// </summary>
/// <param name="url">url for the http post</param>
/// <param name="data">string data to post</param>
/// <returns>Server answer</returns>
string VulkanDatabase::httpPost(string url, string data)
{
	manager = new QNetworkAccessManager(NULL);

	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	QHttpPart jsonPart;
	jsonPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"data\"; filename=\"vulkanreport.json\""));
	jsonPart.setBody(QString::fromStdString(data).toLatin1());
	multiPart->append(jsonPart);

	QUrl qurl(QString::fromStdString(url));

    if (username != "" && password != "")
    {
        qurl.setUserName(username);
        qurl.setPassword(password);
    }

	QNetworkRequest request(qurl);
	QNetworkReply *reply = manager->post(request, multiPart);
	multiPart->setParent(reply);
	
	QEventLoop loop;
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

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
		return err.toStdString();
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
	urlss << getBaseUrl() << "/services/getreportid.php?"
		<< "devicename=" << device.props.deviceName
        << "&driverversion=" << device.getDriverVersion()
		<< "&osname=" << device.os.name
		<< "&osversion=" << device.os.version
        << "&osarchitecture=" << device.os.architecture
        << "&apiversion=" << vulkanResources::versionToString(device.props.apiVersion);
	string url = encodeUrl(urlss.str());
	reply = httpGet(url);
	return (!reply.empty()) ? atoi(reply.c_str()) : -1;
}

/// <summary>
/// Checks if the report is present in the online database
/// </summary>
bool VulkanDatabase::checkReportPresent(VulkanDeviceInfo device)
{
    int reportID = getReportId(device);
	return (reportID > -1) ? true : false;
}

/// <summary>
/// Fechtes an xml with all report data from the online database
/// </summary>
/// <param name="reportId">id of the report to get the report xml for</param>
/// <returns>xml string</returns>
string VulkanDatabase::fetchReport(int reportId)
{
	string reportXml;
	stringstream urlss;
    urlss << getBaseUrl() << "services/getreport.php?id=" << reportId;
	reportXml = httpGet(urlss.str());
	return reportXml;
}

/// <summary>
/// Posts the given xml for a report to the database	
/// </summary>
/// <returns>todo</returns>
string VulkanDatabase::postReport(string xml)
{
	string httpReply;
	stringstream urlss;
    urlss << getBaseUrl() << "api/v2/uploadreport.php";
	httpReply = httpPost(urlss.str(), xml);
	return httpReply;
}

/// <summary>
/// Posts the given url to the db report update script 
/// </summary>
/// <returns>Coma separated list of updated caps</returns>
string VulkanDatabase::postReportForUpdate(string xml)
{
	string httpReply;
	stringstream urlss;
	urlss << getBaseUrl() << "services/updatereport.php";
	httpReply = httpPost(urlss.str(), xml);
	return httpReply;
}


string VulkanDatabase::getBaseUrl()
{
    return databaseUrl.toStdString();
}

