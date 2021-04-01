#include "game.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QString>
#include <QImage>
#include <QTimer>
#include <QDebug>
#include "enemy.h"
#include "click.h"
#include <list>
#include <QGraphicsRectItem>
#include <QFile>
#include <ctype.h>


Game::Game()
{

    scene = new QGraphicsScene();

    setScene(scene);

    // disable scrollbar and make scene equal with view

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);
    scene->setSceneRect(0,0, 1024, 768);

    readFromFile();
}

void Game::menu()
{
    scene->setBackgroundBrush(QImage(":/images/newBackgroundImage.png"));

    QGraphicsTextItem * nameOfTheGame = new QGraphicsTextItem(QString("SPACE SHOOTER"));
    nameOfTheGame->setFont(QFont("comic sans", 50));
    nameOfTheGame->setDefaultTextColor(Qt::red);
    nameOfTheGame->setPos(width()/2 - nameOfTheGame->boundingRect().width()/2, 100);
    scene->addItem(nameOfTheGame);


    Click * playButton = new Click("PLAY");
    playButton->setPos(this->width()/2 - playButton->boundingRect().width()/2, 300);
    scene->addItem(playButton);
    connect(playButton, SIGNAL(pressed()), this, SLOT(startGame()));


    Click * exitButton = new Click("EXIT");
    exitButton->setPos(this->width()/2 - exitButton->boundingRect().width()/2, 400);
    scene->addItem(exitButton);
    connect(exitButton, SIGNAL(pressed()), this, SLOT(endGame()));

    Click * leaderBoard = new Click("RECORDS");
    leaderBoard->setPos(this->width()/2 - leaderBoard->boundingRect().width()/2, 500);
    scene->addItem(leaderBoard);
    connect(leaderBoard, SIGNAL(pressed()), this, SLOT(showRecords()));

}

void Game::displayMenuForGameOver()
{
    Click * exitButton = new Click("EXIT");
    exitButton->setPos(this->width()/2 - exitButton->boundingRect().width()/2, 400);
    scene->addItem(exitButton);
    connect(exitButton, SIGNAL(pressed()), this, SLOT(endGame()));

}

void Game::theEnd()
{

    int playerScore = score->getScore();

    if(leaderboard.checkLeaderboard(playerScore))
    {

        QString nicknameOfThePlayer;
        dialog dialogForLeaderboard;

        int returnValue = dialogForLeaderboard.exec();

        if(returnValue == QDialog::Accepted)
        {
            nicknameOfThePlayer = dialogForLeaderboard.lineEdit->text();
            writeInFile(nicknameOfThePlayer, playerScore);
            leaderboard.results.clear();
            //readFromFile();

        }
    }

    displayMenuForGameOver();
}

void Game::writeInFile(QString name, int score)
{
    QFile file(""); // leaderboard won't work without rigth path to the folder where leaderboard file exists

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File does not exist or failed to create";
    }else
    {
        leaderboard.doSortAndPop(name, score);

        QTextStream stream(&file);

        for(int i = 0; i < 5; i++)
        {

            stream << leaderboard.results[i].nickname << Qt::endl;
            stream << leaderboard.results[i].score << Qt::endl;
        }
    }

    file.flush();
    file.close();

}

void Game::readFromFile()
{
    QFile file(""); // leaderboard won't work without rigth path to the folder where leaderboard file exists

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File does not exist or failed to create";
    }else
    {
           QTextStream in(&file);
           QString fromFile;

           for(int i = 0; i < 5; i++)
           {
               QString tempName = "";
               int tempScore = 0;

               fromFile = in.readLine();
               tempName = fromFile;

               fromFile = in.readLine();
               tempScore = fromFile.toInt();

               leaderboard.results.append(leadingOnes(tempName, tempScore));
           }
    }

    file.flush();
    file.close();
}

void Game::startGame()
{
    scene->clear();

    setBackgroundBrush(QImage(":/images/newBackgroundImage.png"));

    player = new Player();

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    player->setPos(width()/2, 668);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    scene->addItem(health);

    spawner = new Spawner();
    spawner->spawnersTimer = new QTimer(spawner);

    QObject::connect(spawner->spawnersTimer, SIGNAL(timeout()), spawner, SLOT(makeEnemies()));

    spawner->spawnersTimer->start(1700);

}

void Game::showRecords()
{
    scene->clear();

    QGraphicsTextItem * nameOfTheGame = new QGraphicsTextItem(QString("RECORDS"));
    nameOfTheGame->setFont(QFont("comic sans", 40));
    nameOfTheGame->setDefaultTextColor(Qt::red);
    nameOfTheGame->setPos(width()/2 - nameOfTheGame->boundingRect().width()/2, 100);
    scene->addItem(nameOfTheGame);

    QList<leadingOnes>::iterator iter;

    int y = 300;


    for(iter = leaderboard.results.begin(); iter != leaderboard.results.end(); ++iter)
    {
        QGraphicsTextItem * nameAndScore = new QGraphicsTextItem;

        nameAndScore->setFont(QFont("comic sans", 20));
        nameAndScore->setDefaultTextColor(Qt::yellow);
        nameAndScore->setPlainText(QString((*iter).nickname) + "  " + QString::number((*iter).score));
        nameAndScore->setPos(width()/2 - nameAndScore->boundingRect().width()/2, y);
        scene->addItem(nameAndScore);

        y += 30;
    }

    Click * exitButton = new Click("CLOSE");
    exitButton->setPos(this->width()/2 - exitButton->boundingRect().width()/2, 500);
    scene->addItem(exitButton);
    connect(exitButton, SIGNAL(pressed()), this, SLOT(clearAndDisplay()));

}


Game::~Game()
{
    delete scene;
    qDebug() << "Scene is deleted";

}

void Game::clearAndDisplay()
{
    scene->clear();
    menu();
}

void Game::endGame()
{
    scene->clear();
    close();
    deleteLater();
}



