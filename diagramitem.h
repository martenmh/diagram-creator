#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPolygonItem>
#include <QPen>
#include <QBrush>
#include "handles.h"
#include <QGraphicsAnchorLayout>



class DiagramItem : public QGraphicsItem
{
public:
    //properties for property panel:
    QPen borderColor;
    QBrush color;
    QSize size;

    Handles& handles;

    //methods for properties:
    void changeBorderColor();
    void changeInnerColor();
    //when changing from the properties panel (no mouse event)
    void changeSize();
    //when changing from the handles
    void resize(QGraphicsSceneMouseEvent*);


    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    //check whether the mouse button is on the item itself (base is only logic for a rectangle)


    enum Mode{Selected, None, Hover};

    // if selected add resize points
    // on hover show element and all arrows connected

    DiagramItem(QPointF*, QPointF*);




    DiagramItem();
    DiagramItem(int,int,int,int);
    DiagramItem(QPointF*,QPointF*,QPointF*,QPointF*);
    ~DiagramItem();

    void mouseDoublePressEvent();
    void setBoundingRect(QRectF*);
    void setBoundingRect(QRectF);
    void setBoundingRect(QPointF*, QPointF*);
    void setBoundingRect(QPointF, QPointF);
    QRectF boundingRect() const;

    // overriding paint()
    virtual void paint(QPainter * painter,
        const QStyleOptionGraphicsItem * option,
        QWidget * widget);

    // item state
    Mode state;
    bool Pressed;
    bool Overlappable;

    void prepareGeometryChange();

protected: //overriden methods

    //static double minHeight;
    void mousePressEvent(QGraphicsSceneMouseEvent* event);  //Select or see options (left or right mouse)
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);   //Move
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event); //selected
    //virtual method for setting the resizing handles

    QPointF topLeft;
    QPointF bottomRight;


};

#endif // DIAGRAMITEM_H

