#include <QWheelEvent>

#include "cvview.h"


CVView::CVView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void CVView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        qreal new_scale =  1.0 + event->angleDelta().y() * 0.00125;
        scale(new_scale, new_scale);
        event->accept();
    } else {
        event->ignore();
    }
}

