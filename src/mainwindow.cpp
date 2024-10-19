#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imgv_fileTree.h"
#include "imgv_graphicsItem.h"
#include "imgv_keyFilter.h"
#include "imgv_previewBar.h"
#include "imgv_viewport.h"
#include <QDir>
#include <QDockWidget>
#include <QFileSystemModel>
#include <QLabel>
#include <QPixmapCache>
#include <QTreeView>
#include <qassert.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qdockwidget.h>
#include <qevent.h>
#include <qfilesystemmodel.h>
#include <qgraphicslayoutitem.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qpixmapcache.h>
#include <qwidget.h>
MainWindow::MainWindow (QWidget *parent)
    : QMainWindow (parent, Qt::FramelessWindowHint), ui (new Ui::MainWindow)
{
  ui->setupUi (this);
  viewport = new imgv_viewport ();

  setWindowFlags (Qt::FramelessWindowHint);
  setAttribute (Qt::WA_NoSystemBackground);
  setAttribute (Qt::WA_TranslucentBackground);
  setAttribute (Qt::WA_TransparentForMouseEvents);
  setStyleSheet ("background-color: rgba(110,110,110,30)");
  setCentralWidget (viewport);
  setStatusBar (nullptr);

  tree = new imgv_fileTree (this);
  toolbar = new imgv_previewBar (this);

  QObject::connect (viewport, &imgv_viewport::iconAdded, toolbar,
                    &imgv_previewBar::addBarIcon);
  QObject::connect (viewport, &imgv_viewport::treeToggle, tree,
                    &imgv_fileTree::hideToggle);
  QObject::connect (viewport, &imgv_viewport::newCache, toolbar,
                    &imgv_previewBar::clearBar);
  QObject::connect (tree, &imgv_fileTree::currentDirChanged, viewport,
                    &imgv_viewport::refreshCache);
  imgv_keyFilter *filter = new imgv_keyFilter ("main window", this);
  tree->installEventFilter (filter);
  viewport->installEventFilter (filter);
}
void
MainWindow::resizeEvent (QResizeEvent *event)
{
  tree->setGeometry ({ 0, 0, 250, 350 });
  toolbar->setGeometry ({ 0, this->height () - 50, this->width (), 50 });
}

MainWindow::~MainWindow () { delete ui; }
