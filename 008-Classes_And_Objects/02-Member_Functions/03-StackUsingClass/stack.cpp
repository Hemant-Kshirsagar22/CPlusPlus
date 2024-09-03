#include <iostream>

class Stack
{
public:
	char data[100];
	int top;

	bool empty()
	{
		return(top == -1);
	}

	char peek()
	{
		return(data[top]);
	}

	void push(char x)
	{
		data[++top] = x;
	}

	void pop()
	{
		if (!empty())
			--top;
	}
};

int main(void)
{
	Stack stack;

	stack.top = -1;
	char string[10] = "ABCED";
	
	for (int i = 0; i < 5; i++)
		stack.push(string[i]);

	std::cout << "Reversed String : ";

	while (!stack.empty())
	{
		std::cout << stack.peek();
		stack.pop();
	}

	return(0);
}
