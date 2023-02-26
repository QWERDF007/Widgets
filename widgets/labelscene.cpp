#include "labelscene.h"

LabelScene::LabelScene(QObject *parent)
    : QGraphicsScene(parent)
{

}

LabelScene::LabelScene(const QRectF &sceneRect, QObject *parent)
    : QGraphicsScene(sceneRect, parent)
{

}

LabelScene::LabelScene(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent)
{

}

LabelScene::~LabelScene()
{

}

void LabelScene::setMode(Mode mode)
{
    mode_ = mode;
}

void LabelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void LabelScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void LabelScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

