//dynamic cast can only be used with pointers and references to classes(or with void*)
//1. Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type
//2. This naturally includes pointer upcast(converting from pointer - to - derived to pointer - to - base), in the same way as allowed as an implicit conversion
//3. But dynamic cast can also downcast(convert from pointer - to - base to pointer - to - derived) polymorphic classes(those with virtual members) if - and -only - if the pointed object is a valid complete object of the target type
//4. If the pointed object is not a valid complete object of the target type, dynamic cast returns a null pointer
//5. If dynamic_cast is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead
//6. dynamic cast can also perform the other implicit casts allowed on pointers : casting null pointers between pointers types(even between unrelated classes), and casting any pointer of any type to a void* pointer

#include <iostream>

using namespace std;

class A 
{ 
	public: 
		virtual ~A() { }
};

class B : public A
{

};

class C
{
public:
	virtual ~C() { }
};

int main(void)
{
	A a;
	B b;
	C c;

	B* pB = &b;
	A* pA = dynamic_cast<A*>(pB);
	cout << pB << " casts to " << pB << " Up Cast : Valid" << endl;

	pA = &b;
	pB = dynamic_cast<B*>(pA);
	cout << pA << " casts to " << pB << " Down cast : Valid" << endl;

	pA = &a;
	pB = dynamic_cast<B*>(pA);
	cout << pA << " casts to " << pB << " Down cast : Invalid" << endl;

	pA = (A*)&c;
	C* pC = dynamic_cast<C*>(pA);
	cout << pA << " casts to " << pC << " Unrelated cast : Invalid" << endl;

	pA = 0;
	pC = dynamic_cast<C*>(pA);
	cout << pA << " casts to " << pC << " Unrelated cast : valid for null" << endl;

	pA = &a;
	void* pV = dynamic_cast<void*>(pA);
	cout << pA << " casts to " << pV << " cast to void : valid" << endl;
	
	// pA = dynamic_cast<A*>(pV); // error : void * invalid expression type for dynamic cast
	
	return(0);
}
