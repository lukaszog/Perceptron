#ifndef PRINTRECTANGLE_H
#define PRINTRECTANGLE_H

#include <QWidget>
#include <QMouseEvent>
#include <teacher.h>
#include <perceptron.h>


class PrintRectangle : public QWidget
{
    Q_OBJECT
public:
    explicit PrintRectangle(QWidget *parent = 0);

private:
    void resetClickedIndex();
    void updateIndexFromPoint( const QPoint& point);
public:
    int mXIndex;
    int mYIndex;
    QVector<QPoint> points;
    bool clicked[5][5] = {};
    teacher *tech;
    std::vector<std::vector<perceptron>> p;
    double techconst = 0.1;
    void savePoints(bool clicked[5][5], QString numberToLearnValue);
    QVector<QPoint> loadPoints();


signals:

public slots:
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *eventPress);
};

#endif // PRINTRECTANGLE_H
