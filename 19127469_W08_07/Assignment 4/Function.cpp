#include "Function.h"

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

void insertEvens(LinkedList &lst)
{
	if(lst.head == NULL)
		return;
	int k = 2;
	Node *p = createNode(k);
	p->next = lst.head;
	lst.head = p;
	
	Node *prev = lst.head->next;
	Node *cur = lst.head->next->next;
	while(cur != NULL)
	{
		k += 2;
		p = createNode(k);
		prev->next = p;
		p->next = cur;
		
		prev = cur;
		cur = cur->next;
	}
}
