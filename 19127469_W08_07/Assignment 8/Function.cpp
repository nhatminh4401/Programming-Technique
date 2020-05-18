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

Node *mergeList(Node* odd, Node* even)
{
	Node *result;
    if(odd == NULL) 
	{
        return even;
    }
    
    if(even == NULL) 
	{
    	return odd;
    }
    
    if(odd->data < even->data)
	{
        result = odd;
        result->next = mergeList(odd->next, even);
    } 
    
    else 
	{
        result = even;
        result->next = mergeList(odd, even->next);
    }
    return result;
}

