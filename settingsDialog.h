#pragma once
#include <QDialog>
#include "settings.h"

class settingsDialog : public QDialog
{
	Q_OBJECT
private:
	settings appSettings;
public:
	settingsDialog(settings appSet, QWidget * parent = 0, Qt::WindowFlags f = 0);
	~settingsDialog();
private Q_SLOTS:
	void slotAccept();
	void slotCancel();
};
