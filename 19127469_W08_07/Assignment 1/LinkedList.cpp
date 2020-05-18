#include "LinkedList.h"

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
	
	if(x == 0)
		return;
	
	Node *p = createNode(x);
	lst.head = p;
	Node *cur = lst.head; //tail
	
	while(true)
	{
		fin >> x;
		if(x == 0)
			break; 
		p = createNode(x);
		cur->next = p;
		cur = cur->next;
	}
}

void removeAllX(LinkedList &lst, int x)
{
	if(lst.head == NULL)
	{
		return;	
	}	
	// remove head
	while(lst.head != NULL && lst.head->data == x)
	{
		Node *p = lst.head;
		lst.head = lst.head->next;
		delete p;
	}
	
	if(lst.head == NULL)
		return;
	Node *prev = lst.head;
	Node *cur = lst.head->next;
	while(cur != NULL)
	{
		if(cur->data == x)
		{
			Node *p = cur;
			prev->next = cur->next;
			cur = cur->next;
			delete p;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void save(ofstream &fout, LinkedList lst)
{
	Node *cur = lst.head;
	while(cur != NULL)
	{
		fout << cur->data << " ";
		cur = cur->next;
	}
	fout << "0";
}
