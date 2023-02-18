#include "cvgraphicspixmapitem.h"

CVGraphicsPixmapItem::CVGraphicsPixmapItem(QGraphicsItem *parent)
    : QGraphicsPixmapItem{parent}
{
    setAcceptDrops(true);
}
