#ifndef IMGV_PREVIEWBAR_H
#define IMGV_PREVIEWBAR_H

#include <QLabel>
#include <qboxlayout.h>
#include <qpixmap.h>
#include <qtmetamacros.h>
#include <qwidget.h>

class imgv_previewBar : public QWidget
{
  Q_OBJECT

public:
  imgv_previewBar (QWidget *parent = nullptr);
  ~imgv_previewBar () {};

public slots:
  void addBarIcon (QIcon &icon);
  void clearBar ();

private:
  QHBoxLayout *box;
  QList<QLabel> list;
};

#endif // IMGV_PREVIEWBAR_H
