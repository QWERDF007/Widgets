#include <QPixmap>
#include <QCursor>
#include <QPainter>
//#include <QColor>
#include <QGraphicsSceneMouseEvent>

#include "cvpixmapitem.h"

CVPixmapItem::CVPixmapItem(QGraphicsItem *parent)
    : QGraphicsPixmapItem{parent}, pen_(QColor(72,178, 234), 2)
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

void CVPixmapItem::showImage(cv::Mat img)
{
    QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)img.data, img.cols, img.rows, QImage::Format_RGB888));
    setPixmap(pixmap);
}

void CVPixmapItem::showImage(QString &path)
{
    QPixmap pixmap(path);
    setPixmap(pixmap);
}

QRectF CVPixmapItem::boundingRect() const
{
    QRectF rect = QGraphicsPixmapItem::boundingRect();
    qreal offset =  pen_.width() + 2;
    return rect.adjusted(-offset, -offset, offset, offset);
}

void CVPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!pixmap().isNull()) {
        painter->setPen(pen_);
        painter->drawRect(boundingRect());
    }
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void CVPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
}

void CVPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF dist = event->pos() - event->lastPos();
    moveBy(dist.rx(), dist.ry());
}

void CVPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}
