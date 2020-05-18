// Product.cpp
#include "Product.h"

void loadProduct(ifstream &f, Product &p)
{
    f >> p.id;
    f.getline(p.name, 100);
    f.getline(p.name, 100);
    f >> p.stock;
    f >> p.price;
}

void loadProductArray(ifstream &f, Product a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadProduct(f, a[i]);
    }
}

unsigned int Total_Cost(Product a[], int &n)
{
	unsigned int s = 0;
    for(int i = 0; i < n; i++)
    {
    	s += a[i].stock*a[i].price;
	}
	return s;
}



