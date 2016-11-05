#include "perceptron.h"

perceptron::perceptron()
{

}
perceptron& perceptron::operator=(const perceptron&){

    return * this;
}

perceptron::randweight()
{

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            weights[i][j] = this->fRand(0,1);
        }
    }
    bias = this->fRand(0,1);
}

perceptron::correctweight(int fieldValue[][5], double m, double err)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            double correct = err * fieldValue[i][j];
            weights[i][j] += correct;
        }
    }

    bias -= err;

}

short perceptron::check(int fieldValue[][5])
{
    double result = 0.0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            result += weights[i][j] * fieldValue[i][j];
        }
    }

    return (short) ((result - bias>=0)?1:-1);
}

double perceptron::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
