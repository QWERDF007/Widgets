#ifndef CVGRAPHICSVIEW_H
#define CVGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include "widgets_global.h"

class WIDGETS_EXPORT CVGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CVGraphicsView(QWidget *parent = nullptr);

    void showImage(QString path);

    void showImage(cv::Mat img);

    cv::Mat getMat() const;

protected:


private:
    cv::Mat img_;

    bool is_init{false};

    QGraphicsPixmapItem *image_pixmap_{nullptr};

signals:

};

#endif // CVGRAPHICSVIEW_H
