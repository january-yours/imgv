#include "imgv_previewBar.h"
#include <qboxlayout.h>
#include <QLabel>
#include <qlabel.h>
#include <qnamespace.h>



imgv_previewBar::imgv_previewBar(QWidget *parent):QWidget(){

    box = new QHBoxLayout(this);
    box->setAlignment(Qt::AlignCenter);

}
void imgv_previewBar::addBarIcon(QIcon &icon){
  

  qDebug()<<"\nBarIconSlot";
  QPixmap pixmap = icon.pixmap(QSize(64, 64));
  QLabel *label = new QLabel();
  label->setPixmap(pixmap);
  box->addWidget(label);

}
void imgv_previewBar::clearBar(){
  QLayoutItem* item;
  while ( ( item = box->takeAt( 0 ) ) != NULL )
  {
        delete item->widget();
        delete item;
        qDebug()<<"\n ITEM CLEARED";
  }

}
