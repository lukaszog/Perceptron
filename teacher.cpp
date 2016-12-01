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

teacher::learnPerceptron(perceptron p, int number, double learnConst)
{

    p.randweight();



    qDebug("%s", "Zakonczylem nauke...");

}

teacher::saveDataToFile(int tab[], int value)
{
    /*QFile file("data.txt");

    if(!file.open(QIODevice::Append | QIODevice::Text))
        return 0;

    QVector<int> tmp;
    QString line;
    for(int i=0; i<25; i++)
    {
        line += tab[i] + " ";
        tmp[i] = tab[i];
    }

    tmp[25] = value;
    line += value;

    QVector<QString> added;
    added.append(line);
    savedData.append(tmp);

    QTextStream out(&file);
     for (QVector<QString>::iterator iter = added.begin(); iter != added.end(); iter++){
         out << *iter;
     }
     file.close();*/
}
