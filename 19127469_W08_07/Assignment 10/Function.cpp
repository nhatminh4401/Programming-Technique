#include "Function.h"
#include <string>
Node* createNode(int x)
{
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void load(ifstream &fin, LinkedList &lst)
{
	lst.head = NULL;
	int x;
	fin >> x;
	
	if(x == -1)
		return;
	
	Node *p = createNode(x);
	lst.head = p;
	Node *cur = lst.head; //tail
	
	while(true)
	{
		fin >> x;
		if(x == -1)
			break; 
		p = createNode(x);
		cur->next = p;
		cur = cur->next;
	}
}

unsigned long convertListToNum(LinkedList lst)
{
	unsigned long temp = 0;

	while(lst.head->next != NULL)
	{
		temp = lst.head->data*10 + lst.head->next->data;
		lst.head = lst.head->next;
		lst.head->data = temp;
	}
	return temp;
}
