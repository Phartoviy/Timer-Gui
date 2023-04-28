#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    ui->label->setNum(a);
    ui->label_2->setNum(b);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatetime()));
    timer->setInterval(10);


    ui->lone->hide();
    ui->ltwo->hide();
    ui->lthree->hide();

    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlag(Qt::WindowCloseButtonHint);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::updatetime()
{
    if (b==59)
           {
        b=0;
        c++;
        ui->label_2->setNum(b);
        ui->label_4->setNum(c);
    }
    if (a>=99){
        b++;
        a=0;
        ui->label->setNum(a);
        ui->label_2->setNum(b);}
    else{
        a++;
        ui->label->setNum(a);}

}

void MainWindow::on_pushButton_clicked()
{

    //QTimer *timer = new QTimer(this);


    if (key==false){

        timer->start(10);
        key=true;
        ui->pushButton->setText("Stop");
    }
    else
    {
        key=false;
        timer->stop();
        ui->pushButton->setText("Start");
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    a = 0;
    b = 0;
    c = 0;
    ui->label_4->setNum(c);
    ui->label_2->setNum(b);
    ui->label->setNum(a);
}

void MainWindow::on_pushButton_3_clicked()
{
    if (s==0)
    {
        ui->lone->hide();
        ui->ltwo->hide();
        ui->lthree->hide();
    }
    s++;
    if (s==1)
    {
        ui->lone->setText(ui->label_4->text()+ui->label_5->text()+ui->label_2->text()+ui->label_3->text()+ui->label->text());
        ui->lone->show();
    }
    if (s==2)
    {
        ui->ltwo->setText(ui->label_4->text()+ui->label_5->text()+ui->label_2->text()+ui->label_3->text()+ui->label->text());
        ui->ltwo->show();
    }
    if (s==3)
    {
        ui->lthree->setText(ui->label_4->text()+ui->label_5->text()+ui->label_2->text()+ui->label_3->text()+ui->label->text());
        ui->lthree->show();
        s=0;
    }
}
