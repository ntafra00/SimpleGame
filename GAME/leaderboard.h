#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QString>
#include <QList>
#include "leadingones.h"


class leaderboard
{
public:
    leaderboard();
    void doSortAndPop(QString, int);
    bool checkLeaderboard(int);

    QList<leadingOnes> results;


};

#endif // LEADERBOARD_H
