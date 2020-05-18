// Product.h
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include <fstream>
using namespace std;

struct Product
{
    unsigned char id;
    char name[100];
    unsigned short int stock;
    unsigned long int price;
};

void loadProduct(ifstream &f, Product &p);
void loadProductArray(ifstream &f, Product a[], int &n);
unsigned int Total_Cost(Product a[], int &n);

#endif

