#include <QGraphicsItem>
#include <QWheelEvent>

#include "labelview.h"


LabelView::LabelView(QWidget *parent)
    : QGraphicsView{parent}
{

}

LabelView::LabelView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent)
{

}

LabelView::~LabelView()
{

}

void LabelView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete) {
        deleteItems();
    } else {
        QGraphicsView::keyPressEvent(event);
    }
}

void LabelView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QGraphicsView::mouseDoubleClickEvent(event);
}

void LabelView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

void LabelView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void LabelView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void LabelView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        qreal new_scale =  1.0 + event->angleDelta().y() * 0.00125;
        scale(new_scale, new_scale);
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void LabelView::deleteItems()
{
    if (scene()) {
        for (auto item : scene()->selectedItems()) {
            scene()->removeItem(item);
            delete item;
        }
    }
}

