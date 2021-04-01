#ifndef CLICK_H
#define CLICK_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QObject>


class Click:public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    Click(QString toBeDisplayed, QGraphicsItem * parent = 0); // constructor of the class

    void hoverLeaveEvent(QGraphicsSceneHoverEvent * hoverLeaveEvent); // function that will handle hoverLeaveEvent
    void hoverEnterEvent(QGraphicsSceneHoverEvent * hoverEnterEvent); // function that will handle hoverEnterEvent
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent); // function that will handle mouse input

private:
    QGraphicsTextItem * textOfTheButton;

signals:
    void pressed();

};

#endif // CLICK_H
