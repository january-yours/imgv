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
#include <qgraphicsitem.h>
#include <QDir>

class imgv_viewport : public QGraphicsView
{
    Q_OBJECT
public:
    imgv_viewport(QWidget *parent = nullptr);
    //virtual ~imgv_viewport(){};
    void loadfile(QString &filename);
    QString currentDir;
    unsigned int i = 0;QStringList images;
private:
    QString basefilename = ":/base";
    void keyPressEvent(QKeyEvent *event) override;

    QGraphicsScene *scene;

    QString currentfilename;
    QImage qimage;
    QPixmap qpixmap;
    imgv_graphicsItem *qpixmapitem;
};















#endif //IMGV_VIEWPORT
