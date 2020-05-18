//main.cpp
#include "Function.h"

int main(void)
{
	char base[] = "D:\\";
	char inputPath[101];
	strcpy(inputPath, base);
	strcat(inputPath, "input.txt");
	
	LinkedList lst;
	
	ifstream fin;
	fin.open(inputPath);
	if(!fin.is_open()){
		cout << "Can not open file" << endl;
	}
	else
	{
		load(fin, lst);
		fin.close();
		
		cout << "Number is: " << convertListToNum(lst);
	}
}
