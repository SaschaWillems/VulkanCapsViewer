#include "vulkancapsviewer.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QApplication>
#include <QtGlobal>

int main(int argc, char *argv[])
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);
    a.setApplicationVersion(QString::fromStdString(vulkanCapsViewer::version));

    QCommandLineParser parser;  

    QCommandLineOption optionSaveReport("s", "Save report to file without starting the GUI", "savereport", "");
    QCommandLineOption optionUploadReport("upload", "Upload report for device with given index to the database without visual interaction");
    QCommandLineOption optionUploadReportDeviceIndex("deviceindex", "Set device index for report upload", "0");
    QCommandLineOption optionUploadReportSubmitter("submitter", "Set optional submitter name for report upload", "submitter", "");
    QCommandLineOption optionUploadReportComment("comment", "Set optional comment for report upload", "comment", "");
    QCommandLineOption optionDBConnection("d", "Load database connection information from an .ini file", "db.ini", "");

    parser.setApplicationDescription("Vulkan Hardware Capability Viewer");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(optionSaveReport);
    parser.addOption(optionUploadReport);
    parser.addOption(optionDBConnection);
    parser.addOption(optionUploadReportDeviceIndex);
    parser.addOption(optionUploadReportSubmitter);
    parser.addOption(optionUploadReportComment);
    parser.process(a);

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

    vulkanCapsViewer w;

    if (parser.isSet(optionSaveReport))
    {
        w.exportReportAsJSON(parser.value(optionSaveReport).toStdString(), "", "");
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
        int res = w.uploadReportNonVisual(deviceIndex, submitter, comment);
        return res;
    }

    w.show();
    return a.exec();
}
