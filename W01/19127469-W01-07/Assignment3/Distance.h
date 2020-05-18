// Distance.h
#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
};

void loadPoint(ifstream &f, Point &p);
void loadPointArray(ifstream &f, Point a[], int &n);
double Calc_Distance(Point p);
void sortArrayIncrease(Point a[],int n);


#endif

