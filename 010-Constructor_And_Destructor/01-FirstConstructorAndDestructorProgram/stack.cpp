/*
* Why we need Constructor?
* -> If A class Having private/any data we need to initialize the data to work the functionalities of that class correctly like following example we need to initalize the top variable to -1 we use constructor.
* The cunstructor() is called while creating the object.
* constructor name is same as class name
* 
* why we need Distructor?
* -> If A class Have to uninitalize the variables or we want to free the memroy that we used in class,
* the des
*/
#include <iostream>

class Stack
{
private:
	char *data;
	int top;
	int sizeOfStack;
	Stack(); // this is constructor
public:
	Stack(int sizeOfStack) : top(-1),sizeOfStack(sizeOfStack) // this is constructor
	{
		data = new char(sizeof(char) * sizeOfStack);		
	}

	int size(void)
	{
		return(sizeOfStack);
	}
	
	void push(char x)
	{
		data[++top] = x;
	}

	void pop(void)
	{
		--top;
	}

	char peek(void)
	{
		return(data[top]);
	}

	int isEmpty(void)
	{
		return(top == -1);
	}

	~Stack() // this is destructor
	{
		delete[] data;
		data = NULL;
	}
};

int main(void)
{
	char str[] = "hemant kshirsagar";

	Stack *s = new Stack(sizeof(str)/sizeof(char));
	
	printf("size : %zd\n", (sizeof(str) / sizeof(char)));

	for (int i = 0; i < (sizeof(str) / sizeof(char)) -1 ; i++)
	{
		s->push(str[i]);
	}

	while (!s->isEmpty())
	{
		std::cout << s->peek();
		s->pop();
	}

	return(0);
}
