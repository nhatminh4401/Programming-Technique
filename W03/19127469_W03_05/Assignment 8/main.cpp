//main.cpp
#include "Function.h"

int main(void)
{
	int **labstations, nlab, *labs;
	
	inputLabsAndStations(labstations, nlab, labs);
	menu(labstations, nlab, labs);
	delMemory(labstations, nlab , labs);
}
