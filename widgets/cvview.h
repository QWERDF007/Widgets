#ifndef CVVIEW_H
#define CVVIEW_H

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

#endif // CVVIEW_H
