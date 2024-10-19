#ifndef IMGV_KEYFILTER_H
#define IMGV_KEYFILTER_H

#include <qobject.h>
#include <qtmetamacros.h>
class imgv_keyFilter : public QObject
{
  Q_OBJECT

public:
  explicit imgv_keyFilter (QString message, QObject *parent = nullptr);

protected:
  bool eventFilter (QObject *dest, QEvent *event);

private:
  QString m_message;
};

#endif // IMGV_KEYFILTER
