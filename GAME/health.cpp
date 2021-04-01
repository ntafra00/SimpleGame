#include "health.h"
#include "game.h"
#include <QFont>
#include <QObject>
#include <QDebug>

extern Game* game;

Health::Health()
{
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("comic sans", 16));
    setPos(0, game->score->boundingRect().height());
    setDefaultTextColor(Qt::red);
}

Health::~Health()
{
}

void Health::decreseHealth()
{

    if(health > 0)
    {
       --health;
       showHealth();
    }else if(health == 0)
    {
        game->theEnd();
    }


}

void Health::showHealth()
{
    setPlainText(QString("Health: ") + QString::number(health));
    setFont(QFont("comic sans", 16));
    setPos(0, game->score->boundingRect().height());
    setDefaultTextColor(Qt::red);
}


