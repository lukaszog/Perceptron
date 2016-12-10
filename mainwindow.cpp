#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "perceptron.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->widget();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_learn_clicked()
{

    QString numberToLearnVal = ui->numberToLearn->text();
    ui->widget->savePoints(ui->widget->clicked, numberToLearnVal);
}

void MainWindow::on_classify_clicked()
{
    QVector<int> readed;
    int ile=1;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            readed.push_back(ui->widget->clicked[i][j]);
        }
    }

    for(int i=0; i<2; i++)
    {
       if(ui->widget->p[i].check(readed) == 1)
       {
             qDebug() << "Wykryłem liczbe: " << i;
       }
    }
}
