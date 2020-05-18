//main.cpp
#include "Function.h"

int main(void)
{
	char base[] = "D:\\";
	char inputPath[101];
	strcpy(inputPath, base);
	strcat(inputPath, "input.txt");
	
	char outputPath[101];
	strcpy(outputPath, base);
	strcat(outputPath, "output.txt");
		
	LinkedList lst;
	
	ifstream fin;
	ofstream fout;
	fin.open(inputPath);
	if(!fin.is_open()){
		cout << "Can not open file" << endl;
	}
	else
	{
		load(fin, lst);
		fin.close();
		
		reverseList(lst);
		fout.open(outputPath);
		if(!fout.is_open())
			cout << "Can not create file" << endl;
		else
		{
			save(fout, lst);
			fout.close();
		}
	}
}
