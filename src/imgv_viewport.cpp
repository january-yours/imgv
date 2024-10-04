#include "imgv_viewport.h"
#include "imgv_graphicsItem.h"
#include "imgv_previewBar.h"
#include <QDebug>
#include <qgraphicsitem.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <QDir>
#include <QPixmapCache>
#include <qpixmapcache.h>
#include <QKeyEvent>
#include <qpoint.h>
#include <qtypes.h>
#include <QScrollBar>


imgv_viewport::imgv_viewport(QWidget *parent):QGraphicsView(parent){
    auto *scene = new QGraphicsScene(0, 0, 0, 0, this);
    

    setScene(scene);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter); 
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

setTransformationAnchor(QGraphicsView::NoAnchor);
    loadfile(basefilename);
    qpixmapitem = new imgv_graphicsItem();
    qpixmapitem->setPixmap(qpixmap);
    qpixmapitem->setFlag(QGraphicsItem::ItemIsMovable);
    

    scaleFactor = 1.25;
    currentScale = 1.0;
    lastZoomEventPos = QPoint(0, 0);

    zoomBasis = transform();
    zoomBasisScaleFactor = 1.0;
    scene->addItem(qpixmapitem);

QPixmapCache::setCacheLimit(100240);
    QDir directory("/home/january/tmp/");

    currentDir = directory.path();
images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
foreach(QString filename, images) {
        QPixmap pixmap;
        if(!QPixmapCache::find(filename, &pixmap)){
            QString absoluteFilePath = directory.absoluteFilePath(filename);
            if(pixmap.load(absoluteFilePath)) {qDebug()<<"\nLoaded"<<filename;
            QPixmapCache::insert(filename, pixmap);
                QIcon icon(pixmap);
           }
        }
        
        //qDebug()<<"\n"<<filename;
    }
    currentfilename = images[i];
}

void imgv_viewport::testshit(){

        dir.setPath("/home/january/tmp/");
    foreach(QString filename, images){
        QPixmap pixmap;
        if(QPixmapCache::find(filename, &pixmap)){
        QIcon icon(pixmap);
            emit iconAdded(icon);
            qDebug()<<"\nEMIT";

        }



    }
}


void imgv_viewport::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_L){
            QDir directory(currentDir); 
            QString absoluteFilePath = directory.absoluteFilePath(currentfilename);
            loadfile (absoluteFilePath);i++;
           
            currentfilename = images[i];
            qpixmapitem->setPixmap(qpixmap);
            qpixmapitem->sceneBoundingRect();
            centerOn(qpixmapitem);
    }
}

void imgv_viewport::zoom(qreal scaleFactor, const QPoint &pos){

    currentScale *= scaleFactor;
    if (currentScale >= 400 || currentScale <= 0.1)
    {
        currentScale *= qPow(scaleFactor, -1);
        return;
    }

    const QPointF scenePos = mapToScene(pos);
    if (pos != lastZoomEventPos)
        lastZoomEventPos = pos;


    zoomBasisScaleFactor *= scaleFactor;
    setTransform(QTransform(zoomBasis).scale(zoomBasisScaleFactor, zoomBasisScaleFactor));
    absoluteTransform.scale(scaleFactor, scaleFactor);

    if (currentScale > 0.4)
    {
        const QPointF p1mouse = mapFromScene(scenePos);
        const QPointF move = p1mouse - pos;
        qDebug()<<"\nMapFromScene is: "<<p1mouse<<"\nmove is:"<<move;
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + (move.x()));
        verticalScrollBar()->setValue(verticalScrollBar()->value() + move.y());
    }
    else
    {
        centerOn(qpixmapitem);
    }
}

void imgv_viewport::wheelEvent(QWheelEvent *event){

    const QPoint eventPos = event->position().toPoint();
  const int yDelta = event->angleDelta().y();

    if (yDelta == 0)
        return;

    qreal zoomFactor = 1.5;
    if (yDelta < 0)
        zoomFactor = qPow(zoomFactor, -1);

    zoom(zoomFactor, eventPos);


}



void imgv_viewport::loadfile(QString &filename){
    
    qpixmap.load(filename);
    if (!qpixmap) 
        qDebug()<<"\nuebok";
    else 
        qDebug()<<"\n"<<filename;

}
