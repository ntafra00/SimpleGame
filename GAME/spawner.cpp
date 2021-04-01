#include "spawner.h"
#include <QTimer>
#include "enemy.h"
#include "game.h"
#include <QDebug>

extern Game* game;

Spawner::Spawner()
{
    spawnersTimer = NULL;
}

void Spawner::makeEnemies()
{
   if(game->health->health > 0)
   {
       Enemy * opponent = new Enemy();
       game->scene->addItem(opponent);
   }
}


