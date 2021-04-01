#include "leaderboard.h"
#include "leadingones.h"
#include <QtAlgorithms>

bool lessThan(leadingOnes l1, leadingOnes l2)
{
    return l1.score > l2.score;
}

leaderboard::leaderboard()
{
}

void leaderboard::doSortAndPop(QString string, int number)
{
    results.prepend(leadingOnes(string, number));

    std::sort(results.begin(), results.end(), lessThan);

    results.pop_back();

}

bool leaderboard::checkLeaderboard(int currentScore)
{
    QList<leadingOnes>::iterator iter;

    for(iter = results.begin(); iter != results.end(); ++iter)
    {
        if((*iter).score < currentScore)
        {
            return true;
        }
    }

    return false;
}


