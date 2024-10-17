#include "imgv_previewBar.h"
#include <QLabel>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qnamespace.h>

imgv_previewBar::imgv_previewBar (QWidget *parent) : QWidget (parent)
{

  box = new QHBoxLayout (this);
  box->setAlignment (Qt::AlignCenter);

  setStyleSheet ("background-color: rgba(70,70,70,80)");
}
void
imgv_previewBar::addBarIcon (QIcon &icon)
{

  qDebug () << "\nBarIconSlot";
  QPixmap pixmap = icon.pixmap (QSize (64, 64));
  QLabel *label = new QLabel ();
  label->setPixmap (pixmap);
  box->addWidget (label);
}
void
imgv_previewBar::clearBar ()
{
  QLayoutItem *item;
  while ((item = box->takeAt (0)) != NULL)
    {
      delete item->widget ();
      delete item;
      qDebug () << "\n ITEM CLEARED";
    }
}
