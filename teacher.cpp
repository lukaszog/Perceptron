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
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            resultVector[i][j] = dataFromMatrix[i][j];
        }
    }
    readDataFromFile();
}

teacher::readDataFromFile()
{
    QFile inputFile("E:\\Sieci Neuronowe\\Perceptron\\points.txt");
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          QVector<int> readLine;

          for(int i=0; i<line.size(); i++)
          {
             readLine.append(line[i].digitValue());
          }

          savedData.append(readLine);
       }
       inputFile.close();
    }
}

void teacher::learnPerceptrons(std::vector<std::vector<perceptron>> &vec, double learnConst)
{
    int number=0;

    for (const auto& inner : vec) {
         for (const auto& item : inner) {
             learnPerceptron(item, number, learnConst);
             number++;
         }
     }
}

teacher::learnPerceptron(perceptron p, int perceptronNumber, double learnConst)
{

    p.randweight();

    bool pass = false;

    if(savedData.size() == 0)
    {
        pass = true;
    }

    while(!pass)
    {
          for (const auto& inner : savedData) {

              QVector<int> readed;

              for(int i=0; i<25; i++)
              {
                  readed.push_back(inner.at(i));
              }

              int number = (inner.at(25) == perceptronNumber) ? 1 : -1;
              int error = number - p.check(readed);

              if(error != 0)
              {
                  pass = false;
                  p.correctweight(readed, learnConst, error);
              }

          }
    }

    qDebug("%s", "Zakonczylem  nauke...");

}

