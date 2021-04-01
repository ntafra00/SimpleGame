#include "score.h"
#include "game.h"
#include <QFont>


extern Game* game;

Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Your current score is: ") + QString::number(score));
    setFont(QFont("comic sans", 16));
    setDefaultTextColor(Qt::green);
}

void Score::updateScore()
{
    // function that will increase score

    score++;


    printScore();

}

void Score::printScore()
{
    if(game->health->health == 0)
    {
        setPlainText(QString("YOUR FINAL SCORE IS: ") + QString::number(score));
        setFont(QFont("times", 16));
        setDefaultTextColor(Qt::green);
    }else
    {
        setPlainText(QString("Your current score is: ") + QString::number(score));
        setFont(QFont("times", 16));
        setDefaultTextColor(Qt::green);
    }
}

int Score::getScore()
{
    return score;
}



