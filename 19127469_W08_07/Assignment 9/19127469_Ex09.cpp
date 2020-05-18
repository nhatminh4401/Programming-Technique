//main.cpp
#include "Function.h"

int main(void)
{
	char base[] = "D:\\";
	char inputPath1[101];
	strcpy(inputPath1, base);
	strcat(inputPath1, "input1.txt");
	
	char inputPath2[101];
	strcpy(inputPath2, base);
	strcat(inputPath2, "input2.txt");
	
	char outputPath[101];
	strcpy(outputPath, base);
	strcat(outputPath, "output.txt");
	
	LinkedList lst_1;
	LinkedList lst_2;
	LinkedList lst;
	
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	fin1.open(inputPath1);
	if(!fin1.is_open()){
		cout << "Can not open odd file" << endl;
	}
	else
	{
		load(fin1, lst_1);
		fin1.close();
		fin2.open(inputPath2);
		if(!fin2.is_open())
			cout << "Can not open even file" << endl;
		else
		{
			load(fin2, lst_2);
			fin2.close();
			
			join2Lists(lst_1, lst_2);

			fout.open(outputPath);
			if(!fout.is_open())
				cout << "Can not create file" << endl;
			else
			{
				save(fout, lst_1);
				cout << "Join successfully." << endl;
				fout.close();
			}
		}
	}
}
