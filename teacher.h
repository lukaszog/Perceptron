#ifndef TEACHER_H
#define TEACHER_H

#include <QVector>
#include <QList>

class teacher
{
public:
    teacher();
    teacher(int dataFromMatrix[][5]);
    readDataFromFile();
    writeToFile();
    learnPerceptrons();
    learnPerceptron();
    randPerceptronsWights();
    saveDataToFile(int tab[], int value);
    int resultVector[5][5];
    QList<QVector<int>> savedData;


};

#endif // TEACHER_H
