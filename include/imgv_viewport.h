#ifndef IMGV_VIEWPORT_H
#define IMGV_VIEWPORT_H

#include "imgv_graphicsItem.h"
#include <QDir>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
#include <QImageReader>
#include <QObject>
#include <QPixmap>
#include <qgraphicsitem.h>
#include <qlist.h>

class imgv_viewport : public QGraphicsView
{
  Q_OBJECT
public:
  imgv_viewport (QWidget *parent = nullptr);
  // virtual ~imgv_viewport(){};
  QStringList images;

  void zoom (qreal scaleFactor, const QPoint &pos = QPoint (0, 0));

  void testshit ();
  void refreshCache (QString newDir);

  QDir dir;
  QString currentDir;
  unsigned int i = 0;

signals:
  void iconAdded (QIcon &icon);
  void newCache ();
  void treeToggle ();
  void keyPressed (QKeyEvent *);

protected:
  void wheelEvent (QWheelEvent *event) override;

private:
  QString basefilename = ":/base";
  void keyPressEvent (QKeyEvent *event) override;
  void nextImage ();
  void prevImage ();
  bool nothingToShow;

  QGraphicsScene *scene;

  QString currentfilename;
  QPixmap qpixmap;
  imgv_graphicsItem *qpixmapitem;

  qreal scaleFactor;
  qreal currentScale;
  QPoint lastZoomEventPos;
  QTransform absoluteTransform;
  QTransform zoomBasis;
  qreal zoomBasisScaleFactor;
};

#endif // IMGV_VIEWPORT
