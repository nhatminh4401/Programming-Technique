#ifndef Function_h
#define Function_h

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Date
{
	int Day, Month;
	int Year;	
};
void inputArray(Date *&a, int &n);
void saveArray(ofstream &fout, Date *a, int n);
void loadArray(ifstream &fin, Date *&a, int &n);
void outputArray(Date *a, int n);
void menu(Date *a, int &n, ofstream &fout, ifstream &fin);
int newest_date(Date *a, int n);

#endif
