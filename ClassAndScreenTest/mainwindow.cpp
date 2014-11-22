#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(this->width(), this->height());
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string tempName = ui->nameBox->text().toStdString();

    //bool male = false;
    //if(ui->checkBox->isTristate())
    //{
      //  male = true;
    //}
    temp = new person(tempName,ui->ageBox->text().toInt(),false);

    const QString sentence = "yayyy we saved "+ui->nameBox->text()+"\n who is "+ui->ageBox->text();
    ui->saveInfoLabel->setText(sentence);
    //ui->nameBox->text().toStdString();
    //ui->ageBox->text().toInt();
    //ui->checkBox->clicked();

}
