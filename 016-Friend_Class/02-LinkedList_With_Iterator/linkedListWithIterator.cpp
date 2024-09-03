#include <iostream>

class Node;
class List;

class Iterator
{
	Node *node;
	List *list;

public:
	Iterator(void) : node(NULL), list(NULL) {}
	void begin(List *); // Init
	bool end(void); // check its end or not
	void next(void); // go to next node
	int info(void); // get node data
};

class List
{
	Node *head;
	Node *tail;

public:
	List(Node *h = NULL) : head(h),tail(h) {}
	void append(Node *p);
	
	friend class Iterator;
};

class Node
{
	int data;
	Node *next;

public:
	Node(int i = 0) : data(i),next(NULL) {}
	friend class List;
	friend class Iterator;
};

void Iterator::begin(List *l)
{
	list = l;

	node = l->head;
}

bool Iterator::end(void)
{
	return(node != NULL);
}

void Iterator::next(void)
{
	node = node->next;
}

int Iterator::info(void)
{
	return(node->data);
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

	Iterator iterator;
	
	for (iterator.begin(&list); iterator.end(); iterator.next())
	{
		std::cout << iterator.info() << " ";
	}
}
