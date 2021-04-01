#include "player.h"
#include "ammo.h"
#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "enemy.h"
#include <stdlib.h>
#include <QMediaPlayer>

extern Game* game;

Player::Player()
{
    setPixmap(QPixmap(":/images/realCharacter.png"));
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/bulletSound.wav")); // rijesen i bullet sound kako sada stvari stoje
}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent * keyboardInput)
{
    if(keyboardInput->key() == Qt::Key_Right && pos().x() + 100 < scene()->width() && game->health->health != 0)
    {
        setPos(x()+15, y());
    }else if(keyboardInput->key() == Qt::Key_Left && pos().x() > 0 && game->health->health != 0)
    {
        setPos(x()-15, y());
    }else if(keyboardInput->key() == Qt::Key_Space  && game->health->health != 0)
    {

        Ammo * ammo = new Ammo();
        ammo->setPos(x() + 44 , y()+20);
        scene()->addItem(ammo);

        if(sound->state() == QMediaPlayer::PlayingState)
        {
            sound->setPosition(0);
        }else {
            sound->play();
        }
    }
}

