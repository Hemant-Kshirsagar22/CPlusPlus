#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x, int y) :
		x(x), y(y)
	{
		std::cout << "Point Constructor ";
		print();
		std::cout << std::endl;
	}
	
	~Point(void)
	{
		std::cout << "Point Destroctor ";
		print();
		std::cout << std::endl;
	}

	void print(void)
	{
		std::cout << "( " << x << ", " << y << " )";
	}
};

class Rectangle
{
	Point topLeft;
	Point bottomRight;
public:
	Rectangle(int tlX, int tlY, int brX, int brY) :
		topLeft(tlX, tlY), bottomRight(brX, brY)
	{
		std::cout << "Rectangle Constructor ";
		print();
		std::cout << std::endl;
	}

	~Rectangle(void)
	{
		std::cout << "Rectangle Destroctor ";
		print();
		std::cout << std::endl;
	}

	void print(void)
	{
		std::cout << "[";
		topLeft.print();
		std::cout << ", ";
		bottomRight.print();
		std::cout<< "]" << std::endl;
	}

};

int main(void)
{
	Rectangle rectangle(0, 2, 5, 7);

	std::cout << std::endl;
	rectangle.print();
	std::cout << std::endl;

	return(0);
}
