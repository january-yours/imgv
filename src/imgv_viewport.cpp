#include "imgv_viewport.h"
#include "imgv_graphicsItem.h"
#include <QDebug>
#include <qgraphicsitem.h>
#include <qlogging.h>
#include <qnamespace.h>



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

}

void imgv_viewport::loadfile(QString &filename){
    
    qpixmap.load(filename);
    if (!qpixmap) 
        qDebug()<<"\nuebok";
    else 
        qDebug()<<"\n"<<filename;

}
