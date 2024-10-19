#include "imgv_keyFilter.h"
#include <QKeyEvent>
imgv_keyFilter::imgv_keyFilter (QString message, QObject *parent)
    : QObject (parent), m_message (message)
{
}
bool
imgv_keyFilter::eventFilter (QObject *dest, QEvent *event)
{
  if (event->type () == QEvent::KeyPress)
    {
      qDebug () << "Event hijacked by" << m_message;
      return true; // Event handled here. No need to propagate
    }
  return QObject::eventFilter (dest, event);
}
