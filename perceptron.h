#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QWidget>
#include <QMouseEvent>

class perceptron
{
public:
    perceptron();
public:
    randweight();
    short check(int fieldValue[][5]);
    correctweight(int fieldValue[][5], double m, double err);
    double fRand(double fMin, double fMax);
    perceptron& operator=(const perceptron&);


private:
    double weights[5][5];
    double bias;
};

#endif // PERCEPTRON_H
