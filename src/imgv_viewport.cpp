#include "imgv_viewport.h"
#include <QDebug>
#include <qlogging.h>



imgv_viewport::imgv_viewport(QWidget *parent):QGraphicsView(parent){
    auto *scene = new QGraphicsScene(-1.0, -1.0, 2.0, 2.0, this);
    setScene(scene);
    setAttribute(Qt::WA_TranslucentBackground);
    
    loadfile(basefilename);
    qpixmapitem = new QGraphicsPixmapItem();
    qpixmapitem->setPixmap(qpixmap);
    scene->addItem(qpixmapitem);

}

void imgv_viewport::loadfile(QString &filename){
    
    qpixmap.load(filename);
    if (!qpixmap) 
        qDebug()<<"\nuebok\n"<<filename;
    else 
        qDebug()<<"\n"<<filename;

}
