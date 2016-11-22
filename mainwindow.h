#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <perceptron.h>
#include <printrectangle.h>
#include <teacher.h>


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
    void on_learn_clicked();
    void on_classify_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
