#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "computer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_num1Btn_clicked();

    void on_DivOptBtn_clicked();

    void on_plusOptBtn_clicked();

    void on_num2Btn_clicked();

    void on_num3Btn_clicked();

    void on_num4Btn_clicked();

    void on_num5Btn_clicked();

    void on_num6Btn_clicked();

    void on_num7Btn_clicked();

    void on_num8Btn_clicked();

    void on_num9Btn_clicked();

    void on_num0Btn_clicked();

    void on_timesOptBtn_clicked();

    void on_minusOptBtn_clicked();

    void on_leftParBtn_clicked();

    void on_rightParBtn_clicked();

    void on_delBtn_clicked();

    void on_ACbtn_clicked();

    void on_dotSignBtn_clicked();

    void on_equalSignBtn_clicked();

private:
    Ui::MainWindow *ui;
    Computer computer;
};

#endif // MAINWINDOW_H
