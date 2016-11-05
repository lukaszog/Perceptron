#ifndef PRINTRECTANGLE_H
#define PRINTRECTANGLE_H

#include <QWidget>
#include <QMouseEvent>


class PrintRectangle : public QWidget
{
    Q_OBJECT
public:
    explicit PrintRectangle(QWidget *parent = 0);

private:
    void resetClickedIndex();
    void updateIndexFromPoint( const QPoint& point);
private:
    int mXIndex;
    int mYIndex;
    QVector<QPoint> points;

signals:

public slots:
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *eventPress);
};

#endif // PRINTRECTANGLE_H
