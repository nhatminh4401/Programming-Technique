// Area.h
#ifndef _AREA_H_
#define _AREA_H_

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
};

struct Circle
{
	Point pt;
	double r;
};

void loadData(ifstream &f, Circle &p);
void loadDataArray(ifstream &f, Circle a[], int &n);
double Calc_Area(Circle p);
double Sum_Area(Circle a[], int &n);


#endif

