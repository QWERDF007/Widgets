#ifndef CVPIXMAPITEM_H
#define CVPIXMAPITEM_H

#include <QPen>
#include <QGraphicsPixmapItem>

#include <opencv2/opencv.hpp>

#include "widgets_global.h"

class WIDGETS_EXPORT CVPixmapItem : public QGraphicsPixmapItem
{
public:
    explicit CVPixmapItem(QGraphicsItem *parent = nullptr);

    void showImage(cv::Mat img);

    /**
     * @brief showImage
     * @param path
     */
    void showImage(QString &path);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief 实现图像移动
     * @param event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:

    QPen pen_;
};

#endif // CVPIXMAPITEM_H
