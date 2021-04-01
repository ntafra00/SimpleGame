#ifndef AMMO_H
#define AMMO_H
#include <QGraphicsRectItem>
#include <QObject>

class Ammo: public QObject, public QGraphicsRectItem{
Q_OBJECT
public:
    Ammo(); // constructor;
public slots:
    void moveBullet(); // function that will make bullet move
};

#endif // AMMO_H

