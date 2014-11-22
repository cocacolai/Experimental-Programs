#include "structureinfo.h"
#include "ui_structureinfo.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "mainwindow.h"

StructureInfo::StructureInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StructureInfo)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);

    AddRoot("dwarfs", "seven");
}

StructureInfo::~StructureInfo()
{
    delete ui;
}

void StructureInfo::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *tree = new QTreeWidgetItem(ui->treeWidget);
    tree->setText(0,name);
    tree->setText(1,Description);
    ui->treeWidget->addTopLevelItem(tree);

    AddChild(tree, "happy", "yay");
    AddChild(tree, "sad", "boo");
}

void StructureInfo::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *branch = new QTreeWidgetItem();
    branch->setText(0,name);
    branch->setText(1,Description);
    parent->addChild(branch);
}

void StructureInfo::on_pushButton_clicked()
{
    this->setVisible(false);
    MainWindow *main = new MainWindow(this);
    main->show();
}
