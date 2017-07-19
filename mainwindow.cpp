#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "computer.h"
#include <exception>
#include <string>
#include <QDebug>

using std::string;
using std::exception;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plusOptBtn_clicked()
{
    QString tmp = ui->numDisplayLbl->text();

    if (computer.getHasComputed())
    {
        tmp = computer.getResultStr() + "+";
        computer.setHasComputed(false);
    }
    else
    {
        tmp += "+";
    }
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_minusOptBtn_clicked()
{
    QString tmp = ui->numDisplayLbl->text();

    if (computer.getHasComputed())
    {
        tmp = computer.getResultStr() + "-";
        computer.setHasComputed(false);
    }
    else
    {
        tmp += "-";
    }
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_timesOptBtn_clicked()
{
    QString tmp = ui->numDisplayLbl->text();

    if (computer.getHasComputed())
    {
        tmp = computer.getResultStr() + "*";
        computer.setHasComputed(false);
    }
    else
    {
        tmp += "*";
    }
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_DivOptBtn_clicked()
{
    QString tmp = ui->numDisplayLbl->text();

    if (computer.getHasComputed())
    {
        tmp = computer.getResultStr() + "/";
        computer.setHasComputed(false);
    }
    else
    {
        tmp += "/";
    }
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num1Btn_clicked()
{
    //computer.pushStack(Sign('1', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "1";
    else
        tmp = "1";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num2Btn_clicked()
{
    //computer.pushStack(Sign('2', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "2";
    else
        tmp = "2";
    ui->numDisplayLbl->setText(tmp);
}


void MainWindow::on_num3Btn_clicked()
{
    //computer.pushStack(Sign('3', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "3";
    else
        tmp = "3";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num4Btn_clicked()
{
    //computer.pushStack(Sign('4', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "4";
    else
        tmp = "4";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num5Btn_clicked()
{
   // computer.pushStack(Sign('5', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "5";
    else
        tmp = "5";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num6Btn_clicked()
{
    //computer.pushStack(Sign('6', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "6";
    else
        tmp = "6";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num7Btn_clicked()
{
    //computer.pushStack(Sign('7', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "7";
    else
        tmp = "7";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num8Btn_clicked()
{
    //computer.pushStack(Sign('8', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "8";
    else
        tmp = "8";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num9Btn_clicked()
{
    //computer.pushStack(Sign('9', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "9";
    else
        tmp = "9";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_num0Btn_clicked()
{
    //computer.pushStack(Sign('0', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "0";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_leftParBtn_clicked()
{
    //computer.pushStack(Sign('(', LPAR, 3));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += "(";
    else
        tmp = "(";
    ui->numDisplayLbl->setText(tmp);
}


void MainWindow::on_rightParBtn_clicked()
{
    //computer.pushStack(Sign(')', RPAR, 3));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += ")";
    else
        tmp = ")";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_delBtn_clicked()
{
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp.length() == 1)
    {
        tmp = "0";
        //computer.clearStack();
    }
    else
    {
        tmp.remove(tmp.length() - 1, 1);
        //computer.popStack();
    }
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_ACbtn_clicked()
{
    ui->numDisplayLbl->setText("0");
    ui->resultDisplayLbl->setText("=");
    computer.clearStack();
    computer.setHasComputed(false);
}

void MainWindow::on_dotSignBtn_clicked()
{
    //computer.pushStack(Sign('.', NUM, -1));
    QString tmp = ui->numDisplayLbl->text();
    if (computer.getHasComputed())
    {
        tmp = "0";
        computer.setHasComputed(false);
    }
    if (tmp != "0")
        tmp += ".";
    else
        tmp = ".";
    ui->numDisplayLbl->setText(tmp);
}

void MainWindow::on_equalSignBtn_clicked()
{
    QString rst;
    bool hasError = false;
    string exp = ui->numDisplayLbl->text().toStdString();

    // push last result into record to make it join the
    // next computing
//    string lastResult = computer.getResultStr();

//    if (computer.getHasComputed())
//    {
//        lastResult += exp;
//        exp = lastResult;
//        ui->numDisplayLbl->setText(
//                    QString::fromStdString(exp));
//    }

    // push expression into record of computer
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9'
                || exp[i] == '.')
        {
            computer.pushStack(Sign(exp[i], NUM, -1));
        }
//        else if (exp[i] == '+')
//        {
//            computer.pushStack(Sign(exp[i], OPT, 1));
//        }
        else if (exp[i] == '-'
                 || exp[i] == '+')
        {
            // judge if '-' is negative symbol
            if (computer.isEmpty()
                    || computer.getBack().getType() == OPT)
            {
                computer.pushStack(Sign(exp[i], NUM, -1));
            }
            else
            {
                computer.pushStack(Sign(exp[i], OPT, 1));
            }
        }
        else if (exp[i] == '*'
                 || exp[i] == '/')
        {
            computer.pushStack(Sign(exp[i], OPT, 2));
        }
        else if (exp[i] == '(')
        {
            computer.pushStack(Sign(exp[i], LPAR, 3));
        }
        else if (exp[i] == ')')
        {
            computer.pushStack(Sign(exp[i], RPAR, 3));
        }
    }
    // process and compute
    try
    {
        computer.infix2Postfix();
        computer.computeResult();
    }
    catch (exception e)
    {
        hasError = true;
        computer.clearStack();
    }
    computer.setHasComputed(true);
    if (!hasError)
    {
        rst = "=" + QString::number(computer.getResult());
    }
    else
    {
        rst = "Bad Expression!";
    }
    ui->resultDisplayLbl->setText(rst);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_0:
        on_num0Btn_clicked();
        break;
    case Qt::Key_1:
        on_num1Btn_clicked();
        break;
    case Qt::Key_2:
        on_num2Btn_clicked();
        break;
    case Qt::Key_3:
        on_num3Btn_clicked();
        break;
    case Qt::Key_4:
        on_num4Btn_clicked();
        break;
    case Qt::Key_5:
        on_num5Btn_clicked();
        break;
    case Qt::Key_6:
        on_num6Btn_clicked();
        break;
    case Qt::Key_7:
        on_num7Btn_clicked();
        break;
    case Qt::Key_8:
        on_num8Btn_clicked();
        break;
    case Qt::Key_9:
        on_num9Btn_clicked();
        break;
    case Qt::Key_Plus:
        on_plusOptBtn_clicked();
        break;
    case Qt::Key_Minus:
        on_minusOptBtn_clicked();
        break;
    case Qt::Key_Asterisk:
        on_timesOptBtn_clicked();
        break;
    case Qt::Key_Slash:
        on_DivOptBtn_clicked();
        break;
    case Qt::Key_Period:
        on_dotSignBtn_clicked();
        break;
    case Qt::Key_ParenLeft:
        on_leftParBtn_clicked();
        break;
    case Qt::Key_ParenRight:
        on_rightParBtn_clicked();
        break;
    case Qt::Key_Delete:
    case Qt::Key_Backspace:
        on_delBtn_clicked();
        break;
    case Qt::Key_Enter:
        on_equalSignBtn_clicked();
        break;
    default:
        break;
    }
}
