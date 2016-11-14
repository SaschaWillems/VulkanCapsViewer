#include "vulkancapsviewer.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption optionDBUser("u", "User name for protected database access", "dbuser", "");
    QCommandLineOption optionDBPass("p", "Password for protected database access", "dbpass", "");
    parser.addOption(optionDBUser);
    parser.addOption(optionDBPass);
    parser.parse(a.arguments());
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
	w.show();
	return a.exec();
}
