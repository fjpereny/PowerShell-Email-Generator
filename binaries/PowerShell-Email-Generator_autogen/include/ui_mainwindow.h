/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionAbout;
    QAction *actionGenerate_PowerShell_Script;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *projectNameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *gateLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *gateDueLineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *emailSubject;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *attachmentPathLineEdit;
    QPushButton *selectFolderButton1;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *attachment2PathLineEdit;
    QPushButton *selectFolderButton2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLineEdit *attachment3PathLineEdit;
    QPushButton *selectFolderButton3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QLineEdit *attachment4PathLineEdit;
    QPushButton *selectFolderButton4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *attachment5PathLineEdit;
    QPushButton *selectFolderButton5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QPushButton *projectNameButton;
    QPushButton *projectGateButton;
    QPushButton *gateDueButton;
    QPushButton *taskButton;
    QPushButton *ownerButton;
    QPushButton *ownerEmailButton;
    QPushButton *managerButton;
    QPushButton *managerEmailButton;
    QPushButton *statusButton;
    QPushButton *dueDateButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QPlainTextEdit *emailBody;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    QDateEdit *todayEdit;
    QLabel *label_13;
    QSpinBox *lateTasksSpinBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *generateButton;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1161, 798);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionGenerate_PowerShell_Script = new QAction(MainWindow);
        actionGenerate_PowerShell_Script->setObjectName(QString::fromUtf8("actionGenerate_PowerShell_Script"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_13 = new QHBoxLayout(centralwidget);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setPointSize(16);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_11);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        projectNameLineEdit = new QLineEdit(centralwidget);
        projectNameLineEdit->setObjectName(QString::fromUtf8("projectNameLineEdit"));

        horizontalLayout_2->addWidget(projectNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        gateLineEdit = new QLineEdit(centralwidget);
        gateLineEdit->setObjectName(QString::fromUtf8("gateLineEdit"));

        horizontalLayout_3->addWidget(gateLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        gateDueLineEdit = new QLineEdit(centralwidget);
        gateDueLineEdit->setObjectName(QString::fromUtf8("gateDueLineEdit"));

        horizontalLayout_4->addWidget(gateDueLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(39);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        emailSubject = new QLineEdit(centralwidget);
        emailSubject->setObjectName(QString::fromUtf8("emailSubject"));

        horizontalLayout_5->addWidget(emailSubject);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font1;
        font1.setPointSize(12);
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_17);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        attachmentPathLineEdit = new QLineEdit(centralwidget);
        attachmentPathLineEdit->setObjectName(QString::fromUtf8("attachmentPathLineEdit"));

        horizontalLayout_8->addWidget(attachmentPathLineEdit);

        selectFolderButton1 = new QPushButton(centralwidget);
        selectFolderButton1->setObjectName(QString::fromUtf8("selectFolderButton1"));

        horizontalLayout_8->addWidget(selectFolderButton1);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(7);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        attachment2PathLineEdit = new QLineEdit(centralwidget);
        attachment2PathLineEdit->setObjectName(QString::fromUtf8("attachment2PathLineEdit"));

        horizontalLayout_9->addWidget(attachment2PathLineEdit);

        selectFolderButton2 = new QPushButton(centralwidget);
        selectFolderButton2->setObjectName(QString::fromUtf8("selectFolderButton2"));

        horizontalLayout_9->addWidget(selectFolderButton2);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(7);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_10->addWidget(label_14);

        attachment3PathLineEdit = new QLineEdit(centralwidget);
        attachment3PathLineEdit->setObjectName(QString::fromUtf8("attachment3PathLineEdit"));

        horizontalLayout_10->addWidget(attachment3PathLineEdit);

        selectFolderButton3 = new QPushButton(centralwidget);
        selectFolderButton3->setObjectName(QString::fromUtf8("selectFolderButton3"));

        horizontalLayout_10->addWidget(selectFolderButton3);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(7);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_11->addWidget(label_15);

        attachment4PathLineEdit = new QLineEdit(centralwidget);
        attachment4PathLineEdit->setObjectName(QString::fromUtf8("attachment4PathLineEdit"));

        horizontalLayout_11->addWidget(attachment4PathLineEdit);

        selectFolderButton4 = new QPushButton(centralwidget);
        selectFolderButton4->setObjectName(QString::fromUtf8("selectFolderButton4"));

        horizontalLayout_11->addWidget(selectFolderButton4);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(7);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_12->addWidget(label_16);

        attachment5PathLineEdit = new QLineEdit(centralwidget);
        attachment5PathLineEdit->setObjectName(QString::fromUtf8("attachment5PathLineEdit"));

        horizontalLayout_12->addWidget(attachment5PathLineEdit);

        selectFolderButton5 = new QPushButton(centralwidget);
        selectFolderButton5->setObjectName(QString::fromUtf8("selectFolderButton5"));

        horizontalLayout_12->addWidget(selectFolderButton5);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        projectNameButton = new QPushButton(centralwidget);
        projectNameButton->setObjectName(QString::fromUtf8("projectNameButton"));
        projectNameButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(projectNameButton);

        projectGateButton = new QPushButton(centralwidget);
        projectGateButton->setObjectName(QString::fromUtf8("projectGateButton"));
        projectGateButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(projectGateButton);

        gateDueButton = new QPushButton(centralwidget);
        gateDueButton->setObjectName(QString::fromUtf8("gateDueButton"));
        gateDueButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(gateDueButton);

        taskButton = new QPushButton(centralwidget);
        taskButton->setObjectName(QString::fromUtf8("taskButton"));
        taskButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(taskButton);

        ownerButton = new QPushButton(centralwidget);
        ownerButton->setObjectName(QString::fromUtf8("ownerButton"));
        ownerButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(ownerButton);

        ownerEmailButton = new QPushButton(centralwidget);
        ownerEmailButton->setObjectName(QString::fromUtf8("ownerEmailButton"));
        ownerEmailButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(ownerEmailButton);

        managerButton = new QPushButton(centralwidget);
        managerButton->setObjectName(QString::fromUtf8("managerButton"));
        managerButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(managerButton);

        managerEmailButton = new QPushButton(centralwidget);
        managerEmailButton->setObjectName(QString::fromUtf8("managerEmailButton"));
        managerEmailButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(managerEmailButton);

        statusButton = new QPushButton(centralwidget);
        statusButton->setObjectName(QString::fromUtf8("statusButton"));
        statusButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(statusButton);

        dueDateButton = new QPushButton(centralwidget);
        dueDateButton->setObjectName(QString::fromUtf8("dueDateButton"));
        dueDateButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(dueDateButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        emailBody = new QPlainTextEdit(centralwidget);
        emailBody->setObjectName(QString::fromUtf8("emailBody"));

        verticalLayout_3->addWidget(emailBody);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout_13->addLayout(verticalLayout_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        todayEdit = new QDateEdit(centralwidget);
        todayEdit->setObjectName(QString::fromUtf8("todayEdit"));
        todayEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(todayEdit);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_7->addWidget(label_13);

        lateTasksSpinBox = new QSpinBox(centralwidget);
        lateTasksSpinBox->setObjectName(QString::fromUtf8("lateTasksSpinBox"));
        lateTasksSpinBox->setReadOnly(true);

        horizontalLayout_7->addWidget(lateTasksSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_7->addLayout(horizontalLayout_7);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(true);
        tableWidget->setRowCount(1);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_6->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));

        horizontalLayout->addWidget(generateButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_8->addLayout(verticalLayout_6);


        horizontalLayout_13->addLayout(verticalLayout_8);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1161, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionGenerate_PowerShell_Script);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PowerShell Email Generator", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionGenerate_PowerShell_Script->setText(QCoreApplication::translate("MainWindow", "Generate PowerShell Script", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Project Information", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Project Name:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Project Gate:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Gate Due Date", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Email Setup", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Subject", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Email Attachment Folders", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Folder 1", nullptr));
        selectFolderButton1->setText(QCoreApplication::translate("MainWindow", "Select Folder", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Folder 2", nullptr));
        selectFolderButton2->setText(QCoreApplication::translate("MainWindow", "Select Folder", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Folder 3", nullptr));
        selectFolderButton3->setText(QCoreApplication::translate("MainWindow", "Select Folder", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Folder 4", nullptr));
        selectFolderButton4->setText(QCoreApplication::translate("MainWindow", "Select Folder", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Folder 5", nullptr));
        selectFolderButton5->setText(QCoreApplication::translate("MainWindow", "Select Folder", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Text Variables", nullptr));
        projectNameButton->setText(QCoreApplication::translate("MainWindow", "Project Name", nullptr));
        projectGateButton->setText(QCoreApplication::translate("MainWindow", "Project Gate", nullptr));
        gateDueButton->setText(QCoreApplication::translate("MainWindow", "Gate Due Date", nullptr));
        taskButton->setText(QCoreApplication::translate("MainWindow", "Task", nullptr));
        ownerButton->setText(QCoreApplication::translate("MainWindow", "Owner", nullptr));
        ownerEmailButton->setText(QCoreApplication::translate("MainWindow", "Owner Email", nullptr));
        managerButton->setText(QCoreApplication::translate("MainWindow", "Manager", nullptr));
        managerEmailButton->setText(QCoreApplication::translate("MainWindow", "Manager Email", nullptr));
        statusButton->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        dueDateButton->setText(QCoreApplication::translate("MainWindow", "Due Date", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Body", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Task Data Table", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Today's Date", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Late Tasks", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Task", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Owner", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Owner Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Manager", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Manager Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Due Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Update Day(s)", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate PowerShell Script", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Generate and Run PowerShell Script", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H