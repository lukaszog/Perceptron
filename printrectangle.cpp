#include "printrectangle.h"
#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <iostream>

PrintRectangle::PrintRectangle(QWidget *parent) : QWidget(parent),
    p(std::vector<perceptron>(10))
{
    qDebug() << "Wykonuje konstruktor";
    tech = new teacher(clicked);

    for(int i=0; i<10; i++)
    {
          p[i].randweight();
    }
    double learnConst = 0.1;
    tech->learnPerceptrons(p, learnConst);
}

void PrintRectangle::savePoints(bool clicked[][5], QString numberToLearnValue)
{
    numberToLearnValue = numberToLearnValue.simplified();
    numberToLearnValue.replace( " ", "" );

    QString filename="E:\\Sieci Neuronowe\\Perceptron\\points.txt";
    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream( &file );

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                stream << clicked[i][j];
            }
        }
        stream << numberToLearnValue << endl;
    }else{
        qDebug("%s", "Nie moge otworzyc pliku");
    }
    qDebug("%s", "Zakonczylem zapis...");
   // this->PrintRectangle(QWidget parent);
}

void PrintRectangle::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    int xpos=20;
    int ypos=20;
    int recWidth=50;
    int recHeight=50;

    for(int i=0; i<5; i++)
    {
        ypos=20;
        for(int j=0; j<5; j++)
        {
            QColor color = Qt::white;
            for(int k=0; k<points.size(); k++){

                  if( i == points[k].x() && j == points[k].y() )
                  {
                     color = Qt::black;
                  }

            }
            p.fillRect(xpos,ypos,recWidth,recHeight,color);
            ypos+=60;
        }
        xpos+=60;
    }
}

void PrintRectangle::mousePressEvent(QMouseEvent *ev)
{
    QPoint point = ev->pos();
    this->updateIndexFromPoint( point );
    update();
}

void PrintRectangle::updateIndexFromPoint(const QPoint &point)
{
    int x = point.x() - 20;
    int y = point.y() - 20;
    bool removed = false;

    if( ( (x >= 0 )  && ( x <= 300) ) && ( (y >= 0 )  && ( y <= 300) ) )
    {
        mXIndex = x / 60; //rec width + spacing
        mYIndex = y / 60; //rec height + spacing

        for(int k=0; k<points.size(); k++){
            if(points[k].x() == mXIndex && points[k].y() == mYIndex){
                points.remove(k);
                removed = true;
                clicked[mYIndex][mXIndex] = 0;
            }
        }

        if(!removed){
           clicked[mYIndex][mXIndex] = 1;
           points.append(QPoint(mXIndex,mYIndex));
        }
    }
}
