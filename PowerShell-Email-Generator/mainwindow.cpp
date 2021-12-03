#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      last_focused_widget(new QWidget)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    last_focused_widget = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionClose_triggered()
{
    close();
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

