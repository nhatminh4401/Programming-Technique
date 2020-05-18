// Date.cpp
#include "Date.h"

void loadDate(ifstream &f, Date &p)
{
    f >> p.year;
    f >> p.month;
    f >> p.day;
}

void loadDateArray(ifstream &f, Date a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadDate(f, a[i]);
    }
}

int Calc_Date(Date p) //I make a my own formula to compare 2 dates easily
{
    return(p.year*10000 + p.month*100 + p.day);
}

void sortArrayIncrease(Date a[], int n)
{
	Date t;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if( Calc_Date(a[i]) > Calc_Date(a[j]) )
			{
				t = a[i]; 
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}



