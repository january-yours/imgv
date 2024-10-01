#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imgv_graphicsItem.h"
#include "imgv_viewport.h"
#include <QDir>
#include <qcontainerfwd.h>
#include <qgridlayout.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <QPixmapCache>
#include <qpixmapcache.h>

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
    setStyleSheet("background-color: rgba(10,10,10,0)");
    setCentralWidget(viewport);
    setStatusBar(nullptr);


}

MainWindow::~MainWindow()
{
    delete ui;
}
