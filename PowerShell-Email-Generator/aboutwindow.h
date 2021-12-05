#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
