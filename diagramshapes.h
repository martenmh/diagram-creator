#ifndef SHAPES_H
#define SHAPES_H

#include "diagramitem.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPathItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>

class SelectableArea : public DiagramItem
{
    SelectableArea();
    ~SelectableArea();
};

class Line : public DiagramItem
{
public:
    Line();
    Line(QPointF*, QPointF*);

    void setFirstPointPos(QPointF val);
    void setLastPointPos(QPointF val);

    DiagramItem* firstElement;
    DiagramItem* lastElement;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    void setPos(const QPointF &pos);
    virtual QPainterPath shape() const;
    QPointF closestPoint(QPointF) const;

protected:

    QPainterPath path;
    QGraphicsPathItem pathItem;
    QVector<QGraphicsLineItem> lines;

    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
};

class SimpleText : public DiagramItem
{
public:
    SimpleText();
    SimpleText(QPointF*, QPointF*);

protected:
    QString text;
    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
private:
};

class Text : public DiagramItem, QGraphicsTextItem
{
public:
    Text();
    Text(QPointF*, QPointF*);
protected:
    QString text;
    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
};

class Rectangle : public DiagramItem
{
public:
    Rectangle();
    Rectangle(QPointF*, QPointF*);
protected:
    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
};

class Ellipse : public DiagramItem
{
public:
    Ellipse(QPointF*, QPointF*);
    Ellipse();

protected:
    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
};

class Image : public DiagramItem
{
public:
    Image(QPointF*, QPointF*);
    Image();

protected:
    QImage image;
    void setHandles();
    void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);
};
#endif // SHAPES_H
