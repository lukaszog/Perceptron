#include "perceptron.h"

perceptron::perceptron()
{

}
perceptron& perceptron::operator=(const perceptron&){

    return * this;
}

perceptron::randweight()
{

    for(int i=0; i<25; i++)
    {

        weights[i] = this->fRand(0,1);

    }
    bias = this->fRand(0,1);
}

perceptron::correctweight(QVector<int> readed, double m, double err)
{
    for(int i=0; i<25; i++)
    {
         double correct = err * readed.at(i) * m;
         weights[i] += correct;

    }
    bias -= err;
}

short perceptron::check(QVector<int> readed)
{
    double result = 0.0;

    for(int i=0; i<25; i++)
    {
         result +=  weights[i] * readed.at(i);
    }

    return (short) ((result - bias>=0)?1:-1);
}

double perceptron::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
