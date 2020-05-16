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
    QCommandLineOption optionDBConnection("d", "Load database connection information from an .ini file", "ini", "");

    parser.setApplicationDescription("Vulkan Hardware Capability Viewer");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(optionSaveReport);
    parser.addOption(optionDBConnection);
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
    else
    {
        w.show();
        return a.exec();
    }
}
