#ifndef LinkedList_h
#define LinkedList_h

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
void removeAllX(LinkedList &lst, int x);
#endif
