#ifndef IMGV_GRAPHICS_ITEM_H
#define IMGV_GRAPHICS_ITEM_H

#include <QObject>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <qgraphicsitem.h>
#include <QGraphicsSceneMouseEvent>
#include <qgraphicssceneevent.h>
#include <qobject.h>

class imgv_graphicsItem : public QGraphicsPixmapItem{
  //  Q_OBJECT
public:
    explicit imgv_graphicsItem(QGraphicsPixmapItem *parent = nullptr);
    ~imgv_graphicsItem();
private:
   void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};















#endif //IMGV_GRAPHICS_ITEM
