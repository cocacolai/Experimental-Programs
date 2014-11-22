#include "person.h"

personTypes::Eyes person::convertIntToEyeEnum(int eyeC)
{
    personTypes::Eyes tempEye;

    if(validateEyeEnum(eyeC))
    {
        if(eyeC == 1)
        {
            tempEye = personTypes::BLUE;
        }
        else if(eyeC == 2)
        {
            tempEye = personTypes::GREEN;
        }
        else if(eyeC == 3)
        {
            tempEye = personTypes::BROWNN;
        }
        else if(eyeC == 4)
        {
            tempEye = personTypes::HAZEL;
        }
        else if(eyeC == 5)
        {
            tempEye = personTypes::GREY;
        }
    }

    return tempEye;
}

personTypes::Hair person::convertIntToHairEnum(int hairC)
{
    personTypes::Hair tempHair = personTypes::START;

    if(validateHairEnum(hairC))
    {
        if(hairC == 1)
        {
            tempHair = personTypes::BLONDE;
        }
        else if(hairC == 2)
        {
            tempHair = personTypes::BROWN;
        }
        else if(hairC = 3)
        {
            tempHair = personTypes::GINGER;
        }
        else if(hairC = 4)
        {
            tempHair = personTypes::RED;
        }
        else if(hairC = 5)
        {
            tempHair = personTypes::BLACK;
        }
    }

    return tempHair;
}

bool person::validateDayBorn(int dayBorn)
{
    bool validDay = false;

    if((dayBorn>1)&&(dayBorn>32))
    {
        validDay = true;
    }

    return validDay;
}

bool person::validateMonthBorn(int monthBorn)
{
    bool validMonth = false;

    if((monthBorn >-1)&&(monthBorn < 12))
    {
        validMonth = true;
    }

    return validMonth;
}

bool person::validateYearBorn(int yearBorn)
{
    bool validYear = false;

    if(yearBorn>1990)
    {
        validYear = true;
    }

    return validYear;
}

bool person::validateBirthDate(int dayBorn, int monthBorn, int yearBorn)
{
    bool validDOB = false;

    if((validateDayBorn(dayBorn))&&(validateMonthBorn(monthBorn))&&(validateYearBorn(yearBorn)))
    {
        validDOB = true;
    }

    return validDOB;
}

bool person::validateString(std::string name)
{
    bool validS = true;

    if(name.empty())
    {
        validS = false;
    }

    return validS;
}

bool person::validateHairEnum(int num)
{
    bool validHair = true;

    if((num == personTypes::START)||(num == personTypes::END))
    {
        validHair = false;
    }

    return validHair;
}

bool person::validateEyeEnum(int num)
{
    bool validEye = true;

    if((num == personTypes::FIRST)||( num == personTypes::LAST))
    {
        validEye = false;
    }

    return validEye;
}

person::person()
{
}

person::person(std::string fName, std::string lName, int dayBorn, int monthBorn, int yearBorn, int eyeC, int hairC)
{
    if((!validateString(fName))&&(!validateString(lName))&&(!validateBirthDate(dayBorn,monthBorn,yearBorn))&&(!validateHairEnum(hairC)&&(!validateEyeEnum(eyeC))))
    {
        return;
    }
    firstName = fName;
    lastName = lName;
    dateOfBirth.tm_mday = dayBorn;
    dateOfBirth.tm_mon = monthBorn;
    dateOfBirth.tm_year = yearBorn;

    eyeColour = convertIntToEyeEnum(eyeC);
    hairColour = convertIntToHairEnum(hairC);
}

bool person::changeName(std::string name, bool isFirstName)
{
    bool changeName = false;

    if(!name.empty())
    {
        if(isFirstName)
        {
            firstName = name;
            changeName = true;
        }
        else
        {
            lastName = name;
            changeName = true;
        }
    }

    return changeName;
}

std::string person::getName(bool isFirstName)
{
    std::string returnName = "";

    if(isFirstName)
    {
        returnName = firstName;
    }
    else
    {
        returnName = lastName;
    }

    return returnName;
}

bool person::changeBirthDate(int dayBorn, int monthBorn, int yearBorn)
{
    bool changeDOB = false;

    if((dayBorn!=NULL)&&(monthBorn!=NULL)&&(yearBorn!=NULL))
    {
        changeDOB = true;
        dateOfBirth.tm_mday = dayBorn;
        dateOfBirth.tm_mon = monthBorn;
        dateOfBirth.tm_year = yearBorn;
    }
    else if((dayBorn==NULL)&&(monthBorn=NULL)&&(yearBorn==NULL))
    {
        changeDOB = false;
    }
    else
    {
        if(dayBorn == NULL)
        {
            if((monthBorn == NULL)&&(yearBorn != NULL))
            {
                if(validateYearBorn(yearBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_year = yearBorn;
                }
            }
            else if((yearBorn == NULL)&&( monthBorn != NULL))
            {
                if(validateMonthBorn(monthBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mon = monthBorn;
                }
            }
            else
            {
                if((validateYearBorn(yearBorn))&&(validateMonthBorn(monthBorn)))
                {
                    changeDOB = true;
                    dateOfBirth.tm_year = yearBorn;
                    dateOfBirth.tm_mon = monthBorn;
                }
            }

        }
        else if(monthBorn == NULL)
        {
            if((dayBorn == NULL)&&(yearBorn != NULL))
            {
                if(validateYearBorn(yearBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_year = yearBorn;
                }
            }
            else if((yearBorn == NULL && (dayBorn != NULL)))
            {
                if(validateDayBorn(dayBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mday = dayBorn;
                }
            }
            else
            {
                if((validateYearBorn(yearBorn))&&(validateDayBorn(dayBorn)))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mday = dayBorn;
                    dateOfBirth.tm_year = yearBorn;
                }
            }
        }
        else if(yearBorn == NULL)
        {
            if((dayBorn == NULL)&&(monthBorn != NULL))
            {
                if(validateMonthBorn(monthBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mon = monthBorn;
                }
            }
            else if((monthBorn == NULL ) &&(dayBorn != NULL))
            {
                if(validateDayBorn(dayBorn))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mday = dayBorn;
                }
            }
            else
            {
                if((validateDayBorn(dayBorn))&&(validateMonthBorn(monthBorn)))
                {
                    changeDOB = true;
                    dateOfBirth.tm_mon = monthBorn;
                    dateOfBirth.tm_mday = dayBorn;
                }
            }
        }

    }

    return changeDOB;
}

int person::getDayBorn()
{
    return dateOfBirth.tm_mday;
}

int person::getMonthBorn()
{
    return dateOfBirth.tm_mon;
}

int person::getYearBorn()
{
    return dateOfBirth.tm_year;
}

personTypes::Eyes person::getEyeColour()
{
    return eyeColour;
}

bool person::changeEyeColour(int eyeC)
{
    bool changeEC = false;
    if(validateEyeEnum(eyeC))
    {
        changeEC = true;
        eyeColour = convertIntToEyeEnum(eyeC);
    }
    return changeEC;
}

personTypes::Hair person::getHairColour()
{
    return hairColour;
}

bool person::changeHairColour(int hairC)
{
    bool changeHC = false;

    if(validateHairEnum(hairC))
    {
        changeHC = true;
        hairColour = convertIntToHairEnum(hairC);
    }

    return changeHC;
}
