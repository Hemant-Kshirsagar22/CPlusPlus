#include <iostream>

class MyClass
{
	int myPriMember;
public:
	int myPubMember;

	MyClass(int mPri, int myPub) :
		myPriMember(mPri),
		myPubMember(myPub) {}

	int getMember(void) const { // in this line we write const before the method start because we want to give access to this method if the object is constant
		return(myPriMember);
	}

	void setMember(int i)
	{
		myPriMember = i;
	}
	void print(void) const {
		std::cout << "MyPrimember : " << myPriMember << "\nMyPublicMember : " << myPubMember << std::endl;
	}
};

int main(void)
{
	MyClass myObj(0, 1); // non-const object
	const MyClass myConstObj(5, 6); // const object
	
	// non-const object can invoke all member functions and update data members
	std::cout << myObj.getMember() << std::endl;
	myObj.setMember(2);
	myObj.myPubMember = 3;
	myObj.print();

	// const object cannot allow any change
	std::cout << myConstObj.getMember() << std::endl;
	//  myConstObj.setMember(7);  // cannot invoke non-const member functions
	// myConstObj.myPubMember = 8; // cannot update data member
	myConstObj.print();

	return(0);
}
