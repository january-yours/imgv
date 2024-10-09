#ifndef IMGV_FILETREE_H
#define IMGV_FILETREE_H

#include <qboxlayout.h>
#include <qevent.h>
#include <qfilesystemmodel.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qtreeview.h>
#include <qtreewidget.h>
#include <qwidget.h>
#include <QTreeWidget>

class imgv_fileTree: public QTreeView {
Q_OBJECT

public:
  imgv_fileTree(QWidget *parent = nullptr);

public slots:
  void setCurrentDir(const QModelIndex &index);

signals:
  void currentDirChanged(QString currentDir);


private:
  
  QFileSystemModel *model;
  QTreeView *tree;
  QVBoxLayout *box;
  QDir currentDirectory;

};









#endif //IMGV_FILETREE_H
