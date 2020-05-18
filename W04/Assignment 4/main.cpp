#include "Function.h"

int main(int argc, char **argv)
{
	int numpart = atoi(argv[6]);
	int sizeapart = atoi(argv[6]);
	if (argc == 1)
		cout << "Error: no input argument.";
	else
	{
		if(strcmp(argv[5], "-numpart" ) == 0 && strcmp(argv[1], "-s") == 0 && strcmp(argv[3], "-d") == 0 ) 
		{
			if(atoi(argv[6]) < 0)
				cout << "The numpart must be > 0!!!" << endl;
			splitFile_1(argv[2], argv[4], numpart);
			cout << "Split file successfully";	
		}
		else if(strcmp(argv[5], "-sizeapart") == 0 && strcmp(argv[1], "-s") == 0 && strcmp(argv[3], "-d") == 0 ) 
		{
			if(atoi(argv[6]) < 0)
				cout << "The numpart must be > 0!!!" << endl;
			splitFile_2(argv[2], argv[4], sizeapart);
			cout << "Split file successfully";		
		}
		else
			cout << "Copy failed. Make sure that you enter the syntax properly!!";
	}
}
