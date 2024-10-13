#include <iostream>

using namespace std;

class Shapes
{
public:
	virtual void draw(void) = 0; // pure virtual function declaration some compiler does not allowed to inline function body of pure virtual function
	/*virtual void draw() = 0 
	{
		cout << "Shapes: Init Brush" << endl; 
	}*/
};

void Shapes::draw(void) // pure virtual function with dody
{
	cout << "Shapes: Init Brush" << endl;
}

class Polygon : public Shapes
{
public:
	void draw(void)
	{
		cout << "Polygon : Draw by Triangulation\n";
	}
};

class Triangle : public Shapes
{
public:
	void draw(void)
	{
		cout << "Triangle : Draw by lines\n";
	}
};

class Rectangle : public Shapes
{
public:
	void draw(void)
	{
		cout << "Rectangle : Draw by Triangulation\n";
	}
};
int main(void)
{
	Shapes *shapes[] = { new Polygon,new Triangle,new Rectangle };

	for (int i = 0; i < sizeof(shapes) / sizeof(Shapes *); i++)
	{
		shapes[i]->draw();
	}

	return(0);
}
