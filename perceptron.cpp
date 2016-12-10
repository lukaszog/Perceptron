#include "perceptron.h"
#include<QDebug>
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
  //  qDebug() << "Bias: " << bias;
}

perceptron::correctweight(QVector<int> readed, double m, double err)
{
    for(int i=0; i<readed.size(); i++)
    {
         double correct = err * readed.at(i) * m;
         weights[i] += correct;
        // qDebug() << "POPRAWKA :" << correct;

    }
    bias -= err;
}

int perceptron::check(QVector<int> readed)
{
    double result = 0.0;

    for(int i=0; i<readed.size(); i++)
    {
         result +=  weights[i] * readed.at(i);

        // qDebug() << "Dzialanie: " << weights[i] << " * " << readed.at(i);

        // qDebug() << result;
    }

    if(( result - bias >= 0))
    {
       // qDebug() << "Zwracam 1";
    }else{
      //  qDebug()<<"Zwracam -1";
    }

   // qDebug() << "Bias wynosi: " << bias << "Result wynosi: " << result;

    return (( result - bias >= 0 ) ? 1 : -1 );
}

double perceptron::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
