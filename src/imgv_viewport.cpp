#include "imgv_viewport.h"
#include "imgv_fileTree.h"
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
#include <qwidget.h>
#include <QGraphicsProxyWidget>

imgv_viewport::imgv_viewport(QWidget *parent):QGraphicsView(parent){
    auto *scene = new QGraphicsScene(0, 0, 0, 0, this);
    

    setScene(scene);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter); 
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

setTransformationAnchor(QGraphicsView::NoAnchor);
    qpixmap.load(basefilename);

    qpixmapitem = new imgv_graphicsItem();
    qpixmapitem->setPixmap(qpixmap);
    qpixmapitem->setFlag(QGraphicsItem::ItemIsMovable);
    

    scaleFactor = 1.25;
    currentScale = 1.0;
    lastZoomEventPos = QPoint(0, 0);

    zoomBasis = transform();
    zoomBasisScaleFactor = 1.0;
    scene->addItem(qpixmapitem);

QPixmapCache::setCacheLimit(300240);

    dir.setCurrent("/home/january/tmp");
    currentDir = dir.currentPath();


    refreshCache(dir.currentPath());


}
void imgv_viewport::refreshCache(QString newDir){
    QPixmapCache::clear();
    images.clear();
    
    emit newCache();
    dir.setPath(newDir);
                /*qDebug()<<"\nNEW DIR FOR ENTRY LIST IS: "<<dir.currentPath();*/
    images = dir.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    qDebug()<<"IMAGES COUNT: "<<images.count();
    if(!images.count()){ qDebug()<<"\nEMPTY FOLDER"; nothingToShow = 1;} else{ nothingToShow = 0;
    
        currentfilename = images[0];
    /*foreach(QString filename, images) {qDebug()<<"entry list item!!!: "<< dir.absoluteFilePath(filename);};*/
        for(int k = 0; k < images.count(); k++) qDebug()<<"Image i="<<k<<" is "<<images[k];


    foreach(QString filename, images) {
        QPixmap pixmap;
        if(!QPixmapCache::find(filename, &pixmap)){
            QString absoluteFilePath = dir.absoluteFilePath(filename);
            if(pixmap.load(absoluteFilePath)) {
                qDebug()<<"Loaded"<<filename;
                QPixmapCache::insert(filename, pixmap);
                QIcon icon(pixmap);
                emit iconAdded(icon);
                
                /*qDebug()<<"\nEMIT NEW ICON";*/
            } else {qDebug()<<"\n OBOSRALSA LOAD PIXMAPA: "<< absoluteFilePath;};
        }
        
        //qDebug()<<"\n"<<filename;
    }

    }

}

void imgv_viewport::prevImage(){
 if(nothingToShow) return;

    if(i>0) i--; else i=images.count()-1;

    currentfilename = images[i];
    qpixmap.load(dir.absoluteFilePath(currentfilename));
    qpixmapitem->setPixmap(qpixmap);
    qpixmapitem->sceneBoundingRect();
    centerOn(qpixmapitem);

}
void imgv_viewport::nextImage(){
 if(nothingToShow) return;

    if(i<images.count()-1) i++; else i=0;

    currentfilename = images[i];
    qpixmap.load(dir.absoluteFilePath(currentfilename));
    qpixmapitem->setPixmap(qpixmap);
    qpixmapitem->sceneBoundingRect();
    centerOn(qpixmapitem);

}

void imgv_viewport::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_L){
        qDebug()<<"Current filename is: "<<currentfilename;
        nextImage();
        }
    else if(event->key() == Qt::Key_H){
        qDebug()<<"Current filename is: "<<currentfilename;
        prevImage();
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



