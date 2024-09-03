#include <iostream>

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point bottomLeft;
	Point bottomRight;
	Point topRight;
	Point topLeft;
};

int main(void)
{
	Rectangle rectangle = { {0,0},{0,1},{1,1},{1,0} };
	
	printf("[%d, %d]\n[%d, %d]\n[%d, %d]\n[%d, %d]\n", rectangle.bottomLeft.x, rectangle.bottomLeft.y, rectangle.bottomRight.x, rectangle.bottomRight.y, rectangle.topRight.x, rectangle.topRight.x, rectangle.topLeft.x, rectangle.topRight);
}
