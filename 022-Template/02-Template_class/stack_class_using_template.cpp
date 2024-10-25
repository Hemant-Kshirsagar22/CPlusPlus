#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class Stack
{
	T data[100];
	int top;

	public:
	Stack() : top(-1) {}
	~Stack() {}

	void push(const T& item)
	{
		data[++top] = item;
	}

	void pop(void)
	{
		--top;
	}

	const T& peek(void) const
	{
		return(data[top]);
	}

	bool isEmpty(void) const
	{
		return(top == -1);
	}		
};

int main(void)
{
	char str[] = "ABCDE\0";

	Stack<char> s;

	for(unsigned int i = 0; i < strlen(str); ++i)
	{
		s.push(str[i]);
	}

	cout << "Reversed String : ";

	while(!(s.isEmpty()))
	{
		cout << s.peek();
		s.pop();
	}

	cout << endl;

	return(0);
}

