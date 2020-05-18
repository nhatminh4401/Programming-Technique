#ifndef Function_h
#define Function_h

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void inputArray(int *&a, int &n);
void saveArray(ofstream &fout, int *a, int n);
void loadArray(ifstream &fin, int *&a, int &n);
void outputArray(int *a, int n);
double median(int *a, int &n);
void menu(int *a, int &n, ofstream &fout, ifstream &fin);

#endif
