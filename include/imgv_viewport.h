#ifndef IMGV_VIEWPORT_H
#define IMGV_VIEWPORT_H

#include "imgv_graphicsItem.h"
#include <QObject>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QImage>
#include <QImageReader>


class imgv_viewport : public QGraphicsView
{
    Q_OBJECT
public:
    imgv_viewport(QWidget *parent = nullptr);
    //virtual ~imgv_viewport(){};
    void loadfile(QString &filename);

private:
    QString basefilename = ":/base";
    
    QGraphicsScene *scene;

    QImage qimage;
    QPixmap qpixmap;
    imgv_graphicsItem *qpixmapitem;
};















#endif //IMGV_VIEWPORT
