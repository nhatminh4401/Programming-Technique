// Distance.cpp
#include "Distance.h"

void loadPoint(ifstream &f, Point &p)
{
    f >> p.x;
    f >> p.y;
}

void loadPointArray(ifstream &f, Point a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadPoint(f, a[i]);
    }
}

double Calc_Distance(Point p)
{
    return((double)sqrt(pow(p.x,2) + pow(p.y,2))); //it actually is square root of (x2-x1)^2 + (y2-y1)^2 with x1,y1 is O(0,0).
}

void sortArrayIncrease(Point a[], int n)
{
	Point t;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if( Calc_Distance(a[i]) > Calc_Distance(a[j]) )
			{
				t = a[i]; 
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}



