#include "vulkancapsviewer.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    a.setApplicationVersion(QString::fromStdString(vulkanCapsViewer::version));

    QCommandLineParser parser;  

    QCommandLineOption optionDBUser("u", "User name for protected database access", "dbuser", "");
    QCommandLineOption optionDBPass("p", "Password for protected database access", "dbpass", "");
    QCommandLineOption optionSaveReport("s", "Save report to file without starting the GUI", "savereport", "");

    parser.setApplicationDescription("Vulkan Hardware Capability Viewer");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addOption(optionDBUser);
    parser.addOption(optionDBPass);
    parser.addOption(optionSaveReport);
    //parser.parse(a.arguments());
    parser.process(a);
    if (parser.isSet(optionDBUser))
    {
        VulkanDatabase::dbUser = parser.value(optionDBUser);
    }
    if (parser.isSet(optionDBPass))
    {
        VulkanDatabase::dbPass = parser.value(optionDBPass);
    }
    VulkanDatabase::dbLogin = (!VulkanDatabase::dbUser.isEmpty()) && (!VulkanDatabase::dbPass.isEmpty());
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
