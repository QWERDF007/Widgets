#include <QImage>
#include <QBrush>
#include <QGraphicsItem>
#include "cvgraphicsview.h"

CVGraphicsView::CVGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
    setBackgroundBrush(QBrush(QColor(221,221,221)));
}

void CVGraphicsView::showImage(QString path)
{
    QPixmap pixmap(path);
    if (image_pixmap_) {
        image_pixmap_->setPixmap(pixmap);
    } else {
        image_pixmap_ =  scene()->addPixmap(pixmap);
    }
}

void CVGraphicsView::showImage(cv::Mat img)
{
    QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)img.data, img.cols, img.rows, QImage::Format_RGB888));
    if (image_pixmap_) {
        image_pixmap_->setPixmap(pixmap);
    } else {
        image_pixmap_ =  scene()->addPixmap(pixmap);
    }
}

cv::Mat CVGraphicsView::getMat() const
{
    return img_;
}

void CVGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    Q_UNUSED(event);
}
