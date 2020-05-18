// Date.h
#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
    int year;
    short month, day;
};

void loadDate(ifstream &f, Date &p);
void loadDateArray(ifstream &f, Date a[], int &n);
double Calc_Frac(Date p);
void sortArrayIncrease(Date a[],int n);


#endif

