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
Node *mergeList(Node *odd, Node *even);

#endif