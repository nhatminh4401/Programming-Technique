// Fraction.h
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void loadFractionArray(ifstream &f, Fraction a[], int &n);

// -1 p1 < p2
// 0 p1 = p2
// 1 p1 > p2
int compare(Fraction p1, Fraction p2);
Fraction maxFraction(Fraction a[], int n);

void saveFraction(ofstream &f, Fraction p);

#endif

