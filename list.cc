#include <iostream>

struct Node {
	int value;
	Node *next;
};

class List {
	Node *head;
public:
	List() : head(NULL) {}
	void push_front(int x)
	{
		Node *p = new Node;
		p->value = x;
		p->next = head;
		head = p;
	}
	void print()
	{
		Node *p = head;
		while (p != NULL)
		{
			std::cout << p->value << std::endl;
			p = p->next;
		}
	}
	~List()
	{
		while (head != NULL)
		{
			Node *p = head->next;
			//std::cout << "deleting " << head->value
			// << std::endl;
			delete head;
			head = p;
		}
	}
	bool insert(int n, int x)
	{
		if (n == 0)
			push_front(x);
		else
		{
			Node *p = head;
			while (p != NULL && n != 1)
			{
				p = p->next;
				n--;
			}
			if (p == NULL)
				return FALSE;

			Node *node = new Node;
			node->value = x;
			node->next = p->next;
			p->next = node;			
		}
		return TRUE;
	}

	void insert2(int n, int x)
	{
		Node **p = &head;
		while (n != 0)
		{
			if (*p == NULL)
				return FALSE; 
	
			p = &((*p)->next);
			n--;
		}

		Node *node = new Node;
		node->value = x;
		node->next = *p;
		*p = node;
		return TRUE;
	}
};

int main()
{
	List x;
	x.push_front(1);
	x.push_front(2);
	x.insert2(1, 3);
	x.insert2(2, 4);
	x.insert2(7, 5);
	x.print();

	return 0;
}
