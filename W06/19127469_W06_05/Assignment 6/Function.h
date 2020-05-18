#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <iomanip>

#define MAX 8

using namespace std;

bool isValid(int x, int y, int sol[MAX][MAX], int N);
void printSolution(int sol[MAX][MAX], int N);
int knightTour(int x, int y, int move, int sol[MAX][MAX], int xMove[], int yMove[], int N);


#endif
