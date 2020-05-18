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

void reverseList(LinkedList &lst)
{
	Node *cur1 = NULL;
 	Node *cur2 = lst.head; 
    Node *cur3 = lst.head->next; 
  
    while (cur2 != NULL) 
	{ 
        cur3 = cur2->next; 
  
    	cur2->next = cur1; 
  
        cur1 = cur2; 
        cur2 = cur3; 
    } 
    lst.head = cur1; 
}
