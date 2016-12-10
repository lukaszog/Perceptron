#include "teacher.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <fstream>
#include <iostream>
teacher::teacher()
{

}

teacher& teacher::operator=(const teacher&){

    return * this;
}

teacher::teacher(bool dataFromMatrix[][5])
{
    readDataFromFile();
}

void teacher::readDataFromFile()
{
    QFile inputFile("E:\\Sieci Neuronowe\\Perceptron\\points.txt");
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QVector<int> readLine;

          for(int i=0; i<26; i++)
          {
             readLine.append(line[i].digitValue());
          }

          savedData.append(readLine);
       }
       inputFile.close();
    }
}

void teacher::learnPerceptrons(std::vector<perceptron> &vec, double learnConst)
{
    int number=0;

    for (const auto& item : vec) {
         learnPerceptron(item, number, learnConst);
         number++;
    }
}

void teacher::learnPerceptron(perceptron p, int perceptronNumber, double learnConst)
{

    //p.randweight();

    bool pass = false;

    if(savedData.size() == 0)
    {
        pass = true;
    }

    int ilosc=0;

    while(!pass)
    {
          pass = true;
          for (const QVector<int> inner : savedData) {

              qDebug() << "Linia numer " << ilosc;
              ilosc++;
              QVector<int> readed;

              for(int i=0; i<25; i++)
              {
                 //qDebug() << "Zczytane wartosci " << inner.at(i);
                  readed.push_back(inner.at(i));
              }

              int number = (inner.at(25) == perceptronNumber) ? 1 : -1;
              //qDebug()<< "Wchodze";
              int error = number - p.check(readed);

              if(error != 0)
              {
                  pass = false;
                  qDebug() << "Learn const" << learnConst;
                  p.correctweight(readed, learnConst, error);
                  //qDebug() << "Poprawiam wagi";
              }
          }
    }
}

