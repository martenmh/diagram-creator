#include "toolbar.h"
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QToolBar>
#include "mainwindow.h"
#include <QMessageBox>
#include <QStandardItem>
#include <QDebug>
#include <QFileSystemModel>




Toolbar::Toolbar()
{

CreateTools();



        QFile styleSheet("/home/marten/projects/diagram-creator/toolbar.qss");
        if(!styleSheet.open(QFile::ReadOnly))
                QMessageBox::information(nullptr, "Error", styleSheet.errorString());
        QString StyleSheet = QLatin1String(styleSheet.readAll());

        this->setStyleSheet(StyleSheet);

//        QFile styleSheet("/home/marten/projects/diagram-creator/toolbar.qss");
//        if(!styleSheet.open(QFile::ReadOnly))
//                QMessageBox::information(nullptr, "Error", styleSheet.errorString());
//        QString StyleSheet = QLatin1String(styleSheet.readAll());


//        this->setStyleSheet(StyleSheet);

}
Toolbar::~Toolbar(){
}

/* (Tree) For example:
 *
 * Class: (Category)
 *  table (Tool)
 * Relations:
 *  One to many
 *  One to one
 *  Many to many
 * Shapes:
 *  Ellipse
 *  Rectangle
*/
void Toolbar::CreateCategories(){

}
void Toolbar::CreateTools(){

    QTreeWidgetItem* wiptr = nullptr;
    for(auto category : {"Shapes", "Drawing"}){
        wiptr = new QTreeWidgetItem(QStringList(category), 0);
        this->addTopLevelItem(wiptr);
        categories.append(wiptr);
    }


    for(auto tool : {"Rectangle", "Ellipse", "Line", "Image", "SimpleText", "Text"}){
        wiptr = new QTreeWidgetItem(QStringList(tool), 0);
        categories[0]->addChild(wiptr);
        tools.append(wiptr);
    }

    for(auto tool : {"Pen", "Eraser"}){
        wiptr = new QTreeWidgetItem(QStringList(tool), 0);
        categories[1]->addChild(wiptr);
        tools.append(wiptr);
    }
    this->expandAll();


}


void Toolbar::currentChanged(const QModelIndex &current, const QModelIndex &previous){
    diagramScene->setMode(diagramScene->DrawObject);


    qDebug() << current.row();

qDebug() << this->model();
    switch(current.row()){


        case 0:
            //selection = SelectedItem::Rectangle;
            selection = SelectedItem::Rectangle;
        break;
        case 1:
            selection = SelectedItem::Ellipse;
        break;
        case 2:
            selection = SelectedItem::Line;

        break;
        case 3:
            selection = SelectedItem::Image;
        break;
        case 4:
            selection = SelectedItem::SimpleText;
        break;
        case 5:
            selection = SelectedItem::Text;
        break;
        case 6:
            selection = SelectedItem::Pen;
        break;

    }


}
void Toolbar::currentColumnChanged(const QModelIndex &current, const QModelIndex &previous){

}
void Toolbar::currentRowChanged(const QModelIndex &current, const QModelIndex &previous){

}
void Toolbar::setDiagramScene(DiagramScene* scene){
    diagramScene = scene;
}


