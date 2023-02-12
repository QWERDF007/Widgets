#include <QImage>
#include <QGraphicsItem>
#include "cvgraphicsview.h"

CVGraphicsView::CVGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void CVGraphicsView::showImage(QString path)
{
    QPixmap pixmap(path);
    if (!is_init) {
        image_pixmap_ =  scene()->addPixmap(pixmap);
        is_init = true;
    } else {
        image_pixmap_->setPixmap(pixmap);
    }
}

void CVGraphicsView::showImage(cv::Mat img)
{
    QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*)img.data, img.cols, img.rows, QImage::Format_RGB888));
    if (!is_init) {
        image_pixmap_ =  scene()->addPixmap(pixmap);
        is_init = true;
    } else {
        image_pixmap_->setPixmap(pixmap);
    }
}

cv::Mat CVGraphicsView::getMat() const
{
    return img_;
}
