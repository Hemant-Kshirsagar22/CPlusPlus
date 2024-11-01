#include <iostream>
#include <memory>

using namespace std;

struct Node
{
	shared_ptr<Node> leftChild; // owns left child
	shared_ptr<Node> rightChild; // owns right child
	weak_ptr<Node> parent;	// observes parent
	int v;			// Node value

	Node(int i = 0) : v(i)
	{
		cout << "Node = " << v << endl;
	}

	~Node(void)
	{
		cout << "Node = " << v << endl;
	}
};

int main(void)
{
	shared_ptr<Node> root = make_shared<Node>(2); // root : 2

	root->leftChild = make_shared<Node>(1); // left child : 1

	root->rightChild = make_shared<Node>(3);

	root->leftChild->parent = root;
	root->rightChild->parent = root;

	shared_ptr<Node> p = root; // visit tree
	weak_ptr<Node> q;

	cout << p->v << " ";
	
	p = p ->leftChild;
	cout << p->v << " ";

	q = p->parent;
	p = q.lock();	// weak to shared
	p = p->rightChild;
	
	cout << p->v << " ";
	cout << endl;

	return(0);
}

