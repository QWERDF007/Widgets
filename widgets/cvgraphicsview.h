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

    cv::Mat getMat() const;

protected:


private:
    QPixmap pixmap_;

    cv::Mat mat_;

signals:

};

#endif // CVGRAPHICSVIEW_H
