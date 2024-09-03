#include <iostream>
#include <vector>

class Stack
{
private:
	std::vector<char> data;
	int top;

public:
	Stack() : top(-1)
	{
		data.resize(10, '\0');
	}

	~Stack()
	{
		data.resize(0);
	}

	int empty()
	{
		return(top == -1);
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
};

int main(void)
{
	Stack stack;
	char str[10] = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		stack.push(str[i]);
	}

	while (!stack.empty())
	{
		std::cout << stack.peek();
		stack.pop();
	}
}
