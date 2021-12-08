#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include "tinyxml2.h"

#include <iostream>
#include <set>
#include <vector>
#include <QClipboard>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QDate>
#include <QKeyEvent>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      calculate_on(new bool)
{
    ui->setupUi(this);

    add_date_edit(0, 5);
    add_status_combo(0, 6);
    add_day_checkBox(0, 7);
    add_folder_checkBox(0, 8);

    ui->todayEdit->setDate(QDate::currentDate());
    ui->todayEdit->setButtonSymbols(QDateEdit::NoButtons);

    ui->lastUpdateDateEdit->setDate(QDate::currentDate());
    ui->lastUpdateDateEdit->setDisplayFormat("MMM-dd-yyyy");
    ui->lastUpdateDateEdit->setButtonSymbols(QDateEdit::NoButtons);

    ui->incompleteSpinBox->setButtonSymbols(QSpinBox::NoButtons);
    ui->lateTasksSpinBox->setButtonSymbols(QSpinBox::NoButtons);
    ui->completeSpinBox->setButtonSymbols(QSpinBox::NoButtons);

    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();

    *calculate_on = true;
}


MainWindow::~MainWindow()
{
    delete ui;
}


// GUI Table Widget
void MainWindow::add_date_edit(int cell_row, int cell_col)
{
    QFrame *dateFrame = new QFrame;
    ui->tableWidget->setCellWidget(cell_row, cell_col, dateFrame);
    QLayout *dateLayout = new QVBoxLayout;
    dateFrame->setLayout(dateLayout);
    dateLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QDateEdit *dateEdit = new QDateEdit(dateFrame);
    dateLayout->addWidget(dateEdit);
    dateEdit->setObjectName("dateEdit");
    dateEdit->setDisplayFormat("MMM-dd-yyyy");
    dateEdit->setDate(QDate::currentDate());
}

void MainWindow::add_status_combo(int cell_row, int cell_col)
{
    QFrame *statusFrame = new QFrame;
    ui->tableWidget->setCellWidget(cell_row, cell_col, statusFrame);
    QLayout *statusLayout = new QVBoxLayout;
    statusFrame->setLayout(statusLayout);
    statusLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QComboBox *statusCombo = new QComboBox(statusFrame);
    statusLayout->addWidget(statusCombo);
    statusCombo->setObjectName("statusCombo");
    statusCombo->addItem("Incomplete");
    statusCombo->addItem("Complete");
    QObject::connect(statusCombo,
                     SIGNAL( currentTextChanged(QString) ),
                     this,
                     SLOT( status_changed() ));
    ui->incompleteSpinBox->setValue(ui->incompleteSpinBox->value() + 1);
}

void MainWindow::add_day_checkBox(int cell_row, int cell_col)
{
    QFrame *dayCheckFrame = new QFrame;
    ui->tableWidget->setCellWidget(cell_row, cell_col, dayCheckFrame);
    QLayout *dayCheckLayout = new QVBoxLayout;
    dayCheckFrame->setLayout(dayCheckLayout);
    dayCheckLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QCheckBox *cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Mon");
    cb->setObjectName("mon");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Tue");
    cb->setObjectName("tue");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Wed");
    cb->setObjectName("wed");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Thu");
    cb->setObjectName("thu");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Fri");
    cb->setObjectName("fri");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Sat");
    cb->setObjectName("sat");
    cb = new QCheckBox();
    dayCheckLayout->addWidget(cb);
    cb->setText("Sun");
    cb->setObjectName("sun");
}

void MainWindow::add_folder_checkBox(int cell_row, int cell_col)
{
    QCheckBox *cb;
    QFrame *folderCheckFrame = new QFrame;
    ui->tableWidget->setCellWidget(cell_row, cell_col, folderCheckFrame);
    QLayout *folderCheckLayout = new QVBoxLayout;
    folderCheckFrame->setLayout(folderCheckLayout);
    folderCheckLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    cb = new QCheckBox();
    folderCheckLayout->addWidget(cb);
    cb->setText("Folder 1");
    cb->setObjectName("folder_1");
    cb = new QCheckBox();
    folderCheckLayout->addWidget(cb);
    cb->setText("Folder 2");
    cb->setObjectName("folder_2");
    cb = new QCheckBox();
    folderCheckLayout->addWidget(cb);
    cb->setText("Folder 3");
    cb->setObjectName("folder_3");
    cb = new QCheckBox();
    folderCheckLayout->addWidget(cb);
    cb->setText("Folder 4");
    cb->setObjectName("folder_4");
    cb = new QCheckBox();
    folderCheckLayout->addWidget(cb);
    cb->setText("Folder 5");
    cb->setObjectName("folder_5");
}

void MainWindow::on_actionOpen_triggered()
{
    *calculate_on = false;

    QString file_path = QFileDialog::getOpenFileName(this,
                                                     "Open File",
                                                     QDir::toNativeSeparators(QDir::currentPath()),
                                                     "XML Files (*.xml)\n"
                                                     "All Files (*.*)"
                                                     );

    if (file_path.isEmpty())
        return;

    tinyxml2::XMLDocument xmlDoc;
    xmlDoc.LoadFile(file_path.toStdString().c_str());

    tinyxml2::XMLNode *root = xmlDoc.FirstChild();

    tinyxml2::XMLElement *element_1, *element_2;
    if ( (element_1 = root->FirstChildElement("save_date")) )
    {
        QStringList date = QString(element_1->GetText()).split('.');
        int year = date[0].toInt();
        int month = date[1].toInt();
        int day = date[2].toInt();
        ui->lastUpdateDateEdit->setDate(QDate(year, month, day));
    }
    else
    {
        ui->lastUpdateDateEdit->setDate(QDate::currentDate());
    }


    if ( (element_1 = root->FirstChildElement("project")) )
        if ( (element_2 = element_1->FirstChildElement("project_name")) )
        ui->projectNameLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("project_gate")) )
        ui->gateLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("project_gate_due")) )
        ui->gateDueLineEdit->setText(element_2->GetText());

    if ( (element_1 = root->FirstChildElement("email")) )
        if ( (element_2 = element_1->FirstChildElement("subject")) )
        ui->emailSubject->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("body")) )
        ui->emailBody->setPlainText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_path_1")) )
        ui->attachmentPathLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_path_2")) )
        ui->attachment2PathLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_path_3")) )
        ui->attachment3PathLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_path_4")) )
        ui->attachment4PathLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_path_5")) )
        ui->attachment5PathLineEdit->setText(element_2->GetText());
        if ( (element_2 = element_1->FirstChildElement("folder_1_enabled")) )
        {
            if (QString(element_2->GetText()) == QString("checked"))
                ui->folder1CB->setChecked(true);
            else
                ui->folder1CB->setChecked(false);
        }
        if ( (element_2 = element_1->FirstChildElement("folder_2_enabled")) )
        {
            if (QString(element_2->GetText()) == QString("checked"))
                ui->folder2CB->setChecked(true);
            else
                ui->folder2CB->setChecked(false);
        }
        if ( (element_2 = element_1->FirstChildElement("folder_3_enabled")) )
        {
            if (QString(element_2->GetText()) == QString("checked"))
                ui->folder3CB->setChecked(true);
            else
                ui->folder3CB->setChecked(false);
        }
        if ( (element_2 = element_1->FirstChildElement("folder_4_enabled")) )
        {
            if (QString(element_2->GetText()) == QString("checked"))
                ui->folder4CB->setChecked(true);
            else
                ui->folder4CB->setChecked(false);
        }
        if ( (element_2 = element_1->FirstChildElement("folder_5_enabled")) )
        {
            if (QString(element_2->GetText()) == QString("checked"))
                ui->folder5CB->setChecked(true);
            else
                ui->folder5CB->setChecked(false);
        }



    tinyxml2::XMLElement *table_element = root->FirstChildElement("task_table");
    tinyxml2::XMLElement *row_element;
    int table_row = 0;
    QTableWidgetItem *cell_0_0 = new QTableWidgetItem();
    ui->tableWidget->setItem(0, 0, cell_0_0);
    ui->tableWidget->setCurrentCell(0, 0);
    ui->tableWidget->setCurrentItem(ui->tableWidget->item(0, 0));
    for (row_element = table_element->FirstChildElement();
         row_element != NULL;
         row_element = row_element->NextSiblingElement())
    {
        int last_index = ui->tableWidget->rowCount() - 1;
        if (last_index < table_row)
        {
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
            add_date_edit(table_row, 5);
            add_status_combo(table_row, 6);
            add_day_checkBox(table_row, 7);
            add_folder_checkBox(table_row, 8);
        }

        QTableWidgetItem *item;
        QString task = row_element->FirstChildElement("task")->GetText();
        if (!(item = ui->tableWidget->item(table_row, 0)) )
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(table_row, 0, item);
        }
        item->setText(task);
        ui->tableWidget->item(table_row, 0)->setText(task);
        QString owner = row_element->FirstChildElement("owner")->GetText();
        if (!(item = ui->tableWidget->item(table_row, 1)) )
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(table_row, 1, item);
        }
        item->setText(owner);
        QString owner_email = row_element->FirstChildElement("owner_email")->GetText();
        if (!(item = ui->tableWidget->item(table_row, 2)) )
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(table_row, 2, item);
        }
        item->setText(owner_email);
        QString manager = row_element->FirstChildElement("manager")->GetText();
        if (!(item = ui->tableWidget->item(table_row, 3)) )
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(table_row, 3, item);
        }
        item->setText(manager);
        QString manager_email = row_element->FirstChildElement("manager_email")->GetText();
        if (!(item = ui->tableWidget->item(table_row, 4)) )
        {
            item = new QTableWidgetItem();
            ui->tableWidget->setItem(table_row, 4, item);
        }
        item->setText(manager_email);


        QString date = row_element->FirstChildElement("due_date")->GetText();
        QStringList date_list = date.split('.');
        int year = date_list[0].toInt();
        int month = date_list[1].toInt();
        int day = date_list[2].toInt();
        QWidget *dateFrame = ui->tableWidget->cellWidget(table_row, 5);
        QDateEdit *dateEdit = dateFrame->findChild<QDateEdit*>("dateEdit");
        dateEdit->setDate(QDate(year, month, day));


        tinyxml2::XMLElement *days = row_element->FirstChildElement("days");
        tinyxml2::XMLElement *mon = days->FirstChildElement("mon");
        tinyxml2::XMLElement *tue = days->FirstChildElement("tue");
        tinyxml2::XMLElement *wed = days->FirstChildElement("wed");
        tinyxml2::XMLElement *thu = days->FirstChildElement("thu");
        tinyxml2::XMLElement *fri = days->FirstChildElement("fri");
        tinyxml2::XMLElement *sat = days->FirstChildElement("sat");
        tinyxml2::XMLElement *sun = days->FirstChildElement("sun");
        bool mon_checked = (QString(mon->GetText()) == QString("checked"));
        bool tue_checked = (QString(tue->GetText()) == QString("checked"));
        bool wed_checked = (QString(wed->GetText()) == QString("checked"));
        bool thu_checked = (QString(thu->GetText()) == QString("checked"));
        bool fri_checked = (QString(fri->GetText()) == QString("checked"));
        bool sat_checked = (QString(sat->GetText()) == QString("checked"));
        bool sun_checked = (QString(sun->GetText()) == QString("checked"));

        QWidget *dayFrame = ui->tableWidget->cellWidget(table_row, 7);
        QCheckBox *monCB = dayFrame->findChild<QCheckBox*>("mon");
        if (mon_checked)
            monCB->setChecked(true);
        QCheckBox *tueCB = dayFrame->findChild<QCheckBox*>("tue");
        if (tue_checked)
            tueCB->setChecked(true);
        QCheckBox *wedCB = dayFrame->findChild<QCheckBox*>("wed");
        if (wed_checked)
            wedCB->setChecked(true);
        QCheckBox *thuCB = dayFrame->findChild<QCheckBox*>("thu");
        if (thu_checked)
            thuCB->setChecked(true);
        QCheckBox *friCB = dayFrame->findChild<QCheckBox*>("fri");
        if (fri_checked)
            friCB->setChecked(true);
        QCheckBox *satCB = dayFrame->findChild<QCheckBox*>("sat");
        if (sat_checked)
            satCB->setChecked(true);
        QCheckBox *sunCB = dayFrame->findChild<QCheckBox*>("sun");
        if (sun_checked)
            sunCB->setChecked(true);


        tinyxml2::XMLElement *attachments = row_element->FirstChildElement("attachments");
        tinyxml2::XMLElement *folder_1 = attachments->FirstChildElement("folder_1");
        tinyxml2::XMLElement *folder_2 = attachments->FirstChildElement("folder_2");
        tinyxml2::XMLElement *folder_3 = attachments->FirstChildElement("folder_3");
        tinyxml2::XMLElement *folder_4 = attachments->FirstChildElement("folder_4");
        tinyxml2::XMLElement *folder_5 = attachments->FirstChildElement("folder_5");
        bool fold_1_checked = (QString(folder_1->GetText()) == QString("checked"));
        bool fold_2_checked = (QString(folder_2->GetText()) == QString("checked"));
        bool fold_3_checked = (QString(folder_3->GetText()) == QString("checked"));
        bool fold_4_checked = (QString(folder_4->GetText()) == QString("checked"));
        bool fold_5_checked = (QString(folder_5->GetText()) == QString("checked"));

        QWidget *attachmentFrame = ui->tableWidget->cellWidget(table_row, 8);
        QCheckBox *fold_1_CB = attachmentFrame->findChild<QCheckBox*>("folder_1");
        if (fold_1_checked)
            fold_1_CB->setChecked(true);
        QCheckBox *fold_2_CB = attachmentFrame->findChild<QCheckBox*>("folder_2");
        if (fold_2_checked)
            fold_2_CB->setChecked(true);
        QCheckBox *fold_3_CB = attachmentFrame->findChild<QCheckBox*>("folder_3");
        if (fold_3_checked)
            fold_3_CB->setChecked(true);
        QCheckBox *fold_4_CB = attachmentFrame->findChild<QCheckBox*>("folder_4");
        if (fold_4_checked)
            fold_4_CB->setChecked(true);
        QCheckBox *fold_5_CB = attachmentFrame->findChild<QCheckBox*>("folder_5");
        if (fold_5_checked)
            fold_5_CB->setChecked(true);

        ++table_row;
    }

    ui->projectNameLineEdit->setFocus();
    *calculate_on = true;
}

bool MainWindow::on_actionSave_triggered()
{
    tinyxml2::XMLDocument *xmlDoc = create_XML();

    QString save_file_path = QFileDialog::getSaveFileName(this,
                                                "Save File",
                                                QDir::toNativeSeparators(QDir::currentPath()),
                                                "XML Files (*.xml)\n"
                                                "All Files (*.*)");
    if (save_file_path.isEmpty())
        return false;

    if (!save_file_path.contains(".xml"))
        save_file_path += ".xml";

    xmlDoc->SaveFile(save_file_path.toStdString().c_str());

    delete xmlDoc;
    xmlDoc = nullptr;
    return true;
}


void MainWindow::on_actionGenerate_PowerShell_Script_triggered()
{
    generate_script();
}

void MainWindow::on_actionClose_triggered()
{
    close();
}


tinyxml2::XMLDocument* MainWindow::create_XML()
{
    tinyxml2::XMLDocument *xmlDoc = new tinyxml2::XMLDocument;
    tinyxml2::XMLNode *root = xmlDoc->NewElement("root");
    xmlDoc->InsertFirstChild(root);

    tinyxml2::XMLElement *save_date = xmlDoc->NewElement("save_date");
    root->InsertEndChild(save_date);
        QDate current_date = QDate::currentDate();
        QString current_date_s = current_date.toString("yyyy.MM.dd");
        save_date->SetText(current_date_s.toStdString().c_str());


    tinyxml2::XMLElement *project = xmlDoc->NewElement("project");
    root->InsertEndChild(project);
        tinyxml2::XMLElement *project_name = xmlDoc->NewElement("project_name");
        tinyxml2::XMLElement *project_gate = xmlDoc->NewElement("project_gate");
        tinyxml2::XMLElement *project_gate_due = xmlDoc->NewElement("project_gate_due");
        tinyxml2::XMLElement *incomplete_tasks = xmlDoc->NewElement("incomplete_tasks");
        tinyxml2::XMLElement *late_tasks = xmlDoc->NewElement("late_tasks");
        tinyxml2::XMLElement *complete_tasks = xmlDoc->NewElement("complete_tasks");
        project_name->SetText(ui->projectNameLineEdit->text().toStdString().c_str());
        project_gate->SetText(ui->gateLineEdit->text().toStdString().c_str());
        project_gate_due->SetText(ui->gateDueLineEdit->text().toStdString().c_str());
        qlonglong last_update_qint = ui->lastUpdateDateEdit->date().toJulianDay();
        QString last_update_str = QString::number(last_update_qint);
        QString temp_string;
        temp_string = QString::number(ui->incompleteSpinBox->value());
        incomplete_tasks->SetText(temp_string.toStdString().c_str());
        temp_string = QString::number(ui->lateTasksSpinBox->value());
        late_tasks->SetText(temp_string.toStdString().c_str());
        temp_string = QString::number(ui->completeSpinBox->value());
        complete_tasks->SetText(temp_string.toStdString().c_str());
        project->InsertEndChild(project_name);
        project->InsertEndChild(project_gate);
        project->InsertEndChild(project_gate_due);
        project->InsertEndChild(incomplete_tasks);
        project->InsertEndChild(late_tasks);
        project->InsertEndChild(complete_tasks);


    tinyxml2::XMLElement *email = xmlDoc->NewElement("email");
    root->InsertEndChild(email);
        tinyxml2::XMLElement *subject = xmlDoc->NewElement("subject");
        tinyxml2::XMLElement *body = xmlDoc->NewElement("body");
        email->InsertEndChild(subject);
        email->InsertEndChild(body);
        subject->SetText(ui->emailSubject->text().toStdString().c_str());
        body->SetText(ui->emailBody->toPlainText().toStdString().c_str());

        tinyxml2::XMLElement *folder_1 = xmlDoc->NewElement("folder_path_1");
        tinyxml2::XMLElement *folder_2 = xmlDoc->NewElement("folder_path_2");
        tinyxml2::XMLElement *folder_3 = xmlDoc->NewElement("folder_path_3");
        tinyxml2::XMLElement *folder_4 = xmlDoc->NewElement("folder_path_4");
        tinyxml2::XMLElement *folder_5 = xmlDoc->NewElement("folder_path_5");
        folder_1->SetText(ui->attachmentPathLineEdit->text().toStdString().c_str());
        folder_2->SetText(ui->attachment2PathLineEdit->text().toStdString().c_str());
        folder_3->SetText(ui->attachment3PathLineEdit->text().toStdString().c_str());
        folder_4->SetText(ui->attachment4PathLineEdit->text().toStdString().c_str());
        folder_5->SetText(ui->attachment5PathLineEdit->text().toStdString().c_str());
        email->InsertEndChild(folder_1);
        email->InsertEndChild(folder_2);
        email->InsertEndChild(folder_3);
        email->InsertEndChild(folder_4);
        email->InsertEndChild(folder_5);

        tinyxml2::XMLElement *folder_1_enabled = xmlDoc->NewElement("folder_1_enabled");
        tinyxml2::XMLElement *folder_2_enabled = xmlDoc->NewElement("folder_2_enabled");
        tinyxml2::XMLElement *folder_3_enabled = xmlDoc->NewElement("folder_3_enabled");
        tinyxml2::XMLElement *folder_4_enabled = xmlDoc->NewElement("folder_4_enabled");
        tinyxml2::XMLElement *folder_5_enabled = xmlDoc->NewElement("folder_5_enabled");
        if(ui->folder1CB->isChecked())
            folder_1_enabled->SetText("checked");
        else
            folder_1_enabled->SetText("unchecked");
        if(ui->folder2CB->isChecked())
            folder_2_enabled->SetText("checked");
        else
            folder_2_enabled->SetText("unchecked");
        if(ui->folder3CB->isChecked())
            folder_3_enabled->SetText("checked");
        else
            folder_3_enabled->SetText("unchecked");
        if(ui->folder4CB->isChecked())
            folder_4_enabled->SetText("checked");
        else
            folder_4_enabled->SetText("unchecked");
        if(ui->folder5CB->isChecked())
            folder_5_enabled->SetText("checked");
        else
            folder_5_enabled->SetText("unchecked");
        email->InsertEndChild(folder_1_enabled);
        email->InsertEndChild(folder_2_enabled);
        email->InsertEndChild(folder_3_enabled);
        email->InsertEndChild(folder_4_enabled);
        email->InsertEndChild(folder_5_enabled);



    tinyxml2::XMLElement *task_table = xmlDoc->NewElement("task_table");
    root->InsertEndChild(task_table);
        for (int row=0; row<ui->tableWidget->rowCount(); ++row)
        {
            QString row_name = "row_" + QString::number(row);
            tinyxml2::XMLElement *new_row = xmlDoc->NewElement(row_name.toStdString().c_str());
            task_table->InsertEndChild(new_row);

            QStringList col_names = {"task", "owner", "owner_email",
                                       "manager", "manager_email",
                                       "due_date", "status", "days", "attachments"};
            for (int col=0; col<ui->tableWidget->columnCount(); ++col)
            {
                QString col_name = col_names.at(col);
                tinyxml2::XMLElement *new_col = xmlDoc->NewElement(col_name.toStdString().c_str());
                new_row->InsertEndChild(new_col);

                if (col == 5)
                {
                    QWidget *frameWidget = ui->tableWidget->cellWidget(row, col);
                    QDateEdit *dateEdit = frameWidget->findChild<QDateEdit*>("dateEdit");
                    QString year = QString::number(dateEdit->date().year());
                    QString month = QString::number(dateEdit->date().month());
                    QString day = QString::number(dateEdit->date().day());
                    QString date = year + "." + month + "." + day;
                    new_col->SetText(date.toStdString().c_str());
                }

                else if (col == 6)
                {
                    QWidget *frameWidget = ui->tableWidget->cellWidget(row, col);
                    QComboBox *statusCombo = frameWidget->findChild<QComboBox*>("statusCombo");
                    new_col->SetText(statusCombo->currentText().toStdString().c_str());
                }

                else if (col == 7)
                {
                    QWidget *frameWidget = ui->tableWidget->cellWidget(row, col);
                    QObjectList objects = frameWidget->children();
                    QCheckBox *cb;
                    for (auto object : objects)
                    {
                        if (object->objectName() != "")
                        {
                            tinyxml2::XMLElement *day = xmlDoc->NewElement(object->objectName().toStdString().c_str());
                            cb = frameWidget->findChild<QCheckBox*>(object->objectName());
                            if (cb->isChecked())
                                day->SetText("checked");
                            else
                                day->SetText("unchecked");

                            new_col->InsertEndChild(day);
                        }
                    }
                }


                else if (col == 8)
                {
                    QWidget *frameWidget = ui->tableWidget->cellWidget(row, col);
                    QObjectList objects = frameWidget->children();
                    QCheckBox *cb;
                    for (auto object : objects)
                    {
                        if (object->objectName() != "")
                        {
                            tinyxml2::XMLElement *day = xmlDoc->NewElement(object->objectName().toStdString().c_str());
                            cb = frameWidget->findChild<QCheckBox*>(object->objectName());
                            if (cb->isChecked())
                                day->SetText("checked");
                            else
                                day->SetText("unchecked");

                            new_col->InsertEndChild(day);
                        }
                    }
                }

                else if (ui->tableWidget->item(row, col))
                {
                    QString cell_text = ui->tableWidget->item(row, col)->text();
                    new_col->SetText(cell_text.toStdString().c_str());
                }
                else
                    new_col->SetText("");
            }
        }

    return xmlDoc;
}


void MainWindow::on_projectNameButton_clicked()
{
    QString tag = "[PROJECT NAME]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_projectGateButton_clicked()
{
    QString tag = "[PROJECT GATE]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_gateDueButton_clicked()
{
    QString tag = "[GATE DUE]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_taskButton_clicked()
{
    QString tag = "[TASK]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_ownerButton_clicked()
{
    QString tag = "[OWNER]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_ownerEmailButton_clicked()
{
    QString tag = "[OWNER EMAIL]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_managerButton_clicked()
{
    QString tag = "[MANAGER]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_managerEmailButton_clicked()
{
    QString tag = "[MANAGER EMAIL]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_statusButton_clicked()
{
    QString tag = "[STATUS]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_dueDateButton_clicked()
{
    QString tag = "[TASK DUE]";

    QList<QWidget*> children = this->findChildren<QWidget *>();
    QListIterator iterator = QListIterator(children);
    QWidget *widget;
    while (iterator.hasNext())
    {
        widget = iterator.next();
        if (QLineEdit *lineEdit = qobject_cast<QLineEdit*>(widget))
        {
            if (lineEdit->hasFocus())
                lineEdit->insert(tag);
        }
        if (QPlainTextEdit *plainText = qobject_cast<QPlainTextEdit*>(widget))
        {
            if (plainText->hasFocus())
                plainText->insertPlainText(tag);
        }
    }
}


void MainWindow::on_generateButton_clicked()
{
    generate_script();
}


QString MainWindow::create_script_header()
{
    QString header = "# Made By PowerShell Email Generator\n";
    header += "# --------------------------------------------------------------------------------------\n";
    header += "# PowerShell Email Generator\n";
    header += "# Copyright (C) 2021 Frank Pereny\n";
    header += "# https://github.com/fjpereny/PowerShell-Email-Generator\n";
    header += "#\n";
    header += "# This program is free software: you can redistribute it and/or modify it under the\n";
    header += "# terms of the GNU General Public License as published by the Free Software\n";
    header += "# Foundation, either version 3 of the License, or (at your option) any later version.\n";
    header += "\n";
    header += "# This program is distributed in the hope that it will be useful, but WITHOUT ANY\n";
    header += "# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n";
    header += "# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n";
    header += "# --------------------------------------------------------------------------------------\n";
    header += "#\n";
    header += "# Program: " + ui->projectNameLineEdit->text() + "\n";
    header += "# Created: " + ui->todayEdit->date().toString("dddd, MMMM dd, yyyy") + "\n";
    header += "\n";
    header += "Add-Type -assembly \"Microsoft.Office.Interop.Outlook\"\n";
    header += "$Outlook = New-Object -comobject Outlook.Application\n";
    return header;
}


QString MainWindow::createMailScript(QString to,
                                     QString cc,
                                     QString bcc,
                                     QString subject,
                                     QString body,
                                     QString attachments)
{
    QString script = "";
    script += "$Mail = $Outlook.CreateItem(0)\n";

    script += "$Mail.To = \"" + to + "\"\n";
    script += "$Mail.Cc = \"" + cc + "\"\n";
    script += "$Mail.Bcc = \"" + bcc + "\"\n";

    script += "$Mail.Subject = \"" + subject + "\"\n";
    script += "$Mail.Body = \"" + body + "\"\n";

    script += "$files = Get-ChildItem -Path \"" + attachments + "\" -File\n";
    script += "foreach($file in $files)\n";
    script += "{\n";
    script += "$Mail.Attachments.Add(\"" + attachments + "\" + $file)\n";
    script += "}\n";

    script += "$Mail.Send()\n";
    script += "\n";
    return script;
}


void MainWindow::generate_script()
{
    QString script = "";

    QString save_file_path = QFileDialog::getSaveFileName(this,
                                                          "Save PowerShell Script",
                                                          QDir::toNativeSeparators(QDir::currentPath()),
                                                          "PowerShell Script (*.ps1)");

    if (save_file_path.isEmpty())
        return;

    if (!save_file_path.contains(".ps1"))
        save_file_path += ".ps1";

    QString project_name = ui->projectNameLineEdit->text();
    QString project_gate = ui->gateLineEdit->text();
    QString gate_due = ui->gateDueLineEdit->text();

    QString attachments1 = ui->attachmentPathLineEdit->text();
    if (attachments1.back() != '/' && attachments1.back() != '\\')
        attachments1 += '/';
    attachments1 = QDir::toNativeSeparators(attachments1);
    QString attachments2 = ui->attachment2PathLineEdit->text();
    if (attachments2.back() != '/' && attachments2.back() != '\\')
        attachments2 += '/';
    attachments2 = QDir::toNativeSeparators(attachments2);
    QString attachments3 = ui->attachment3PathLineEdit->text();
    if (attachments3.back() != '/' && attachments3.back() != '\\')
        attachments3 += '/';
    attachments3 = QDir::toNativeSeparators(attachments3);
    QString attachments4 = ui->attachment4PathLineEdit->text();
    if (attachments4.back() != '/' && attachments4.back() != '\\')
        attachments4 += '/';
    attachments4 = QDir::toNativeSeparators(attachments4);
    QString attachments5 = ui->attachment5PathLineEdit->text();
    if (attachments5.back() != '/' && attachments5.back() != '\\')
        attachments5 += '/';
    attachments5 = QDir::toNativeSeparators(attachments5);

    QString subject;
    QString body;
    QString task;
    QString owner;
    QString owner_email;
    QString manager;
    QString manager_email;
    QString status;
    QString task_due;

    script += create_script_header();
//    for (int row=0; row<ui->tableWidget->rowCount(); ++row)
//    {
//        subject = ui->emailSubject->text();
//        body = ui->emailBody->toPlainText();

//        task = ui->tableWidget->item(row, 0)->text();
//        owner = ui->tableWidget->item(row, 1)->text();
//        owner_email = ui->tableWidget->item(row, 2)->text();
//        manager = ui->tableWidget->item(row, 3)->text();
//        manager_email = ui->tableWidget->item(row, 4)->text();
//        status = ui->tableWidget->item(row, 5)->text();
//        task_due = ui->tableWidget->item(row, 6)->text();

//        subject.replace("[PROJECT NAME]", project_name);
//        subject.replace("[PROJECT GATE]", project_gate);
//        subject.replace("[GATE DUE]", gate_due);
//        subject.replace("[TASK]", task);
//        subject.replace("[OWNER]", owner);
//        subject.replace("[OWNER EMAIL]", owner_email);
//        subject.replace("[MANAGER]", manager);
//        subject.replace("[MANAGER EMAIL]", manager_email);
//        subject.replace("[STATUS]", status);
//        subject.replace("[TASK DUE]", task_due);

//        body.replace("[PROJECT NAME]", project_name);
//        body.replace("[PROJECT GATE]", project_gate);
//        body.replace("[GATE DUE]", gate_due);
//        body.replace("[TASK]", task);
//        body.replace("[OWNER]", owner);
//        body.replace("[OWNER EMAIL]", owner_email);
//        body.replace("[MANAGER]", manager);
//        body.replace("[MANAGER EMAIL]", manager_email);
//        body.replace("[STATUS]", status);
//        body.replace("[TASK DUE]", task_due);

//        script += createMailScript(owner_email, manager_email, "", subject, body, "");

//    }

    QFile file(save_file_path);
    file.open(QFile::WriteOnly);
    if (file.isOpen())
    {
        QTextStream stream(&file);
        stream << script;
        file.close();
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (ui->tableWidget->hasFocus())
    {
        // Move to next cell down or add row on return
        if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        {
            QModelIndex current_index = ui->tableWidget->selectionModel()->selectedIndexes()[0];
            int last_row_index = ui->tableWidget->rowCount() - 1;

            if (current_index.row() == last_row_index)
            {
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                ++last_row_index;

                add_date_edit(last_row_index, 5);
                add_status_combo(last_row_index, 6);
                add_day_checkBox(last_row_index, 7);
                add_folder_checkBox(last_row_index, 8);
            }

            QModelIndex current_selected = ui->tableWidget->selectionModel()->currentIndex();
            QModelIndex next_index = ui->tableWidget->model()->index(last_row_index,
                                                                     current_selected.column());

            QTableWidgetItem *next_item = ui->tableWidget->itemFromIndex(next_index);
            if (!next_item)
            {
                next_item = new QTableWidgetItem;
                ui->tableWidget->setItem(next_index.row(), next_index.column(), next_item);
            }
            ui->tableWidget->setCurrentIndex(next_index);
        }

        if (event->key() == Qt::Key_Delete)
        {
            QList<QModelIndex> index_list = ui->tableWidget->selectionModel()->selectedIndexes();
            QList<int> row_values;
            for (QModelIndex index : index_list)
                row_values.push_back(index.row());

            std::set row_set(row_values.begin(), row_values.end());
            std::vector<int> vec_set(row_set.begin(), row_set.end());
            ui->tableWidget->selectionModel()->clear();
            for (int i=vec_set.size()-1; i>=0; --i)
            {
                ui->tableWidget->removeRow(vec_set[i]);
            }

            if (ui->tableWidget->rowCount() == 0)
            {
                ui->tableWidget->setRowCount(1);
                add_date_edit(0, 5);
                add_status_combo(0, 6);
                add_day_checkBox(0, 7);
                add_folder_checkBox(0, 8);
            }
        }


        if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_C))
        {
            QString text = "";
            QItemSelectionModel *model;
            model = ui->tableWidget->selectionModel();
            QModelIndexList index_list = model->selectedIndexes();

            int prev_row = index_list.at(0).row();
            for (QModelIndex index : index_list)
            {
                if (index.row() == prev_row)
                    text += '\t';
                else
                    text += '\n';

                if (ui->tableWidget->itemFromIndex(index))
                    text += ui->tableWidget->itemFromIndex(index)->text();
                else
                    text += "";
                prev_row = index.row();
            }
            text = text.trimmed();

            QClipboard *cb = QApplication::clipboard();
            cb->setText(text);
        }

        if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_V))
        {
            QClipboard *cb = QApplication::clipboard();            
            QList<QString> stringList = cb->text().split('\t');

            QItemSelectionModel *model = ui->tableWidget->selectionModel();
            QModelIndex first_index = model->selectedIndexes().front();
            int row_start = first_index.row();
            int col_start = first_index.column();

            for (QString text : stringList)
            {
                if (text.contains('\n'))
                    ++row_start;

                if (row_start >= ui->tableWidget->rowCount())
                    break;
                else
                    ui->tableWidget->itemAt(row_start, col_start)->setText(text);
            }


//            QTableWidgetItem *item;
//            if ((item = ui->tableWidget->currentItem()))
//            {
//                item->setText(cb->text());
//            }

//            else
//            {
//                QModelIndex index;
//                index = ui->tableWidget->selectionModel()->selectedIndexes()[0];
//                item = new QTableWidgetItem;
//                ui->tableWidget->setItem(index.row(), index.column(), item);
//                item->setText(cb->text());
//            }
        }

        if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_X))
        {
            QString text;

            QModelIndex index;
            index = ui->tableWidget->selectionModel()->selectedIndexes()[0];

            QTableWidgetItem *item;
            if ((item = ui->tableWidget->item(index.row(), index.column())))
            {
                text = item->text();
                item->setText("");
            }
            else
            {
                text = "";
            }

            QClipboard *cb = QApplication::clipboard();
            cb->setText(text);
        }
    }
}


void MainWindow::on_actionAbout_triggered()
{
    AboutWindow *win = new AboutWindow();
    win->show();
}


void MainWindow::status_changed()
{
    if (!calculate_on)
        return;

    int incomplete = 0, late = 0, complete = 0;

    QWidget *frame, *dateFrame;
    QComboBox *cb;
    QDateEdit *dateEdit;
    for (int row=0; row<ui->tableWidget->rowCount(); ++row)
    {
        frame = ui->tableWidget->cellWidget(row, 6);
        cb = frame->findChild<QComboBox*>("statusCombo");

        dateFrame = ui->tableWidget->cellWidget(row, 5);
        dateEdit = dateFrame->findChild<QDateEdit*>("dateEdit");

        if (cb->currentText() == "Complete")
            ++complete;
        else if (cb->currentText() == "Incomplete")
         {
            ++incomplete;
            if (dateEdit->date() < ui->todayEdit->date())
                ++late;
         }
    }
    ui->incompleteSpinBox->setValue(incomplete);
    ui->lateTasksSpinBox->setValue(late);
    ui->completeSpinBox->setValue(complete);
    set_date_color();
}


void MainWindow::set_date_color()
{
    if (!calculate_on)
        return;

    for (int i=0; i<ui->tableWidget->rowCount(); ++i)
    {
        QWidget *dateFrame = ui->tableWidget->cellWidget(i, 5);
        QDateEdit *dateEdit = dateFrame->findChild<QDateEdit*>("dateEdit");
        QWidget *statusFrame = ui->tableWidget->cellWidget(i, 6);
        QComboBox *cb = statusFrame->findChild<QComboBox*>("statusCombo");

        if (dateEdit->date() < ui->todayEdit->date() && cb->currentText() == "Incomplete")
        {
            dateEdit->setStyleSheet("background-color: red;"
                                    "color: white;");
        }

        else
        {
            dateEdit->setStyleSheet("");
        }
    }

}


void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if (!calculate_on)
        return;

    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}


void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    if (!calculate_on)
        return;

    status_changed();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}



void MainWindow::on_selectFolderButton1_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachmentPathLineEdit->setText(folder_path);
}


void MainWindow::on_selectFolderButton2_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachment2PathLineEdit->setText(folder_path);
}


void MainWindow::on_selectFolderButton3_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachment3PathLineEdit->setText(folder_path);
}


void MainWindow::on_selectFolderButton4_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachment4PathLineEdit->setText(folder_path);
}


void MainWindow::on_selectFolderButton5_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachment5PathLineEdit->setText(folder_path);
}


void MainWindow::on_actionClear_Table_Data_triggered()
{
    ui->tableWidget->selectionModel()->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(1);
    add_date_edit(0, 5);
    add_status_combo(0, 6);
    add_day_checkBox(0, 7);
    add_folder_checkBox(0, 8);
}

