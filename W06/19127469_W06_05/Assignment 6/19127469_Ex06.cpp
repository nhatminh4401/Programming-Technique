//main.cpp
#include "Function.h"

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
