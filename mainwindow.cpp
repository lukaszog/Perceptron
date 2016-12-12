#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "perceptron.h"
#include <QDebug>
#include <QMessageBox>

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
    PrintRectangle *mm = new PrintRectangle();

}

void MainWindow::on_classify_clicked()
{
    QVector<int> readed;
    int ile=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            readed.push_back(ui->widget->clicked[i][j]);
        }
    }

    for(int i=0; i<10; i++)
    {
       if(ui->widget->p[i].check(readed) == 1)
       {
             ile++;
             if(ile > 1)
             {
                 QMessageBox msgBox;
                 msgBox.setText("Wykrylem wiecej niz jedna liczbe");
                 msgBox.exec();
             }else{
                 QMessageBox msgBox;
                 QString text = QString("Liczba: %1").arg(i);
                 msgBox.setText(text);
                 msgBox.exec();
             }
             qDebug() << "Wykryłem liczbe: " << i;
       }
    }
    if(ile==0)
    {
        QMessageBox msgBox;
        msgBox.setText("Nic nie wykryłem");
        msgBox.exec();
    }
}
