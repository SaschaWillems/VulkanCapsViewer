/*
*
* Vulkan hardware capability viewer
*
* Copyright (C) 2016-2023 by Sascha Willems (www.saschawillems.de)
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
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QApplication>
#include <QtGlobal>

void logMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QString msgType;
    switch (type) {
    case QtInfoMsg:
        msgType = "Info";
        break;
    case QtDebugMsg:
        msgType = "Debug";
        break;
    case QtWarningMsg:
        msgType = "Warning";
        break;
    case QtCriticalMsg:
        msgType = "Critical";
        break;
    case QtFatalMsg:
        msgType = "Fatal";
        break;
    }
    QDateTime timeStamp = QDateTime::currentDateTime();
    QString logMessage = QString("%1: %2: %3").arg(timeStamp.toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(msgType).arg(msg);
    QFile logFile("log.txt");
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream textStream(&logFile);
        textStream << logMessage << Qt::endl;
    };
    // Suppress compiler warning
    (void)context;
}

int main(int argc, char *argv[])
{
    // Disable dark mode on Winodows
    qputenv("QT_QPA_PLATFORM", "windows::darkmode=0");

    QApplication application(argc, argv);
    application.setApplicationVersion(VulkanCapsViewer::version);

    QCommandLineParser parser;  

    QCommandLineOption optionSaveReport("s", "Save report to file without starting the GUI", "savereport", "");
    QCommandLineOption optionUploadReport("upload", "Upload report for device with given index to the database without visual interaction");
    QCommandLineOption optionUploadReportDeviceIndex("deviceindex", "Set device index for report upload", "0");
    QCommandLineOption optionUploadReportSubmitter("submitter", "Set optional submitter name for report upload", "submitter", "");
    QCommandLineOption optionUploadReportComment("comment", "Set optional comment for report upload", "comment", "");
    QCommandLineOption optionDBConnection("d", "Load database connection information from an .ini file", "db.ini", "");
    QCommandLineOption optionLogFile("log", "Write log messages to a text file for debugging (log.txt)");
    QCommandLineOption optionDisableProxy("noproxy", "Run withouth proxy (overrides setting)");

    parser.setApplicationDescription("Vulkan Hardware Capability Viewer");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(optionSaveReport);
    parser.addOption(optionUploadReport);
    parser.addOption(optionDBConnection);
    parser.addOption(optionUploadReportDeviceIndex);
    parser.addOption(optionUploadReportSubmitter);
    parser.addOption(optionUploadReportComment);
    parser.addOption(optionLogFile);
    parser.addOption(optionDisableProxy);
    parser.process(application);

    // Custom database settings can be applied via a .ini file
    if (parser.isSet(optionDBConnection))
    {
        QString fileName = parser.value(optionDBConnection);
        if (QFile::exists(fileName))
        {
            QSettings dbSettings(fileName, QSettings::IniFormat);
            VulkanDatabase::username = dbSettings.value("username").toString();
            VulkanDatabase::password = dbSettings.value("password").toString();
            VulkanDatabase::databaseUrl = dbSettings.value("databaseUrl").toString();
        }
    }

    if (parser.isSet(optionLogFile)) {
        qInstallMessageHandler(logMessageHandler);
    }

    settings.restore();
    if (parser.isSet(optionDisableProxy)) {
        settings.proxyEnabled = false;
        settings.applyProxySettings();
    }

    VulkanCapsViewer vulkanCapsViewer;

    if (parser.isSet(optionSaveReport))
    {
        vulkanCapsViewer.saveReport(parser.value(optionSaveReport), "", "");
        return 0;
    }

    if (parser.isSet(optionUploadReport))
    {
        int deviceIndex = 0;
        QString submitter = "";
        QString comment = "";
        if (parser.isSet(optionUploadReportDeviceIndex)) {
            deviceIndex = parser.value(optionUploadReportDeviceIndex).toInt();
        }
        if (parser.isSet(optionUploadReportSubmitter)) {
            submitter = parser.value(optionUploadReportSubmitter);
        }
        if (parser.isSet(optionUploadReportComment)) {
            comment = parser.value(optionUploadReportComment);
        }
        int res = vulkanCapsViewer.uploadReportNonVisual(deviceIndex, submitter, comment);
        return res;
    }

    qInfo() << "Application start";
    vulkanCapsViewer.show();
    return application.exec();
}
