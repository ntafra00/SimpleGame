#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include "spawner.h"
#include "score.h"
#include <QObject>
#include "health.h"
#include "leaderboard.h"
#include "dialog.h"

class Game:public QGraphicsView{
Q_OBJECT
public:
    Game();
    ~Game();

    Player * player;
    QGraphicsScene * scene;
    Spawner * spawner; // custom class that will spawn enemies
    Health * health;
    Score * score;
    leaderboard leaderboard;



    void menu() ;
    void displayMenuForGameOver();
    void theEnd();
    void writeInFile(QString, int); // function that will write in the file
    void readFromFile(); // function that will read content from the file

public slots:
    void startGame(); // function that will make game start
    void showRecords(); // function that will print scores
    void clearAndDisplay();
    void endGame();
};

#endif // GAME_H
