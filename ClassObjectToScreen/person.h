#ifndef PERSON_H
#define PERSON_H

#include "personTypes.h"
#include <string>
#include <ctime>
#include <QMessageBox>

class person
{
private:
    std::string firstName;
    std::string lastName;
    std::tm dateOfBirth;
    personTypes::Eyes eyeColour;
    personTypes::Hair hairColour;

public:

    personTypes::Eyes convertIntToEyeEnum(int eyeC);
    personTypes::Hair convertIntToHairEnum(int hairC);

    person();
    person(std::string fName, std::string lName, int dayBorn, int monthBorn, int yearBorn, int eyeC, int hairC);

    bool changeName(std::string name, bool isFirstName);
    std::string getName(bool isFirstName);

    bool changeBirthDate(int dayBorn, int monthBorn, int yearBorn);
    int getDayBorn();
    int getMonthBorn();
    int getYearBorn();

    personTypes::Eyes getEyeColour();
    bool changeEyeColour(int eyeC);

    personTypes::Hair getHairColour();
    bool changeHairColour(int hairC);

    bool validateDayBorn(int dayBorn);
    bool validateMonthBorn(int monthBorn);
    bool validateYearBorn(int yearBorn);
    bool validateBirthDate(int dayBorn, int monthBorn, int yearBorn);

    bool validateString(std::string name);
    bool validateHairEnum(int num);
    bool validateEyeEnum(int num);

};

#endif // PERSON_H
