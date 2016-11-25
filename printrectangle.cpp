#include "printrectangle.h"
#include <QWidget>
#include <QPainter>

PrintRectangle::PrintRectangle(QWidget *parent) : QWidget(parent),
    p(5, std::vector<perceptron>(5))
{
    tech = new teacher(clicked);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            p[i][j].randweight();
        }
    }
    double learnConst = 0.1;

    tech->learnPerceptrons(p);
}

void PrintRectangle::savePoints(QVector<QPoint> points)
{
    QFile file("points.bin");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << points;
        file.close();
    }
}

QVector<QPoint> PrintRectangle::loadPoints()
{
    QFile file("points.bin");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        in >> points;
        file.close();
    }
    return points;
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
                     clicked[i][j] = 1;
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

            qDebug("%d %d", points[k].x(), points[k].y());

            if(points[k].x() == mXIndex && points[k].y() == mYIndex){

                points.remove(k);
                removed = true;
            }

        }

        if(!removed){
           points.append(QPoint(mXIndex,mYIndex));
        }
    }
}
