#include "vulkancapsviewer.h"
#include <QtWidgets/QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	vulkanCapsViewer w;
	w.show();
	return a.exec();
}
