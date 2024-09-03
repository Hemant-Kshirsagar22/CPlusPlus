#include <iostream>

class Node;

class List
{
	Node *head;
	Node *tail;

public:
	List(Node *h = NULL) : head(h), tail(h) {}
	void display(void);
	void append(Node *);
};

class Node
{
	int data;
	Node *next;

public:
	Node(int data) : data(data),next(NULL) {}
	friend void List::display(void);
	friend void List::append(Node *);
};

void List::display(void)
{
	Node *ptr = head;

	while (ptr != NULL)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

void List::append(Node *p)
{
	if (!head)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = tail->next;
	}
}

int main(void)
{
	List list;
	
	Node nodeOne(1);
	Node nodeTwo(2);
	Node nodeThree(3);

	list.append(&nodeOne);
	list.append(&nodeTwo);
	list.append(&nodeThree);

	list.display();

	return(0);
}
