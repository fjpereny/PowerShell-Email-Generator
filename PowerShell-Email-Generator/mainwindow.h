#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tinyxml2.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    bool on_actionSave_triggered();
    void on_actionClose_triggered();
    void on_actionGenerate_PowerShell_Script_triggered();

    tinyxml2::XMLDocument* create_XML();

    void on_projectNameButton_clicked();
    void on_projectGateButton_clicked();
    void on_gateDueButton_clicked();
    void on_taskButton_clicked();
    void on_ownerButton_clicked();
    void on_ownerEmailButton_clicked();
    void on_managerButton_clicked();
    void on_managerEmailButton_clicked();
    void on_statusButton_clicked();
    void on_dueDateButton_clicked();

    void on_generateButton_clicked();

    QString create_script_header();
    QString createMailScript(QString to = "",
                          QString cc = "",
                          QString bcc = "",
                          QString subject = "",
                          QString body = "",
                          QString attachments = "");

    void generate_script();

    void keyPressEvent(QKeyEvent *event);

    void on_selectFolderButton_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *last_focused_widget;
};
#endif // MAINWINDOW_H
