#include "imgv_viewport.h"
#include "imgv_graphicsItem.h"
#include <QDebug>
#include <qgraphicsitem.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <QDir>
#include <QPixmapCache>
#include <qpixmapcache.h>
#include <QKeyEvent>
imgv_viewport::imgv_viewport(QWidget *parent):QGraphicsView(parent){
    auto *scene = new QGraphicsScene(-1.0, -1.0, 3.0, 3.0, this);
    

    setScene(scene);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter); 
    loadfile(basefilename);
    qpixmapitem = new imgv_graphicsItem();
    qpixmapitem->setPixmap(qpixmap);
    qpixmapitem->setFlag(QGraphicsItem::ItemIsMovable);
    

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
            }
        }
        
        //qDebug()<<"\n"<<filename;
    }
    currentfilename = images[i];
}
void imgv_viewport::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_L){
            QDir directory(currentDir); 
            QString absoluteFilePath = directory.absoluteFilePath(currentfilename);
            loadfile (absoluteFilePath);i++;
           
            currentfilename = images[i];
            qpixmapitem->setPixmap(qpixmap);
    }
}
void imgv_viewport::loadfile(QString &filename){
    
    qpixmap.load(filename);
    if (!qpixmap) 
        qDebug()<<"\nuebok";
    else 
        qDebug()<<"\n"<<filename;

}
