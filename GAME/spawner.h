#ifndef SPAWNER_H
#define SPAWNER_H

#include <QObject>
#include <QTimer>

class Spawner: public QObject{
Q_OBJECT
public:
    QTimer * spawnersTimer;
    Spawner();
public slots:
    void makeEnemies();
};

#endif // SPAWNER_H
