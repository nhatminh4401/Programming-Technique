#include "Function.h"

int main(int argc, char **argv)
{

	if (argc == 1)
		cout << "Error: no input argument.";
	else
	{
		if( strcmp(argv[1], "-s") == 0 && strcmp(argv[3], "-d") == 0 ) 
		{
			if(mergeFile(argv[2], argv[4]) > 0)
				cout << "Merge file successfully.";
			else
				cout << "Merge failed."	;
		}
		else
		{
			cout << "Merge failed. Make sure that you enter the syntax properly!!";
			cout << "\nBesides, you have to enter the full path of source (include the origin file name of the part)";
		}
		
	}
}
