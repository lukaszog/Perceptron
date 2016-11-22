#include "teacher.h"
#include <QFile>
#include <QTextStream>
#include <fstream>

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
    QFile file("data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();

       /* int *load = new int[26];
        for(int i=0; i<26; i++)
        {
            load[i] = atoi(line[2*i]);
        }*/
    }
}

void teacher::learnPerceptrons(perceptron p[][5])
{

}

teacher::saveDataToFile(int tab[], int value)
{
    QFile file("data.txt");

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
     file.close();
}
