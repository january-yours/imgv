#include "imgv_fileTree.h"
#include <QHeaderView>
#include <qabstractitemmodel.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qfilesystemmodel.h>
#include <qnamespace.h>
#include <qtreeview.h>
#include <qtreewidget.h>
#include <qwidget.h>

imgv_fileTree::imgv_fileTree (QWidget *parent) : QTreeView (parent)
{

  box = new QVBoxLayout (this);

  setStyleSheet ("background-color: rgba(70,70,70,80)");
  setFocusPolicy (Qt::NoFocus);
  model = new QFileSystemModel ();
  model->setRootPath (QDir::homePath ());
  model->setFilter (QDir::AllDirs | QDir::NoDotAndDotDot);
  /*model->setNameFilters (QStringList () << "*.jpg");*/

  tree = new QTreeView ();
  tree->setModel (model);
  tree->setRootIndex (model->index (QDir::homePath ()));
  currentDirectory.setCurrent (QDir::homePath ());

  tree->header ()->hide ();
  tree->hideColumn (1);
  tree->hideColumn (2);
  tree->hideColumn (3);
  tree->hideColumn (4);
  tree->setAnimated (true);

  QObject::connect (tree, &QTreeView::expanded, this,
                    &imgv_fileTree::setCurrentDir);

  box->addWidget (tree);
}
void
imgv_fileTree::hideToggle ()
{

  if (this->isVisible ())
    this->hide ();
  else
    this->show ();
}
void
imgv_fileTree::keyPressEvent (QKeyEvent *event)
{
  if (event->key () == Qt::Key_J)
    {
      QModelIndex currentIndex = tree->currentIndex ();
      QModelIndex nextIndex = tree->indexBelow (currentIndex);
      if (nextIndex.isValid ())
        {
          tree->setCurrentIndex (nextIndex);
        }
    }

  else if (event->key () == Qt::Key_K)
    {
      QModelIndex currentIndex = tree->currentIndex ();
      QModelIndex nextIndex = tree->indexAbove (currentIndex);
      if (nextIndex.isValid ())
        {
          tree->setCurrentIndex (nextIndex);
        }
    }
  else if (event->key () == Qt::Key_Space)
    {
      QModelIndex currentIndex = tree->currentIndex ();
      if (tree->isExpanded (currentIndex))
        {
          tree->collapse (currentIndex);
        }
      else
        {
          tree->expand (currentIndex);
        }
    }
  else
    {
      QTreeView::keyPressEvent (event);
    }
}

void
imgv_fileTree::setCurrentDir (const QModelIndex &index)
{
  currentDirectory.setCurrent (model->filePath (index));
  emit currentDirChanged (currentDirectory.currentPath ());
}
