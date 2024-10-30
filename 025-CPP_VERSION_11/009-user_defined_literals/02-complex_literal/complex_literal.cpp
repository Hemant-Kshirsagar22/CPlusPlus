#include <iostream>
#include <complex>

using namespace std;

// note the use of constexpr to enable compile time evaluation

constexpr complex<double> operator"" _i(long double d) // imaginary literal
{
	return(complex<double>{0.0,static_cast<double>(d)});
}

int main(void)
{
	auto z = 3.0 + 4.0_i;		// complex(3.0, 4.0)
	auto y = 2.3 + 5.0_i;		// complex(2.3, 5.0)
	
	cout << z << " + " << y << " = " << z + y << std::endl;
	cout << z << " * " << y << " = " << z * y << std::endl;
	cout << "abs(" << z << ") = " << abs(z) << endl;

	return(0);	
}

