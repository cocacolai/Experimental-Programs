#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveInfoButton_clicked()
{
    bool validInput = true;

    std::string firstName= ui->firstNameLineEdit->text().toStdString();
    std::string lastName = ui->lastNameLineEdit->text().toStdString();
    //int hairC = ui->hairColourComboBox;
    //int eyeC = ui->eyeColourComboBox;
    int day = ui->dayBornLineEdit->text().toInt();
    int month = ui->monthBornLineEdit->text().toInt();
    int year = ui->yearBornLineEdit->text().toInt();
    //personTypes::Hair personHair;
    //personTypes::Eyes personEyes;

    if(tempPerson->validateString(firstName))// if we have a valid first name
    {
        if(tempPerson->validateString(lastName)) // if we have a valid last name
        {

            if(tempPerson->validateBirthDate(day,month,year)) // if we have a valid date
            {

                //if(tempPerson->validateHairEnum(hairC)) // if we have valid hair colour
                {
                    //personHair = tempPerson->convertIntToHairEnum(hairC);
                    //if(tempPerson->validateEyeEnum(eyeC)) // if we have valid eye colour
                    {
                        //personEyes = tempPerson->convertIntToEyeEnum(eyeC);

                        //Grab everything and make a new temporary person
                        tempPerson = new person(firstName,lastName,day,month,year,1, 1);
                    }
                }

            }
        }
    }
    if(validInput)
    {
        std::string fName = tempPerson->getName(true);
        std::string lName = tempPerson->getName(false);

        QString firstNameMessage = "The first name is: "+QString::fromUtf8(fName.c_str());
        QString lastNameMessage = "\nThe last name is: "+QString::fromUtf8(lName.c_str());
        QString dayBornMessage = "\nThe day born is: "+tempPerson->getDayBorn();
        QString monthBornMessage = "\nThe month born is: "+tempPerson->getMonthBorn();
        QString yearBornMessage = "\nThe year born is: "+tempPerson->getYearBorn();
        QString hairColourMessage = "\nThe hair colour is: "+tempPerson->getHairColour();
        QString eyeColourMessage = "\nThe eye colour is: "+tempPerson->getEyeColour();
        QString message = firstNameMessage + lastNameMessage + dayBornMessage + monthBornMessage + yearBornMessage + hairColourMessage + eyeColourMessage;
        ui->infoLabel->setText(message);
    }
}
