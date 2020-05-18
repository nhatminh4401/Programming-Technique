// Fraction.h
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <fstream>
using namespace std;

struct Fraction
{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void loadFractionArray(ifstream &f, Fraction a[], int &n);
double Calc_Frac(Fraction p);
void sortArrayIncrease(Fraction a[],int n);

void saveFraction(ofstream &f, Fraction p);

#endif

