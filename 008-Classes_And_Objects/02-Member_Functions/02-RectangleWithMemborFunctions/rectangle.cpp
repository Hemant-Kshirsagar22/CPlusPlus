#include <iostream>
#include <cmath>

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point TL; // top-left
	Point BR; // bottom-right

	void computeArea(void)
	{
		std::cout << std::endl << std::abs(TL.x - BR.x) * std::abs(BR.y - TL.y) << std::endl;
	}
};

int main(void)
{
	Rectangle rectangle = { {0,2},{5,7} };
	rectangle.computeArea();
}
