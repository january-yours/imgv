#ifndef IMGV_GRAPHICS_ITEM_H
#define IMGV_GRAPHICS_ITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QObject>
#include <QPixmap>
#include <qgraphicsitem.h>
#include <qgraphicssceneevent.h>
#include <qobject.h>

class imgv_graphicsItem : public QGraphicsPixmapItem
{
  //  Q_OBJECT
public:
  explicit imgv_graphicsItem (QGraphicsPixmapItem *parent = nullptr);
  ~imgv_graphicsItem ();

private:
  void mousePressEvent (QGraphicsSceneMouseEvent *event) override;
};

#endif // IMGV_GRAPHICS_ITEM
