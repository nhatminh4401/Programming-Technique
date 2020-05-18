#include "Function.h"

void save(ofstream &fout, LinkedList lst)
{
	Node *cur = lst.head;
	while(cur != NULL)
	{
		fout << cur->data << " ";
		cur = cur->next;
	}
	fout << "-1";
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

void convertNumToList(LinkedList &lst, int n)
{

	Node* mainHead = new Node();
    int remainder = n % 10;
    mainHead->data = remainder;
    n = n / 10;
    Node* head;
    head = mainHead;
    while (n != 0)
	{
        Node* next = new Node();
        int remainder = n % 10;            
        next->data = remainder;
        head->next = next;
        head = next;
        n = n / 10;
    }
    
    lst.head = mainHead;
}
