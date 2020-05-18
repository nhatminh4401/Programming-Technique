#include "Function.h"


void printBoard(int board[MAX][MAX], int N) 
{
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++)
        {
        	cout << setw(3) << board[i][j] << " ";	
		}	
        cout << endl;
    }
}

bool isCaptured(int board[MAX][MAX], int row, int col, int N) 
{
    for(int i = 0; i < col; i++) //check if there is queen in the left 
        if(board[row][i] == true) // means board[row][i] is captured
        	return true;  // Captured, can't place queen
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) //check if there is queen in the left upper diagonal 
        if(board[i][j] == true) //similiar above
        	return true;
    for(int i = row, j = col; j >= 0 && i < N; i++, j--)  //check if there is queen in the left lower diagonal
        if(board[i][j] == true) // similiar above
        	return true;
    return false; // not captured, can place queen
}

bool TryQueen(int board[MAX][MAX], int col, int N) 
{
    if(col >= N) //when N queens are placed successfully
        return true;
    for(int i = 0; i < N; i++)  //for each row, check placing of queen is possible or not
    {
	   if(isCaptured(board, i, col, N) == false ) 
	   {
        	board[i][col] = 1; //if not captured, place the queen at place board[i][col]
        	
        	if(TryQueen(board, col + 1, N) == true ) //Check the other columns
        		return true;
         	board[i][col] = 0; //Backtracking, roll back captures at the cell
       }
    }
    return false; //when no possible order is found
}
