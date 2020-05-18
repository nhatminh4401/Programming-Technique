#include <iostream>
#include <iomanip>
#define MAX 8

using namespace std;


bool isValid(int x, int y, int sol[MAX][MAX], int N) 
{     //check place is in range and not assigned yet
    return ( x >= 0 && x < N   && y >= 0 && y < N    && sol[x][y] == -1);
}

void printSolution(int sol[MAX][MAX], int N) {
    for(int x = 0; x < N; x++) 
    {
        for(int y = 0; y < N; y++)
    		cout << setw(3) << sol[x][y] << " ";
    	cout << endl;
    }
    
}

int knightTour(int x, int y, int move, int sol[MAX][MAX], int xMove[], int yMove[], int N) {
    int xNext, yNext;
    if(move == N*N)     //when the total board solution is full
    	return true;

    for(int k = 0; k < 8; k++) 
	{
        xNext = x + xMove[k];
        yNext = y + yMove[k];
        if(isValid(xNext, yNext, sol, N) == true) 
		{     //check room is preoccupied or not
        	sol[xNext][yNext] = move;
        	
        	if(knightTour(xNext, yNext, move+1, sol, xMove, yMove, N) == true)
            	return true;
         	else
            	sol[xNext][yNext] = -1;// backtracking
        }
    }
    return false;
}

int main()
{
	int N;
	cout << "Enter size of chessboard: ";
	cin >> N;
	int sol[MAX][MAX];
    for(int x = 0; x < N; x++)     //initialize all values to -1 in solution matrix
        for(int y = 0; y < N; y++)
        	sol[x][y] = -1;
        	
   //all possible moves for knight
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    sol[0][0]  = 0;     //starting from room (0, 0)

    if(knightTour(0, 0, 1, sol, xMove, yMove, N) == false) 
	{
    	cout << "No solution";
    } 
	else
    	printSolution(sol, N);
   	return 0;
}

