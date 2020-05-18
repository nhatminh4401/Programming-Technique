#ifndef Function_h
#define Function_h

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct LinkedList{
	Node *head;
};

Node *createNode(int x);
void load(ifstream &fin, LinkedList &lst);
void save(ofstream &fout, LinkedList lst);
void reverseList(LinkedList &lst);
void convertNumToList(LinkedList &lst, int n);
#endif
