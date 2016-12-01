#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QWidget>
#include <QMouseEvent>

class perceptron
{
public:
    perceptron();
    randweight();
    short check(QVector<int> readed);
    correctweight(QVector<int> readed, double m, double err);
    double fRand(double fMin, double fMax);
    perceptron& operator=(const perceptron&);
    double weights[25];
    double bias;
};

#endif // PERCEPTRON_H
