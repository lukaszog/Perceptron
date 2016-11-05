#include "printrectangle.h"
#include <QWidget>
#include <QPainter>


PrintRectangle::PrintRectangle(QWidget *parent) : QWidget(parent)
{
    this->resetClickedIndex();
}

void PrintRectangle::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    int xpos=20;
    int ypos=20;
    int recWidth=50;
    int recHeight=50;

    for(int k=0; k<points.size(); k++){

        qDebug("%d %d", points[k].x(), points[k].y());

    }

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

void PrintRectangle::resetClickedIndex()
{
    mXIndex = -1;
    mYIndex = -1;
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
    else
    {
       // resetClickedIndex();
    }
}
