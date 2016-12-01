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
