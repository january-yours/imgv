#ifndef IMGV_FILETREE_H
#define IMGV_FILETREE_H

#include <qboxlayout.h>
#include <qevent.h>
#include <qfilesystemmodel.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qtreeview.h>
#include <qwidget.h>

class imgv_fileTree : public QTreeView
{
  Q_OBJECT

public:
  imgv_fileTree (QWidget *parent = nullptr);

public slots:
  void setCurrentDir (const QModelIndex &index);
  void hideToggle ();

signals:
  void currentDirChanged (QString currentDir);

private:
  void keyPressEvent (QKeyEvent *event) override;
  QFileSystemModel *model;
  QTreeView *tree;
  QVBoxLayout *box;
  QDir currentDirectory;
};

#endif // IMGV_FILETREE_H
