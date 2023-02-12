#include "cvgraphicsview.h"

CVGraphicsView::CVGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void CVGraphicsView::showImage(QString path)
{
    pixmap_ = QPixmap(path);
}

cv::Mat CVGraphicsView::getMat() const
{
    return mat_;
}
