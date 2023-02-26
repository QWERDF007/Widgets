#ifndef LABELVIEW_H
#define LABELVIEW_H

#include <QGraphicsView>
#include <opencv2/opencv.hpp>
#include "widgets_global.h"

class WIDGETS_EXPORT CVView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CVView(QWidget *parent = nullptr);

protected:

    void wheelEvent(QWheelEvent *event) override;

private:

signals:

};

#endif // LABELVIEW_H
