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

void join2Lists(LinkedList &lst_1, LinkedList &lst_2)
{
	if(lst_1.head == NULL && lst_2.head == NULL)
		return;
	Node *cur = lst_1.head->next;

	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	
	for(Node *p = lst_2.head; p != NULL; p = p->next)
	{
		if(p->next == NULL)
			break;
			
		else
			cur->next = lst_2.head;
			
		cur = cur->next;
		lst_2.head = lst_2.head->next;
	}
}
