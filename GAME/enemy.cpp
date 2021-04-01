#include "enemy.h"
#include "game.h"
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include "enemy.h"


extern Game* game;

Enemy::Enemy(QGraphicsItem * parent):QGraphicsPixmapItem(parent)
{

    int randomPositionOnXAxis = rand() % 700;

    setPos(randomPositionOnXAxis, 0);
    setPixmap(QPixmap(":/images/lastPictureOfTheEnemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    QTimer * timer = new QTimer(this);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(attackPlayer()));

    timer->start(40);
}

void Enemy::attackPlayer()
{
    if(pos().y() > game->height())
    {
        game->health->decreseHealth();
        game->scene->removeItem(this);
        delete this;

        qDebug() << "Enemy deleted from the scene";
    }else
    {
        setPos(x(), y() + 15);

    }
}


