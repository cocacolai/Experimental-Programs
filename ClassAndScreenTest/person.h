#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class person
{
private:
 string name;
 int age;
 bool isMale;


public:
 person();
 person(string n, int a, bool m);

 bool setName(string n);
 string getName();

 bool setAge(int a);
 int getAge();

 bool setGender(bool m);
 bool getGender();
};

#endif // PERSON_H
