#include "person.h"
#include <string>

using namespace std;

person::person()
{
    name = "";
    age = 0;
    isMale = true;
}

person::person(string n, int a, bool m)
{
    if((n.empty())&&((a<0)||(a>120)))
    {
        return;
    }
    name = n;
    age = a;
    isMale = m;
}

bool person::setName(string n)
{
    bool setN = false;

    if(!n.empty())
    {
        name = n;
        setN = true;
    }

    return setN;
}

string person::getName()
{
    return name;
}

bool person::setAge(int a)
{
    bool setA = false;
    if((a>0)&&(a<120))
    {
        age = a;
        setA = true;
    }
    return setA;
}

int person::getAge()
{
    return age;
}

bool person::setGender(bool m)
{
    isMale = m;
    return true;
}

bool person::getGender()
{
    return isMale;
}
