#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structureinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->blockSignals(false);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool)
{
    this->setVisible(false);
    info = new StructureInfo(this);
    info->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->setVisible(false);
    info = new StructureInfo(this);
    info->show();
}
