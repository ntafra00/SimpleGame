#include "ammo.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>
#include "enemy.h"
#include "score.h"
#include <QList>

extern Game* game;

Ammo::Ammo()
{
    setRect(0,0,5,30);
    setBrush(QBrush(Qt::red));

    QTimer * timer = new QTimer(this);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveBullet()));

    timer->start(25);

}

void Ammo::moveBullet()
{

    QList<QGraphicsItem *>thingsThatBulletCollidesWith = collidingItems();
    int numberOfItems = collidingItems().size();

    for(int i = 0; i < numberOfItems; i++)
    {
        if(typeid(*(thingsThatBulletCollidesWith[i])) == typeid (Enemy))
        {
            // remove them both from the scene and then delete them

            game->scene->removeItem(thingsThatBulletCollidesWith[i]);
            game->scene->removeItem(this);

            delete this;
            delete thingsThatBulletCollidesWith[i];

            game->score->updateScore();

            return;
        }
    }


    if(pos().y() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet is deleted";
    }else
    {
        setPos(x(), y()-10);
    }

}
