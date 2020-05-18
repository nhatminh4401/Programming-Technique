//Function.h
#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include<iostream>
using namespace std;

void inputLabsAndStations(int **&labstations, int &nlab, int *&labs);
void login(int **labstations);
void searchId(int **labstations, int &nlab, int *labs);
void logoff(int **labstations, int &nlab, int *labs);
void printLabStatus(int **labstations, int &nlab, int *labs);
void menu(int **labstations, int &nlab, int *labs);
void delMemory(int **labstations, int &nlab, int *labs);


#endif
