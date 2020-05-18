#include "Function.h"

int main(void)
{
	int *a = NULL;
	int n = 0;
	ifstream fin;
	ofstream fout;
	menu(a, n, fout, fin); // !!Change the fileout, filein in menu function.
	delete a;
	
}
