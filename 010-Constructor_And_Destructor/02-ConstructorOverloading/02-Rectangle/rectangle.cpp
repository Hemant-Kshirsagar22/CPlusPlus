#include <iostream>

class Point
{
public :
	int x;
	int y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Rectangle
{
	Point leftTop;
	Point rightBottom;

public:
	Rectangle(Point leftTop, Point rightBottom) : leftTop(leftTop), rightBottom(rightBottom) {}

	Rectangle(Point leftTop, int height, int width) : leftTop(leftTop), rightBottom(Point(leftTop.x + width, leftTop.y + height)) {}

	Rectangle(int height, int widht) : leftTop(Point(0, 0)), rightBottom(Point(widht, height)) {}

	int area(void)
	{
		return((rightBottom.x - leftTop.x) * (rightBottom.y - leftTop.y));
	}
};

int main(void)
{
	Point pointOne(2, 5);
	Point pointTwo(8, 10);

	Rectangle rectangleOne(pointOne, pointTwo);
	Rectangle rectangleTwo(pointOne, 5, 6);
	Rectangle rectangleThree(5, 6);

	std::cout << std::endl << "Area of rectangleOne = " << rectangleOne.area() << std::endl;
	std::cout << "Area of rectangleOne = " << rectangleTwo.area() << std::endl;
	std::cout << "Area of rectangleOne = " << rectangleThree.area() << std::endl;

	return(0);
}
