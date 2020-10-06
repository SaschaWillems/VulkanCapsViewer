/*
*
* OpenGL hardware capability viewer and database
*
* Submit report dialog
*
* Copyright (C) 2011-2015 by Sascha Willems (www.saschawillems.de)
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

#include "submitDialog.h"

#include <QFormLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QLine>
#include <QSettings>
#include <QDialogButtonBox>

submitDialog::submitDialog(QString submitter)
{
	QFormLayout *formLayout = new QFormLayout;

    // QDialogBox doesn't appear modal on Android which makes it hard to see
    #ifdef ANDROID
        QLabel *labelCaption = new QLabel();
        labelCaption->setText("Submit report to database");
        formLayout->addRow(labelCaption);
        setStyleSheet("QDialog{ border: 2px solid black; border-style: solid; border-radius: 4px; }");
    #endif

	editSubmitter = new QLineEdit();
	editSubmitter->setObjectName("submitter");
	editSubmitter->setPlaceholderText("Can be left empty");
	editSubmitter->setText(submitter);
	editSubmitter->setMinimumWidth(200);
	formLayout->addRow("Submitter:", editSubmitter);

	editComment = new QLineEdit();
	editComment->setObjectName("comment");
	editComment->setPlaceholderText("Can be left empty");
	editComment->setMinimumWidth(200);
	editComment->setMaxLength(32);
	formLayout->addRow("Comment:", editComment);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(slotAccept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(slotCancel()));

	formLayout->addWidget(buttonBox);

	setLayout(formLayout);
	setWindowTitle("Submit report");
}


submitDialog::~submitDialog()
{
}

void submitDialog::slotAccept()
{
	this->accept();
}

void submitDialog::slotCancel()
{
	this->reject();
}

std::string submitDialog::getSubmitter()
{
	return editSubmitter->text().toStdString();
}

std::string submitDialog::getComment()
{
	return editComment->text().toStdString();
}
