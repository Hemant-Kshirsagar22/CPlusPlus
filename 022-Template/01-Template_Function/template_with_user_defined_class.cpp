#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Complex
{
	double real;
	double img;

	public:
	Complex(double re = 0.0,double img = 0.0) : real(re),img(img) {};
	double norm() const 
	{
		return(sqrt(real * real + img * img));
	}

	friend bool operator>(const Complex &c1, const Complex &c2)
	{
		return(c1.norm() > c2.norm());
	}
	
	friend ostream& operator<<(ostream &os,const Complex& c)
	{
		os<< "("  << c.real << ", " << c.img << ")";
		return(os);
	}
};

template<class T>
T Max(T x, T y)
{
	return(x > y ? x : y);
}

int main(void)
{
	Complex c1(2.1,3.2);
	Complex c2(6.2,7.2);

	cout << "max("<< c1 << ", " << c2 << ") = " << Max(c1,c2) << endl;

	return(0);
}

