#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>


class Enemy: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0); // constructor of the class
public slots:
    void attackPlayer(); // function that will enable enemies to move
};

#endif // ENEMY_H

