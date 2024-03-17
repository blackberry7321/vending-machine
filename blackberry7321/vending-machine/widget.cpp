#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    changeEnabled();
}
void Widget::changeEnabled()
{
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=200);
    ui->pbTang->setEnabled(money>=300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::on_lcdNumber_overflow()
{

}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    int ch500, ch100, ch50, ch10 = 0;

    if (money >= 500)
    {
        ch500 = money / 500;
        money %= 500;
    }

    if (money >= 100)
    {
        ch100 = money / 100;
        money %= 100;
    }

    if (money >= 50)
    {
        ch50 = money / 50;
        money %= 50;
    }

    if (money >= 10)
    {
        ch10 = money / 10;
        money %= 10;
    }

    ui->lcdNumber->display(money);
    QMessageBox mb;
    QString message;

    if (ch500 > 0)
    {
        message += QString("Amount of Coin500: %1\n").arg(ch500);
    }
    if (ch100 > 0)
    {
        message += QString("Amount of Coin100: %1\n").arg(ch100);
    }
    if (ch50 > 0)
    {
        message += QString("Amount of Coin50: %1\n").arg(ch50);
    }
    if (ch10 > 0)
    {
        message += QString("Amount of Coin10: %1\n").arg(ch10);
    }

    mb.information(nullptr, "Change", message);
    changeEnabled();
}

