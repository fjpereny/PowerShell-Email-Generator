#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
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
    void add_date_edit(int cell_row, int cell_col);
    void add_status_combo(int cell_row, int cell_col);
    void add_day_checkBox(int cell_row, int cell_col);
    void add_folder_checkBox(int cell_row, int cell_col);

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
    QString createMailScript(int row = 0,
                             QString to = "",
                             QString cc = "",
                             QString bcc = "",
                             QString subject = "",
                             QString body = "",
                             QString attachments_1 = "",
                             QString attachments_2 = "",
                             QString attachments_3 = "",
                             QString attachments_4 = "",
                             QString attachments_5 = "");

    QString generate_script();

    void keyPressEvent(QKeyEvent *event);


    void on_actionAbout_triggered();

    void status_changed();
    void set_date_color();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_selectFolderButton1_clicked();
    void on_selectFolderButton2_clicked();
    void on_selectFolderButton3_clicked();
    void on_selectFolderButton4_clicked();
    void on_selectFolderButton5_clicked();

    void on_actionClear_Table_Data_triggered();

    void on_runButton_clicked();

    void on_actionClear_All_Data_triggered();

private:
    Ui::MainWindow *ui;

    bool *calculate_on;
};
#endif // MAINWINDOW_H
