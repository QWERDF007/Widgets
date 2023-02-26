#ifndef LABELVIEW_H
#define LABELVIEW_H

#include <QGraphicsView>
#include <opencv2/opencv.hpp>
#include "widgets_global.h"

class WIDGETS_EXPORT LabelView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit LabelView(QWidget *parent = nullptr);
    explicit LabelView(QGraphicsScene *scene, QWidget *parent = nullptr);
    ~LabelView();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    Q_DISABLE_COPY(LabelView)

    void deleteItems();

};

#endif // LABELVIEW_H
