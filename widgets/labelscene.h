#ifndef LABELSCENE_H
#define LABELSCENE_H

#include <QGraphicsScene>

#include "widgets_global.h"

class WIDGETS_EXPORT LabelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode {
        InsertItem,
        MoveItem,
    };

    explicit LabelScene(QObject *parent = nullptr);
    explicit LabelScene(const QRectF &sceneRect, QObject *parent = nullptr);
    explicit LabelScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    ~LabelScene();

public slots:
    void setMode(LabelScene::Mode mode);

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Q_DISABLE_COPY(LabelScene);

    Mode mode_{InsertItem};

};

#endif // LABELSCENE_H
