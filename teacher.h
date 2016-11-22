#ifndef TEACHER_H
#define TEACHER_H

#include <QVector>
#include <QList>
#include "perceptron.h"

class teacher
{
public:

    class perceptron;

    teacher();
    teacher(bool dataFromMatrix[][5]);
    readDataFromFile();
    writeToFile();
    learnPerceptron();
    void learnPerceptrons(perceptron p[][5]);
    randPerceptronsWights();
    saveDataToFile(int tab[], int value);
    int resultVector[5][5];
    QList<QVector<int>> savedData;
    teacher& operator=(const teacher&);
};

#endif // TEACHER_H
