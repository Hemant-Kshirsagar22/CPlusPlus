#include <iostream>

/*
* NOTE:
* Friend class : friend class is a class that can have access of private and protected data members as well as its member function of its friend class.
* ex :
* In following code List is a friend of Node hence List class can access all data members and member functions of Node class.
* 
*/
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
	Node(int i) : data(i), next(NULL) {}

	friend class List; // this line gives acces of Node class to List class 
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
