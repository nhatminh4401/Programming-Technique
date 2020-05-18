#include "Function.h"

int main()
{
	int N;
    int board[MAX][MAX];
    cout << "Enter size of chessboard: ";
    cin >> N;
    for(int i = 0; i < N; i++)
    {
   		for(int j = 0; j < N; j++)
		   board[i][j] = 0;		// initialize to 0
    }
    
	if( TryQueen(board, 0, N) == false ) 
      	cout << "No solution";
   	printBoard(board, N);

    return 0;
}
