#include <iostream>
#include <string>
#include <cstring>

template<class T1 = int, class T2 = std::string> // version 1 with default parameters
class Student
{
	T1 rollNo;
	T2 name;

	public:
	Student(T1 r,T2 n) : rollNo(r), name(n) {}

	void print(void) const
	{
		std::cout << "Version 1 : (" << name << " , " << rollNo << ")" << std::endl;
	}
};

template<class T1> // version 2 partial Template specialization
class Student<T1 ,char *>
{
	T1 rollNo;
	char *name;

	public:
	Student(T1 r,char *n) : rollNo(r), name(std::strcpy(new char[std::strlen(n) + 1],n)) {}

	void print(void) const
	{
		std::cout << "Version 2 : (" << name << " , " << rollNo << ")" << std::endl;
	}
};

int main(void)
{
	Student<int,std::string> s1(1,"Hemant"); // version 1 T1 = int , T2 = string
	s1.print(); 

	Student<int> s2(2, "AAA"); // version 1 T1 = int, default T2 = string
	s2.print();

	Student<> s3(3, "CCC"); // version 1 default T1 = int, default T2 = string
	s3.print();

	Student<std::string> s4("x4","BBB"); // version 1 default T1 = int , T2 = string
	s4.print();

	Student<int,char*> s5(5,"DDD"); // version 2 T1 = int, T2 = char *
	s5.print();

	return(0);
}


