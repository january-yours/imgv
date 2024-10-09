#include "imgv_fileTree.h"
#include <qabstractitemmodel.h>
#include <qboxlayout.h>
#include <qcontainerfwd.h>
#include <qfilesystemmodel.h>
#include <qtreeview.h>
#include <qtreewidget.h>
#include <qwidget.h>
#include <QHeaderView>

imgv_fileTree::imgv_fileTree(QWidget *parent):QTreeView(parent){

    box = new QVBoxLayout(this);
    
    setStyleSheet("background-color: rgba(70,70,70,80)");
    model = new QFileSystemModel();
    model->setRootPath(QDir::homePath());
    model->setFilter(QDir::AllDirs| QDir::Files| QDir::NoDotAndDotDot);
    model->setNameFilters(QStringList()<<"*.jpg");
    

    tree = new QTreeView();
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::homePath())); 
    currentDirectory.setCurrent(QDir::homePath());

    tree->header()->hide();
    tree->hideColumn(1);
    tree->hideColumn(2);
    tree->hideColumn(3);
    tree->hideColumn(4);
    tree->setAnimated(true);
    bool succsess2 = QObject::connect(tree, &QTreeView::expanded, this, &imgv_fileTree::setCurrentDir);
    
    qDebug()<<"\nConnect is: "<<succsess2;
  
    box->addWidget(tree);

}

void imgv_fileTree::setCurrentDir(const QModelIndex &index){

    currentDirectory.setCurrent(model->filePath(index));
//qDebug() << "Item expanded: " << model->filePath(index);

qDebug()<<"\n WOWZERS! CURRENT DIR IS: "<< currentDirectory.currentPath();
    emit currentDirChanged(currentDirectory.currentPath());    
}
