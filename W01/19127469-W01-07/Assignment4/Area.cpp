// Area.cpp
#include "Area.h"

void loadData(ifstream &f, Circle &p)
{
    f >> p.pt.x;
    f >> p.pt.y;
    f >> p.r;
}

void loadDataArray(ifstream &f, Circle a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadData(f, a[i]);
    }
}

double Calc_Area(Circle p)
{
    return((double)pow(p.r,2)*3.14);
}

double Sum_Area(Circle a[], int &n)
{
	double s = 0;
	for(int i = 0; i < n; i++)
	{
		s += Calc_Area(a[i]);
	}
	return s;
}



