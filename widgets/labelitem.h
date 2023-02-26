#ifndef LABELITEM_H
#define LABELITEM_H

#include <QGraphicsItem>

#include "widgets_global.h"

class WIDGETS_EXPORT LabelItem : public QGraphicsItem
{
public:
    explicit LabelItem(QGraphicsItem *parent = nullptr);
    ~LabelItem();

private:
    Q_DISABLE_COPY(LabelItem)
};

#endif // LABELITEM_H
