#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imgv_graphicsItem.h"
#include "imgv_viewport.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    imgv_viewport *viewport;
    
};
#endif // MAINWINDOW_H
