#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutwindow.h"
#include "tinyxml2.h"

#include <iostream>
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
      last_focused_widget(new QWidget)
{
    ui->setupUi(this);

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    QDateEdit *dateEdit = new QDateEdit();
    dateEdit->setButtonSymbols(QDateEdit::NoButtons);
    dateEdit->setDate(QDate::currentDate());
    ui->tableWidget->setCellWidget(0, 5, dateEdit);
    dateEdit->connect(dateEdit,
                      SIGNAL ( dateChanged(QDate) ),
                      this,
                      SLOT ( set_date_color() ));

    QComboBox *statusCombo = new QComboBox();
    statusCombo->addItem("Incomplete");
    statusCombo->addItem("Late");
    statusCombo->addItem("Complete");    
    ui->tableWidget->setCellWidget(0, 6, statusCombo);
    QObject::connect(statusCombo,
                     SIGNAL( currentTextChanged(QString) ),
                     this,
                     SLOT( status_changed() ));


    ui->todayEdit->setDate(QDate::currentDate());
    ui->todayEdit->setButtonSymbols(QDateEdit::NoButtons);

    ui->lateTasksSpinBox->setButtonSymbols(QSpinBox::NoButtons);

    last_focused_widget = nullptr;
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
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
    element_1 = root->FirstChildElement("project");
        element_2 = element_1->FirstChildElement("project_name");
        ui->projectNameLineEdit->setText(element_2->GetText());
        element_2 = element_1->FirstChildElement("project_gate");
        ui->gateLineEdit->setText(element_2->GetText());
        element_2 = element_1->FirstChildElement("project_gate_due");
        ui->gateDueLineEdit->setText(element_2->GetText());
        element_2 = element_1->FirstChildElement("attachment_path");
        ui->attachmentPathLineEdit->setText(element_2->GetText());

    element_1 = root->FirstChildElement("email");
        element_2 = element_1->FirstChildElement("subject");
        ui->emailSubject->setText(element_2->GetText());
        element_2 = element_1->FirstChildElement("body");
        ui->emailBody->setPlainText(element_2->GetText());

    tinyxml2::XMLElement *table_element, *row_element, *col_element;
    table_element = root->FirstChildElement("task_table");

    int xml_row_count = 0;
    QString  element_name = "row_" + QString::number(xml_row_count);
    while (table_element->FirstChildElement(element_name.toStdString().c_str()))
    {
        ++xml_row_count;
        element_name = "row_" + QString::number(xml_row_count);
    }

    ui->tableWidget->setRowCount(xml_row_count);
    for (int row=0; row<xml_row_count; ++row)
    {
        for (int col=0; col<ui->tableWidget->columnCount(); ++col)
        {
            QString row_name = "row_" + QString::number(row);
            QString col_name = "col_" + QString::number(col);

            row_element = table_element->FirstChildElement(row_name.toStdString().c_str());
            col_element = row_element->FirstChildElement(col_name.toStdString().c_str());

            QTableWidgetItem *item;
            if (!(item = ui->tableWidget->item(row, col)))
            {
                item = new QTableWidgetItem();
                ui->tableWidget->setItem(row, col, item);
            }
            item->setText(col_element->GetText());
        }
    }
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
        QString date = QDate::currentDate().toString();
        save_date->SetText(date.toStdString().c_str());


    tinyxml2::XMLElement *project = xmlDoc->NewElement("project");
    root->InsertEndChild(project);
        tinyxml2::XMLElement *project_name = xmlDoc->NewElement("project_name");
        tinyxml2::XMLElement *project_gate = xmlDoc->NewElement("project_gate");
        tinyxml2::XMLElement *project_gate_due = xmlDoc->NewElement("project_gate_due");
        tinyxml2::XMLElement *attachment_path = xmlDoc->NewElement("attachment_path");
        project_name->SetText(ui->projectNameLineEdit->text().toStdString().c_str());
        project_gate->SetText(ui->gateLineEdit->text().toStdString().c_str());
        project_gate_due->SetText(ui->gateDueLineEdit->text().toStdString().c_str());
        attachment_path->SetText(ui->attachmentPathLineEdit->text().toStdString().c_str());
        project->InsertEndChild(project_name);
        project->InsertEndChild(project_gate);
        project->InsertEndChild(project_gate_due);
        project->InsertEndChild(attachment_path);

    tinyxml2::XMLElement *email = xmlDoc->NewElement("email");
    root->InsertEndChild(email);
        tinyxml2::XMLElement *to = xmlDoc->NewElement("to");
        tinyxml2::XMLElement *cc = xmlDoc->NewElement("cc");
        tinyxml2::XMLElement *bcc = xmlDoc->NewElement("bcc");
        tinyxml2::XMLElement *subject = xmlDoc->NewElement("subject");
        tinyxml2::XMLElement *body = xmlDoc->NewElement("body");
        tinyxml2::XMLElement *attachments = xmlDoc->NewElement("attachments");
        email->InsertEndChild(to);
        email->InsertEndChild(cc);
        email->InsertEndChild(bcc);
        email->InsertEndChild(subject);
        email->InsertEndChild(body);
        email->InsertEndChild(attachments);
        // to code
        // cc code
        // bcc code
        subject->SetText(ui->emailSubject->text().toStdString().c_str());
        body->SetText(ui->emailBody->toPlainText().toStdString().c_str());

    tinyxml2::XMLElement *task_table = xmlDoc->NewElement("task_table");
    root->InsertEndChild(task_table);
        for (int row=0; row<ui->tableWidget->rowCount(); ++row)
        {
            QString row_name = "row_" + QString::number(row);
            tinyxml2::XMLElement *new_row = xmlDoc->NewElement(row_name.toStdString().c_str());
            task_table->InsertEndChild(new_row);

            for (int col=0; col<ui->tableWidget->columnCount(); ++col)
            {
                QString col_name = "col_" + QString::number(col);
                tinyxml2::XMLElement *new_col = xmlDoc->NewElement(col_name.toStdString().c_str());
                new_row->InsertEndChild(new_col);

                if (ui->tableWidget->item(row, col))
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
    QString header = "";
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

    QString attachments = ui->attachmentPathLineEdit->text();
    if (attachments.back() != '/' && attachments.back() != '\\')
        attachments += '/';
    attachments = QDir::toNativeSeparators(attachments);

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
    for (int row=0; row<ui->tableWidget->rowCount(); ++row)
    {
        subject = ui->emailSubject->text();
        body = ui->emailBody->toPlainText();

        task = ui->tableWidget->item(row, 0)->text();
        owner = ui->tableWidget->item(row, 1)->text();
        owner_email = ui->tableWidget->item(row, 2)->text();
        manager = ui->tableWidget->item(row, 3)->text();
        manager_email = ui->tableWidget->item(row, 4)->text();
        status = ui->tableWidget->item(row, 5)->text();
        task_due = ui->tableWidget->item(row, 6)->text();

        subject.replace("[PROJECT NAME]", project_name);
        subject.replace("[PROJECT GATE]", project_gate);
        subject.replace("[GATE DUE]", gate_due);
        subject.replace("[TASK]", task);
        subject.replace("[OWNER]", owner);
        subject.replace("[OWNER EMAIL]", owner_email);
        subject.replace("[MANAGER]", manager);
        subject.replace("[MANAGER EMAIL]", manager_email);
        subject.replace("[STATUS]", status);
        subject.replace("[TASK DUE]", task_due);

        body.replace("[PROJECT NAME]", project_name);
        body.replace("[PROJECT GATE]", project_gate);
        body.replace("[GATE DUE]", gate_due);
        body.replace("[TASK]", task);
        body.replace("[OWNER]", owner);
        body.replace("[OWNER EMAIL]", owner_email);
        body.replace("[MANAGER]", manager);
        body.replace("[MANAGER EMAIL]", manager_email);
        body.replace("[STATUS]", status);
        body.replace("[TASK DUE]", task_due);        

        script += createMailScript(owner_email, manager_email, "", subject, body, attachments);

    }

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
            QAbstractItemModel *model = ui->tableWidget->model();
            QModelIndex current_index = ui->tableWidget->selectionModel()->selectedIndexes()[0];
            int last_row_index = ui->tableWidget->rowCount() - 1;

            if (current_index.row() == last_row_index)
            {
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

                QDateEdit *dateEdit = new QDateEdit();
                dateEdit->setButtonSymbols(QDateEdit::NoButtons);
                dateEdit->setDate(QDate::currentDate());
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 5, dateEdit);
                dateEdit->connect(dateEdit,
                                  SIGNAL ( dateChanged(QDate) ),
                                  this,
                                  SLOT ( set_date_color() ));

                QComboBox *statusCombo = new QComboBox();
                statusCombo->addItem("Incomplete");
                statusCombo->addItem("Late");
                statusCombo->addItem("Complete");
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 6, statusCombo);
                QObject::connect(statusCombo,
                                 SIGNAL( currentTextChanged(QString) ),
                                 this,
                                 SLOT( status_changed() )
                                 );
            }

            QModelIndex next_index = model->index(current_index.row() + 1, current_index.column());

            ui->tableWidget->selectionModel()->select(next_index, QItemSelectionModel::ClearAndSelect);
            ui->tableWidget->setCurrentIndex(next_index);
        }

        if (event->key() == Qt::Key_Delete)
        {
            QList<QModelIndex> index_list = ui->tableWidget->selectionModel()->selectedIndexes();
            if (index_list.size() >= 1)
            {
                for (auto index : index_list)
                    ui->tableWidget->removeRow(index.row());

                if (ui->tableWidget->rowCount() == 0)
                {
                    ui->tableWidget->setRowCount(1);

                    QDateEdit *dateEdit = new QDateEdit();
                    dateEdit->setButtonSymbols(QDateEdit::NoButtons);
                    dateEdit->setDate(QDate::currentDate());
                    ui->tableWidget->setCellWidget(0, 5, dateEdit);
                    dateEdit->connect(dateEdit,
                                      SIGNAL ( dateChanged(QDate) ),
                                      this,
                                      SLOT ( set_date_color() ));

                    QComboBox *statusCombo = new QComboBox();
                    statusCombo->addItem("Incomplete");
                    statusCombo->addItem("Late");
                    statusCombo->addItem("Complete");
                    ui->tableWidget->setCellWidget(0, 6, statusCombo);
                    QObject::connect(statusCombo,
                                     SIGNAL( currentTextChanged(QString) ),
                                     this,
                                     SLOT( status_changed() ));
                }
            }
        }


        if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_C))
        {
            QString text;
            QTableWidgetItem *item;
            if ((item = ui->tableWidget->currentItem()))
            {
                text = item->text();
            }
            else
            {
                text = "";
            }

            QClipboard *cb = QApplication::clipboard();
            cb->setText(text);
        }

        if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_V))
        {
            QClipboard *cb = QApplication::clipboard();

            QTableWidgetItem *item;
            if ((item = ui->tableWidget->currentItem()))
            {
                item->setText(cb->text());
            }

            else
            {
                QModelIndex index;
                index = ui->tableWidget->selectionModel()->selectedIndexes()[0];
                item = new QTableWidgetItem;
                ui->tableWidget->setItem(index.row(), index.column(), item);
                item->setText(cb->text());
            }
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

void MainWindow::on_selectFolderButton1_clicked()
{
    QString folder_path = QFileDialog::getExistingDirectory(this,
                                                          "Select Attachments Folder",
                                                          QDir::toNativeSeparators(QDir::currentPath()));
    ui->attachmentPathLineEdit->setText(folder_path);
}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow *win = new AboutWindow();
    win->show();
}


void MainWindow::status_changed()
{
    QComboBox *cb = qobject_cast<QComboBox*>(QObject::sender());
    if (cb->currentText() == "Late")
    {
        int late_count = ui->lateTasksSpinBox->value();
        late_count += 1;
        ui->lateTasksSpinBox->setValue(late_count);

        cb->setStyleSheet("background-color : red;"
                          "color: black;"
                          );
    }
    else if (cb->currentText() == "Incomplete")
    {
        int late_count = ui->lateTasksSpinBox->value();
        late_count -= 1;
        ui->lateTasksSpinBox->setValue(late_count);

        cb->setStyleSheet("background-color : yellow;"
                          "color: black");
    }
    else if (cb->currentText() == "Complete")
    {
        int late_count = ui->lateTasksSpinBox->value();
        late_count -= 1;
        ui->lateTasksSpinBox->setValue(late_count);

        cb->setStyleSheet("background-color : green;"
                          "color: black");
    }
}


void MainWindow::set_date_color()
{
    QDateEdit *dateEdit = qobject_cast<QDateEdit*>(QObject::sender());
    if (dateEdit->date() <= ui->todayEdit->date())
    {
        dateEdit->setStyleSheet("background-color : red;"
                                "color : white;"
                               );
    }

    else
    {
        dateEdit->setStyleSheet("");
    }
}
