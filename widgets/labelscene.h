#ifndef LABELSCENE_H
#define LABELSCENE_H

#include <QGraphicsScene>

#include "widgets_global.h"

class WIDGETS_EXPORT LabelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LabelScene(QObject *parent = nullptr);
    explicit LabelScene(const QRectF &sceneRect, QObject *parent = nullptr);
    explicit LabelScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    ~LabelScene();
};

#endif // LABELSCENE_H
