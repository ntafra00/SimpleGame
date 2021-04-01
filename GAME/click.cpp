#include "game.h"
#include "click.h"
#include <QBrush>
#include <QGraphicsSceneHoverEvent>
#include <QDebug>

extern Game* game;

Click::Click(QString toBeDisplayed, QGraphicsItem * parent):QGraphicsRectItem(parent)
{
    setRect(0,0, 200,50);

    QBrush backgroundBrush;
    backgroundBrush.setStyle(Qt::SolidPattern);
    backgroundBrush.setColor(Qt::blue);
    setBrush(backgroundBrush);

    textOfTheButton = new QGraphicsTextItem(this);
    textOfTheButton->setPlainText(toBeDisplayed);
    textOfTheButton->setDefaultTextColor(Qt::yellow);
    textOfTheButton->setFont(QFont("comic sans",20));
    textOfTheButton->setPos(rect().width()/2 - textOfTheButton->boundingRect().width()/2, rect().height()/2 - textOfTheButton->boundingRect().height()/2);

    setAcceptHoverEvents(true);

}

void Click::hoverLeaveEvent(QGraphicsSceneHoverEvent *hoverLeaveEvent)
{
    QBrush backgroundBrush;
    backgroundBrush.setStyle(Qt::SolidPattern);
    backgroundBrush.setColor(Qt::blue);

    setBrush(backgroundBrush);
}

void Click::hoverEnterEvent(QGraphicsSceneHoverEvent *hoverEnterEvent)
{
    QBrush backgroundBrush;
    backgroundBrush.setStyle(Qt::SolidPattern);
    backgroundBrush.setColor(Qt::darkBlue);
    setBrush(backgroundBrush);
}

void Click::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << "Mouse is pressed";
    emit pressed();
}
