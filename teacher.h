#ifndef TEACHER_H
#define TEACHER_H

#include <QVector>
#include <QList>
#include "perceptron.h"

class teacher
{
public:

    teacher();
    teacher(bool dataFromMatrix[][5]);
    readDataFromFile();
    writeToFile();
    learnPerceptron(perceptron p, int number, double learnConst);
    void cos(int a);
    void learnPerceptrons(std::vector<std::vector<perceptron>> &p, double learnConst);
    randPerceptronsWights();
    saveDataToFile(int tab[], int value);
    int resultVector[5][5];
    QList<QVector<int>> savedData;
    teacher& operator=(const teacher&);
};

#endif // TEACHER_H
