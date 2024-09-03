#include <iostream>

struct Point {
	float x;
	float y;
};

Point operator+(Point &pointOne, Point &pointTwo)
{
	Point result;
	result.x = pointOne.x + pointTwo.x;
	result.y = pointOne.y + pointTwo.y;

	return(result);
}
int main(void)
{
	void display(const Point &);
	Point pointOne = { 1.0f,1.0f };
	Point pointTwo = { 1.0f,0.0f };
		
	Point point = pointOne + pointTwo;
	display(point);
	return(0);
}

void display(const Point &point)
{
	printf("Point[%.1f, %.1f]", point.x, point.y);
}
