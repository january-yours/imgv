#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imgv_graphicsItem.h"
#include "imgv_previewBar.h"
#include "imgv_viewport.h"
#include <QDir>
#include <qassert.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qdockwidget.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <QPixmapCache>
#include <qpixmapcache.h>
#include <QDockWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <qwidget.h>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewport = new imgv_viewport();

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setStyleSheet("background-color: rgba(110,110,110,30)");
    setCentralWidget(viewport);
    setStatusBar(nullptr);
   

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView();
    tree->setModel(model);

    QDockWidget *dockWidget = new QDockWidget();
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockWidget->setWidget(tree);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea); 
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures); 
    imgv_previewBar *toolbar = new imgv_previewBar();
      
    bool succsess = QObject::connect(viewport, &imgv_viewport::iconAdded, toolbar, &imgv_previewBar::addBarIcon);
    Q_ASSERT(succsess);
    qDebug()<<"\n SUCC IS: "<<succsess;

    viewport->testshit();

    QDockWidget *dock2 = new QDockWidget();
    dock2->setAllowedAreas(Qt::BottomDockWidgetArea);
    dock2->setWidget(toolbar);
        dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures); 
    addDockWidget(Qt::BottomDockWidgetArea, dock2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
