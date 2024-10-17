#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imgv_fileTree.h"
#include "imgv_previewBar.h"
#include "imgv_viewport.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow (QWidget *parent = nullptr);
  ~MainWindow ();

private:
  void resizeEvent (QResizeEvent *event) override;

  Ui::MainWindow *ui;
  imgv_viewport *viewport;
  imgv_fileTree *tree;
  imgv_previewBar *toolbar;
};
#endif // MAINWINDOW_H
