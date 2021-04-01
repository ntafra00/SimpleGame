#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = 0); // constructor
    void updateScore();
    void printScore();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
