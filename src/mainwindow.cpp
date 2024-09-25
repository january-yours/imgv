#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imgv_viewport.h"

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
    setStyleSheet("background-color: rgba(0,0,0,0)");

    setCentralWidget(viewport);


}

MainWindow::~MainWindow()
{
    delete ui;
}
