/*
*
* Vulkan hardware capability viewer
*
* Submit report dialog
*
* Copyright (C) 2015 by Sascha Willems (www.saschawillems.de)
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

#pragma once
#include <QDialog>
#include <QLineEdit>
#include "submitDialog.h"

class submitDialog : public QDialog
{
	Q_OBJECT
private:
	QLineEdit *editSubmitter;
	QLineEdit *editComment;
public:
	std::string submitter;
	std::string comment;
	submitDialog(QString submitter, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~submitDialog();
	std::string getSubmitter();
	std::string getComment();
	private Q_SLOTS:
	void slotAccept();
	void slotCancel();
};




