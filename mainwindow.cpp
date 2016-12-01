#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "perceptron.h"

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

}
