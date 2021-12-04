#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "tinyxml2.h"

#include <iostream>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QDate>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      last_focused_widget(new QWidget)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->todayEdit->setDate(QDate::currentDate());

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
                                                     QDir::currentPath(),
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

    element_1 = root->FirstChildElement("email");
        element_2 = element_1->FirstChildElement("subject");
        ui->emailSubject->setText(element_2->GetText());
        element_2 = element_1->FirstChildElement("body");
        ui->emailBody->setPlainText(element_2->GetText());
}


bool MainWindow::on_actionSave_triggered()
{
    tinyxml2::XMLDocument *xmlDoc = create_XML();

    QString save_file_path = QFileDialog::getSaveFileName(this,
                                                "Save File",
                                                QDir::currentPath(),
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
        project_name->SetText(ui->projectNameLineEdit->text().toStdString().c_str());
        project_gate->SetText(ui->gateLineEdit->text().toStdString().c_str());
        project_gate_due->SetText(ui->gateDueLineEdit->text().toStdString().c_str());
        project->InsertEndChild(project_name);
        project->InsertEndChild(project_gate);
        project->InsertEndChild(project_gate_due);

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
    script += "$Mail.To = " + to + "\n";
    script += "$Mail.Cc = " + cc + "\n";
    script += "$Mail.Bcc = " + bcc + "\n";
    script += "$Mail.Subject = \"" + subject + "\"\n";
    script += "Mail.Body = \"" + body + "\"\n";
    script += "Mail.Send()\n";
    return script;
}


void MainWindow::generate_script()
{
    QString script = "";

    QString save_file_path = QFileDialog::getSaveFileName(this,
                                                          "Save PowerShell Script",
                                                          QDir::currentPath(),
                                                          "PowerShell Script (*.ps1)");

    if (save_file_path.isEmpty())
        return;

    if (!save_file_path.contains(".ps1"))
        save_file_path += ".ps1";

    QString project_name = ui->projectNameLineEdit->text();
    QString project_gate = ui->gateLineEdit->text();
    QString gate_due = ui->gateDueLineEdit->text();

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

        script += createMailScript(owner_email, manager_email, "", subject, body, "");

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

