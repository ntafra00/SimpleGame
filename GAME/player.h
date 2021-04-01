#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsView>

class Player: public QObject, public QGraphicsPixmapItem
{
public:
    Player(); // constructor that spawns player on the scene
    ~Player();
    void keyPressEvent(QKeyEvent * keyboardInput); // function that helps player to move
private:
    QMediaPlayer * sound;
public slots:
    void makeEnemies();
};

#endif // PLAYER_H
