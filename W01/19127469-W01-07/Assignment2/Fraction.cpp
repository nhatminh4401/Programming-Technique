// Fraction.cpp
#include "Fraction.h"

void loadFraction(ifstream &f, Fraction &p)
{
    f >> p.num;
    f >> p.denom;
}

void loadFractionArray(ifstream &f, Fraction a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadFraction(f, a[i]);
    }
}

double Calc_Frac(Fraction p)
{
    return((double)p.num / p.denom);
}

void sortArrayIncrease(Fraction a[], int n)
{
	Fraction t;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if( Calc_Frac(a[i]) > Calc_Frac(a[j]) )
			{
				t = a[i]; 
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}



