#pragma once
#include <QDialog>
#include "settings.h"

class settingsDialog : public QDialog
{
	Q_OBJECT
private:
	settings appSettings;
public:
    settingsDialog(settings appSet);
	~settingsDialog();
private Q_SLOTS:
	void slotAccept();
	void slotCancel();
};




