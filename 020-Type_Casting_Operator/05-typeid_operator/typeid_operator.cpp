// typeid operator is used whare the dynamic type of a plymorphic object must be known and for static type idenetification
// 1. typeid operator returns const std::type info. The major members are:
// operator==, operator!=: checks whether the objects refer to the same type
// name : implementation - defined name of the type
// 2. typeid operator works for polymorphic type only(as it uses RTTI – virtual function table)
// 3. If the polymorphic object is bad, the typeid throws bad typeid exception

#include <iostream>
#include <typeinfo>

using namespace std;

// polymorphic hierarchy
class A
{
public:
	virtual ~A() { }
};

class B : public A { };

int main(void)
{
	A a;
	cout << typeid(a).name() << " : " << typeid(&a).name() << endl; // static

	A* p = &a;
	cout << typeid(p).name() << " : " << typeid(*p).name() << endl; // dynamic
	
	B b;
	cout << typeid(b).name() << " : " << typeid(&b).name() << endl; // static
	p = &b;
	cout << typeid(p).name() << " : " << typeid(*p).name() << endl; // dynamic

	A& r1 = a;
	A& r2 = b;

	cout << typeid(r1).name() << " : " << typeid(r2).name() << endl; // dynamic

	return(0);
}
