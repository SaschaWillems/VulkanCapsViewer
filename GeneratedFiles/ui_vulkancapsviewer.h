/********************************************************************************
** Form generated from reading UI file 'vulkancapsviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VULKANCAPSVIEWER_H
#define UI_VULKANCAPSVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vulkanCapsViewerClass
{
public:
    QAction *actionRefresh;
    QAction *actionUpload;
    QAction *actionDatabase;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionSaveReport;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout_16;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_buttons;
    QToolButton *toolButtonUpload;
    QToolButton *toolButtonSave;
    QToolButton *toolButtonOnlineDevice;
    QToolButton *toolButtonOnlineDataBase;
    QToolButton *toolButtonSettings;
    QToolButton *toolButtonAbout;
    QToolButton *toolButtonExit;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *reportForLabel;
    QComboBox *comboBoxGPU;
    QLabel *labelDevicePresent;
    QTabWidget *tabWidget;
    QWidget *tabDevice;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidgetDevice;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidgetDeviceProperties;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_3;
    QFormLayout *formLayout_3;
    QLineEdit *filterLineEditFeatures;
    QLabel *filterLabel_2;
    QTreeView *treeViewDeviceFeatures;
    QWidget *tabDeviceLimits;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_2;
    QFormLayout *formLayout_2;
    QLabel *filterLabel;
    QLineEdit *filterLineEditLimits;
    QTreeView *treeViewDeviceLimits;
    QWidget *tab;
    QVBoxLayout *verticalLayout_12;
    QTreeWidget *treeWidgetDeviceExtensions;
    QWidget *tab_11;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_4;
    QFormLayout *formLayout_4;
    QLabel *filterLabel_3;
    QLineEdit *filterLineEditFormats;
    QTreeView *treeViewFormats;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_6;
    QTreeWidget *treeWidgetDeviceLayers;
    QWidget *tab_12;
    QVBoxLayout *verticalLayout_15;
    QTreeWidget *treeWidgetQueues;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_17;
    QTreeWidget *treeWidgetDeviceMemory;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget_2;
    QWidget *tabVulkanLayers;
    QVBoxLayout *verticalLayout_9;
    QTreeWidget *treeWidgetGlobalLayers;
    QWidget *tabVulkanExtensions;
    QVBoxLayout *verticalLayout_10;
    QTreeWidget *treeWidgetGlobalExtenssions;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *vulkanCapsViewerClass)
    {
        if (vulkanCapsViewerClass->objectName().isEmpty())
            vulkanCapsViewerClass->setObjectName(QStringLiteral("vulkanCapsViewerClass"));
        vulkanCapsViewerClass->resize(927, 755);
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        vulkanCapsViewerClass->setFont(font);
        vulkanCapsViewerClass->setAutoFillBackground(false);
        vulkanCapsViewerClass->setStyleSheet(QLatin1String("QToolBar {\n"
"	background-image: url(:/vulkancapsviewer/Resources/vulkan48.png);\n"
"	background-repeat:no;\n"
"	background-position:right;\n"
"	border:0px;\n"
"}\n"
"\n"
"QTabWidget::pane {   \n"
"	align:center;\n"
"	border-top: 1px solid rgb(180, 180, 180);\n"
"}\n"
"\n"
"QTabWidget::tab-bar { \n"
"	alignment: center; \n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    min-width: 8ex;\n"
"    padding: 8px 16px;\n"
"   border:0px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {       \n"
"	color: #cb2b30;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"border-bottom: 2px solid #a41e22;\n"
"color: #a41e22;\n"
"}\n"
"\n"
"QToolButton {\n"
"color:#FFFFFF;\n"
"border-top:0px;\n"
"border-bottom:0px;\n"
"}\n"
"\n"
"QToolButton::hover {       \n"
"	color: #cb2b30;\n"
"	background: rgb(180, 180, 180);\n"
"}"));
        vulkanCapsViewerClass->setDocumentMode(false);
        vulkanCapsViewerClass->setUnifiedTitleAndToolBarOnMac(true);
        actionRefresh = new QAction(vulkanCapsViewerClass);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        actionRefresh->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/vulkancapsviewer/Resources/refresh48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon);
        actionRefresh->setVisible(true);
        actionRefresh->setIconVisibleInMenu(true);
        actionUpload = new QAction(vulkanCapsViewerClass);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        actionUpload->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/vulkancapsviewer/Resources/upload48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpload->setIcon(icon1);
        actionDatabase = new QAction(vulkanCapsViewerClass);
        actionDatabase->setObjectName(QStringLiteral("actionDatabase"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/vulkancapsviewer/Resources/browse48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDatabase->setIcon(icon2);
        actionSettings = new QAction(vulkanCapsViewerClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionSettings->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/vulkancapsviewer/Resources/settings48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon3);
        actionAbout = new QAction(vulkanCapsViewerClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/vulkancapsviewer/Resources/about48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionExit = new QAction(vulkanCapsViewerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/vulkancapsviewer/Resources/close48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        actionSaveReport = new QAction(vulkanCapsViewerClass);
        actionSaveReport->setObjectName(QStringLiteral("actionSaveReport"));
        actionSaveReport->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/vulkancapsviewer/Resources/save48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveReport->setIcon(icon6);
        centralWidget = new QWidget(vulkanCapsViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        centralWidget->setFont(font1);
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(68, 68, 68);"));
        verticalLayout_16 = new QVBoxLayout(widget);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 5);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setEnabled(true);
        widget_5->setCursor(QCursor(Qt::ArrowCursor));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(32, 32, 32);"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 5, 0, 5);
        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setSpacing(6);
        horizontalLayout_buttons->setObjectName(QStringLiteral("horizontalLayout_buttons"));
        toolButtonUpload = new QToolButton(widget_5);
        toolButtonUpload->setObjectName(QStringLiteral("toolButtonUpload"));
        toolButtonUpload->setIcon(icon1);
        toolButtonUpload->setIconSize(QSize(64, 32));
        toolButtonUpload->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonUpload);

        toolButtonSave = new QToolButton(widget_5);
        toolButtonSave->setObjectName(QStringLiteral("toolButtonSave"));
        toolButtonSave->setIcon(icon6);
        toolButtonSave->setIconSize(QSize(64, 32));
        toolButtonSave->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonSave);

        toolButtonOnlineDevice = new QToolButton(widget_5);
        toolButtonOnlineDevice->setObjectName(QStringLiteral("toolButtonOnlineDevice"));
        toolButtonOnlineDevice->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/vulkancapsviewer/Resources/device48.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonOnlineDevice->setIcon(icon7);
        toolButtonOnlineDevice->setIconSize(QSize(64, 32));
        toolButtonOnlineDevice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonOnlineDevice);

        toolButtonOnlineDataBase = new QToolButton(widget_5);
        toolButtonOnlineDataBase->setObjectName(QStringLiteral("toolButtonOnlineDataBase"));
        toolButtonOnlineDataBase->setIcon(icon2);
        toolButtonOnlineDataBase->setIconSize(QSize(64, 32));
        toolButtonOnlineDataBase->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonOnlineDataBase);

        toolButtonSettings = new QToolButton(widget_5);
        toolButtonSettings->setObjectName(QStringLiteral("toolButtonSettings"));
        toolButtonSettings->setIcon(icon3);
        toolButtonSettings->setIconSize(QSize(64, 32));
        toolButtonSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonSettings->setArrowType(Qt::NoArrow);

        horizontalLayout_buttons->addWidget(toolButtonSettings);

        toolButtonAbout = new QToolButton(widget_5);
        toolButtonAbout->setObjectName(QStringLiteral("toolButtonAbout"));
        toolButtonAbout->setIcon(icon4);
        toolButtonAbout->setIconSize(QSize(64, 32));
        toolButtonAbout->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonAbout);

        toolButtonExit = new QToolButton(widget_5);
        toolButtonExit->setObjectName(QStringLiteral("toolButtonExit"));
        toolButtonExit->setIcon(icon5);
        toolButtonExit->setIconSize(QSize(64, 32));
        toolButtonExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_buttons->addWidget(toolButtonExit);

        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        label->setLineWidth(0);
        label->setPixmap(QPixmap(QString::fromUtf8(":/vulkancapsviewer/Resources/vulkan48.png")));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_buttons->addWidget(label);


        horizontalLayout_3->addLayout(horizontalLayout_buttons);


        verticalLayout_16->addWidget(widget_5);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        reportForLabel = new QLabel(widget);
        reportForLabel->setObjectName(QStringLiteral("reportForLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reportForLabel->sizePolicy().hasHeightForWidth());
        reportForLabel->setSizePolicy(sizePolicy);
        reportForLabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 11pt;"));

        formLayout->setWidget(0, QFormLayout::LabelRole, reportForLabel);

        comboBoxGPU = new QComboBox(widget);
        comboBoxGPU->setObjectName(QStringLiteral("comboBoxGPU"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxGPU->sizePolicy().hasHeightForWidth());
        comboBoxGPU->setSizePolicy(sizePolicy1);
        comboBoxGPU->setMinimumSize(QSize(150, 0));
        comboBoxGPU->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 10pt;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxGPU);


        verticalLayout_16->addLayout(formLayout);

        labelDevicePresent = new QLabel(widget);
        labelDevicePresent->setObjectName(QStringLiteral("labelDevicePresent"));
        labelDevicePresent->setStyleSheet(QLatin1String("font: 10pt;\n"
"color: rgb(255, 255, 255);"));
        labelDevicePresent->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(labelDevicePresent);


        verticalLayout_7->addWidget(widget);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);
        tabDevice = new QWidget();
        tabDevice->setObjectName(QStringLiteral("tabDevice"));
        horizontalLayout_2 = new QHBoxLayout(tabDevice);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidgetDevice = new QTabWidget(tabDevice);
        tabWidgetDevice->setObjectName(QStringLiteral("tabWidgetDevice"));
        tabWidgetDevice->setTabPosition(QTabWidget::North);
        tabWidgetDevice->setTabShape(QTabWidget::Rounded);
        tabWidgetDevice->setTabBarAutoHide(false);
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        horizontalLayout = new QHBoxLayout(tab_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidgetDeviceProperties = new QTreeWidget(tab_6);
        treeWidgetDeviceProperties->setObjectName(QStringLiteral("treeWidgetDeviceProperties"));
        treeWidgetDeviceProperties->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetDeviceProperties->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetDeviceProperties->setAlternatingRowColors(true);
        treeWidgetDeviceProperties->header()->setDefaultSectionSize(200);
        treeWidgetDeviceProperties->header()->setStretchLastSection(true);

        horizontalLayout->addWidget(treeWidgetDeviceProperties);

        tabWidgetDevice->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_13 = new QVBoxLayout(tab_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        formLayout_3 = new QFormLayout(widget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 2, 0, 2);
        filterLineEditFeatures = new QLineEdit(widget_3);
        filterLineEditFeatures->setObjectName(QStringLiteral("filterLineEditFeatures"));
        sizePolicy1.setHeightForWidth(filterLineEditFeatures->sizePolicy().hasHeightForWidth());
        filterLineEditFeatures->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, filterLineEditFeatures);

        filterLabel_2 = new QLabel(widget_3);
        filterLabel_2->setObjectName(QStringLiteral("filterLabel_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, filterLabel_2);


        verticalLayout_13->addWidget(widget_3);

        treeViewDeviceFeatures = new QTreeView(tab_3);
        treeViewDeviceFeatures->setObjectName(QStringLiteral("treeViewDeviceFeatures"));
        treeViewDeviceFeatures->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeViewDeviceFeatures->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewDeviceFeatures->setAlternatingRowColors(true);
        treeViewDeviceFeatures->header()->setVisible(false);
        treeViewDeviceFeatures->header()->setMinimumSectionSize(200);

        verticalLayout_13->addWidget(treeViewDeviceFeatures);

        tabWidgetDevice->addTab(tab_3, QString());
        tabDeviceLimits = new QWidget();
        tabDeviceLimits->setObjectName(QStringLiteral("tabDeviceLimits"));
        verticalLayout_4 = new QVBoxLayout(tabDeviceLimits);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_2 = new QWidget(tabDeviceLimits);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        formLayout_2 = new QFormLayout(widget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 2, 0, 2);
        filterLabel = new QLabel(widget_2);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, filterLabel);

        filterLineEditLimits = new QLineEdit(widget_2);
        filterLineEditLimits->setObjectName(QStringLiteral("filterLineEditLimits"));
        sizePolicy1.setHeightForWidth(filterLineEditLimits->sizePolicy().hasHeightForWidth());
        filterLineEditLimits->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, filterLineEditLimits);


        verticalLayout_4->addWidget(widget_2);

        treeViewDeviceLimits = new QTreeView(tabDeviceLimits);
        treeViewDeviceLimits->setObjectName(QStringLiteral("treeViewDeviceLimits"));
        treeViewDeviceLimits->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeViewDeviceLimits->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewDeviceLimits->setAlternatingRowColors(true);
        treeViewDeviceLimits->setHeaderHidden(true);

        verticalLayout_4->addWidget(treeViewDeviceLimits);

        tabWidgetDevice->addTab(tabDeviceLimits, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_12 = new QVBoxLayout(tab);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        treeWidgetDeviceExtensions = new QTreeWidget(tab);
        treeWidgetDeviceExtensions->setObjectName(QStringLiteral("treeWidgetDeviceExtensions"));
        treeWidgetDeviceExtensions->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetDeviceExtensions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetDeviceExtensions->setAlternatingRowColors(true);

        verticalLayout_12->addWidget(treeWidgetDeviceExtensions);

        tabWidgetDevice->addTab(tab, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        verticalLayout_14 = new QVBoxLayout(tab_11);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        widget_4 = new QWidget(tab_11);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        formLayout_4 = new QFormLayout(widget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 2, 0, 2);
        filterLabel_3 = new QLabel(widget_4);
        filterLabel_3->setObjectName(QStringLiteral("filterLabel_3"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, filterLabel_3);

        filterLineEditFormats = new QLineEdit(widget_4);
        filterLineEditFormats->setObjectName(QStringLiteral("filterLineEditFormats"));
        sizePolicy1.setHeightForWidth(filterLineEditFormats->sizePolicy().hasHeightForWidth());
        filterLineEditFormats->setSizePolicy(sizePolicy1);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, filterLineEditFormats);


        verticalLayout_14->addWidget(widget_4);

        treeViewFormats = new QTreeView(tab_11);
        treeViewFormats->setObjectName(QStringLiteral("treeViewFormats"));
        treeViewFormats->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeViewFormats->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewFormats->setAlternatingRowColors(true);
        treeViewFormats->setSortingEnabled(true);
        treeViewFormats->header()->setMinimumSectionSize(250);

        verticalLayout_14->addWidget(treeViewFormats);

        tabWidgetDevice->addTab(tab_11, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        verticalLayout_6 = new QVBoxLayout(tab_9);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        treeWidgetDeviceLayers = new QTreeWidget(tab_9);
        treeWidgetDeviceLayers->setObjectName(QStringLiteral("treeWidgetDeviceLayers"));
        treeWidgetDeviceLayers->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetDeviceLayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetDeviceLayers->setAlternatingRowColors(true);
        treeWidgetDeviceLayers->header()->setDefaultSectionSize(200);
        treeWidgetDeviceLayers->header()->setStretchLastSection(true);

        verticalLayout_6->addWidget(treeWidgetDeviceLayers);

        tabWidgetDevice->addTab(tab_9, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        verticalLayout_15 = new QVBoxLayout(tab_12);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        treeWidgetQueues = new QTreeWidget(tab_12);
        treeWidgetQueues->setObjectName(QStringLiteral("treeWidgetQueues"));
        treeWidgetQueues->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetQueues->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetQueues->setAlternatingRowColors(true);
        treeWidgetQueues->header()->setDefaultSectionSize(250);
        treeWidgetQueues->header()->setStretchLastSection(true);

        verticalLayout_15->addWidget(treeWidgetQueues);

        tabWidgetDevice->addTab(tab_12, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_17 = new QVBoxLayout(tab_2);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        treeWidgetDeviceMemory = new QTreeWidget(tab_2);
        treeWidgetDeviceMemory->setObjectName(QStringLiteral("treeWidgetDeviceMemory"));
        treeWidgetDeviceMemory->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetDeviceMemory->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetDeviceMemory->setAlternatingRowColors(true);
        treeWidgetDeviceMemory->header()->setDefaultSectionSize(200);
        treeWidgetDeviceMemory->header()->setStretchLastSection(true);

        verticalLayout_17->addWidget(treeWidgetDeviceMemory);

        tabWidgetDevice->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidgetDevice);

        tabWidget->addTab(tabDevice, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_8 = new QVBoxLayout(tab_5);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(tab_5);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tabVulkanLayers = new QWidget();
        tabVulkanLayers->setObjectName(QStringLiteral("tabVulkanLayers"));
        verticalLayout_9 = new QVBoxLayout(tabVulkanLayers);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        treeWidgetGlobalLayers = new QTreeWidget(tabVulkanLayers);
        treeWidgetGlobalLayers->setObjectName(QStringLiteral("treeWidgetGlobalLayers"));
        treeWidgetGlobalLayers->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetGlobalLayers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetGlobalLayers->setAlternatingRowColors(true);
        treeWidgetGlobalLayers->setIndentation(10);
        treeWidgetGlobalLayers->header()->setDefaultSectionSize(200);
        treeWidgetGlobalLayers->header()->setStretchLastSection(true);

        verticalLayout_9->addWidget(treeWidgetGlobalLayers);

        tabWidget_2->addTab(tabVulkanLayers, QString());
        tabVulkanExtensions = new QWidget();
        tabVulkanExtensions->setObjectName(QStringLiteral("tabVulkanExtensions"));
        verticalLayout_10 = new QVBoxLayout(tabVulkanExtensions);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        treeWidgetGlobalExtenssions = new QTreeWidget(tabVulkanExtensions);
        treeWidgetGlobalExtenssions->setObjectName(QStringLiteral("treeWidgetGlobalExtenssions"));
        treeWidgetGlobalExtenssions->setStyleSheet(QStringLiteral("QTreeView::item { height: 24px;}"));
        treeWidgetGlobalExtenssions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidgetGlobalExtenssions->setAlternatingRowColors(true);

        verticalLayout_10->addWidget(treeWidgetGlobalExtenssions);

        tabWidget_2->addTab(tabVulkanExtensions, QString());

        verticalLayout_8->addWidget(tabWidget_2);

        tabWidget->addTab(tab_5, QString());

        verticalLayout_7->addWidget(tabWidget);

        vulkanCapsViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vulkanCapsViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 927, 20));
        vulkanCapsViewerClass->setMenuBar(menuBar);

        retranslateUi(vulkanCapsViewerClass);

        tabWidget->setCurrentIndex(0);
        tabWidgetDevice->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(vulkanCapsViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *vulkanCapsViewerClass)
    {
        vulkanCapsViewerClass->setWindowTitle(QApplication::translate("vulkanCapsViewerClass", "Vulkan Hardware Capability Viewer 1.0 (beta)", 0));
        actionRefresh->setText(QApplication::translate("vulkanCapsViewerClass", "Refresh", 0));
#ifndef QT_NO_TOOLTIP
        actionRefresh->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Refresh report", 0));
#endif // QT_NO_TOOLTIP
        actionUpload->setText(QApplication::translate("vulkanCapsViewerClass", "Upload", 0));
#ifndef QT_NO_TOOLTIP
        actionUpload->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Upload device report to online database", 0));
#endif // QT_NO_TOOLTIP
        actionDatabase->setText(QApplication::translate("vulkanCapsViewerClass", "Database", 0));
#ifndef QT_NO_TOOLTIP
        actionDatabase->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Display online database in default browser", 0));
#endif // QT_NO_TOOLTIP
        actionSettings->setText(QApplication::translate("vulkanCapsViewerClass", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        actionSettings->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Application settings", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("vulkanCapsViewerClass", "About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Application information", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("vulkanCapsViewerClass", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Close the application", 0));
#endif // QT_NO_TOOLTIP
        actionSaveReport->setText(QApplication::translate("vulkanCapsViewerClass", "Save", 0));
        actionSaveReport->setIconText(QApplication::translate("vulkanCapsViewerClass", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSaveReport->setToolTip(QApplication::translate("vulkanCapsViewerClass", "Save current device info to disk", 0));
#endif // QT_NO_TOOLTIP
        toolButtonUpload->setText(QApplication::translate("vulkanCapsViewerClass", "Upload", 0));
        toolButtonSave->setText(QApplication::translate("vulkanCapsViewerClass", "Save", 0));
        toolButtonOnlineDevice->setText(QApplication::translate("vulkanCapsViewerClass", "Device", 0));
        toolButtonOnlineDataBase->setText(QApplication::translate("vulkanCapsViewerClass", "Database", 0));
        toolButtonSettings->setText(QApplication::translate("vulkanCapsViewerClass", "Settings", 0));
        toolButtonAbout->setText(QApplication::translate("vulkanCapsViewerClass", "About", 0));
        toolButtonExit->setText(QApplication::translate("vulkanCapsViewerClass", "Exit", 0));
        label->setText(QString());
        reportForLabel->setText(QApplication::translate("vulkanCapsViewerClass", "Report for ", 0));
        labelDevicePresent->setText(QApplication::translate("vulkanCapsViewerClass", "Connecting to database...", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetDeviceProperties->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("vulkanCapsViewerClass", "value", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("vulkanCapsViewerClass", "key", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_6), QApplication::translate("vulkanCapsViewerClass", "Device", 0));
        filterLabel_2->setText(QApplication::translate("vulkanCapsViewerClass", "Filter :", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_3), QApplication::translate("vulkanCapsViewerClass", "Features", 0));
        filterLabel->setText(QApplication::translate("vulkanCapsViewerClass", "Filter :", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tabDeviceLimits), QApplication::translate("vulkanCapsViewerClass", "Limits", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetDeviceExtensions->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("vulkanCapsViewerClass", "Version", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("vulkanCapsViewerClass", "Name", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab), QApplication::translate("vulkanCapsViewerClass", "Extensions", 0));
        filterLabel_3->setText(QApplication::translate("vulkanCapsViewerClass", "Filter :", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_11), QApplication::translate("vulkanCapsViewerClass", "Formats", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidgetDeviceLayers->headerItem();
        ___qtreewidgetitem2->setText(4, QApplication::translate("vulkanCapsViewerClass", "Description", 0));
        ___qtreewidgetitem2->setText(3, QApplication::translate("vulkanCapsViewerClass", "Extensioncount", 0));
        ___qtreewidgetitem2->setText(2, QApplication::translate("vulkanCapsViewerClass", "Impementation", 0));
        ___qtreewidgetitem2->setText(1, QApplication::translate("vulkanCapsViewerClass", "Specification", 0));
        ___qtreewidgetitem2->setText(0, QApplication::translate("vulkanCapsViewerClass", "Name", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_9), QApplication::translate("vulkanCapsViewerClass", "Layers", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidgetQueues->headerItem();
        ___qtreewidgetitem3->setText(1, QApplication::translate("vulkanCapsViewerClass", "value", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("vulkanCapsViewerClass", "key", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_12), QApplication::translate("vulkanCapsViewerClass", "Queues", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidgetDeviceMemory->headerItem();
        ___qtreewidgetitem4->setText(1, QApplication::translate("vulkanCapsViewerClass", "value", 0));
        ___qtreewidgetitem4->setText(0, QApplication::translate("vulkanCapsViewerClass", "key", 0));
        tabWidgetDevice->setTabText(tabWidgetDevice->indexOf(tab_2), QApplication::translate("vulkanCapsViewerClass", "Memory", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDevice), QApplication::translate("vulkanCapsViewerClass", "Your device", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidgetGlobalLayers->headerItem();
        ___qtreewidgetitem5->setText(4, QApplication::translate("vulkanCapsViewerClass", "Description", 0));
        ___qtreewidgetitem5->setText(3, QApplication::translate("vulkanCapsViewerClass", "Extensioncount", 0));
        ___qtreewidgetitem5->setText(2, QApplication::translate("vulkanCapsViewerClass", "Impementation", 0));
        ___qtreewidgetitem5->setText(1, QApplication::translate("vulkanCapsViewerClass", "Specification", 0));
        ___qtreewidgetitem5->setText(0, QApplication::translate("vulkanCapsViewerClass", "Name", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabVulkanLayers), QApplication::translate("vulkanCapsViewerClass", "Layers", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidgetGlobalExtenssions->headerItem();
        ___qtreewidgetitem6->setText(1, QApplication::translate("vulkanCapsViewerClass", "Version", 0));
        ___qtreewidgetitem6->setText(0, QApplication::translate("vulkanCapsViewerClass", "Name", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabVulkanExtensions), QApplication::translate("vulkanCapsViewerClass", "Extensions", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("vulkanCapsViewerClass", "Vulkan", 0));
    } // retranslateUi

};

namespace Ui {
    class vulkanCapsViewerClass: public Ui_vulkanCapsViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VULKANCAPSVIEWER_H
