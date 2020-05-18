#include "Function.h"

int main(int argc, char **argv)
{
	
	if (argc == 1)
		cout << "Error: no input argument.";
	else
	{
		if(strcmp(argv[1], "-s") == 0 && strcmp(argv[3], "-d") == 0)
		{
			copyFile(argv[2], argv[4]);
			cout << "Copy successfully. ";
		}
		else
			cout <<"Copy failed. Make sure that you enter the syntax properly!!";
	}
}
