#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health();
    ~Health();
    void decreseHealth(); // function that will decrease health
    void showHealth(); // function that will print health
    int health;
};

#endif // HEALTH_H
