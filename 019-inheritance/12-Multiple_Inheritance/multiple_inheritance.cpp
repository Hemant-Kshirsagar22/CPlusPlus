// virtual inheritance - virtual base class
#include <iostream>

using namespace std;
class Person
{
public:
    Person(int x)
    {
        cout << "Person::Person(int)" << endl;
    }
    Person(void)
    {
        cout << "Person::Person(void)" << endl;
    }

};


class Faculty : virtual public Person
{
public:
    Faculty(int x) : Person(x)
    {
        cout << "Faculty::faculty(int)" << endl;
    }
};

class Student : virtual public Person
{
public:
    Student(int x) : Person(x)
    {
        cout << "Student::Student(int)" << endl;
    }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x)
    {
        cout << "TA::TA(int)" << endl;
    }
};

int main(void)
{
    TA ta(30);
    return(0);
}

