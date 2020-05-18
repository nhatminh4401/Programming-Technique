#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <iomanip>
#define MAX 20
using namespace std;

void printBoard(int board[MAX][MAX], int N);
bool isCaptured(int board[MAX][MAX], int row, int col, int N);
bool TryQueen(int board[MAX][MAX], int col, int N);

#endif
