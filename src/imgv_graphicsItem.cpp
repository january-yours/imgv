#include "imgv_graphicsItem.h"
#include <qgraphicsitem.h>
#include <qobject.h>

imgv_graphicsItem::imgv_graphicsItem(QGraphicsPixmapItem *parent):QGraphicsPixmapItem(parent){

}

void imgv_graphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
  //  this->setPos(mapToScene(event->pos()));
    
    qDebug()<<"mouse event";
}
imgv_graphicsItem::~imgv_graphicsItem(){}





