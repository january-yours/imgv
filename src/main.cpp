#include "imgv_keyFilter.h"
#include "mainwindow.h"
#include <QApplication>

int
main (int argc, char *argv[])
{
  QApplication a (argc, argv);
  MainWindow w;
  /*imgv_keyFilter *keyFilter = new imgv_keyFilter ("From main", &a);*/
  /*a.installEventFilter (keyFilter);*/

  w.show ();
  return a.exec ();
}
