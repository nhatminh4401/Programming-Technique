//main.cpp
#include "Function.h"

int main(void)
{
	char base[] = "D:\\";
	char inputPath1[101];
	strcpy(inputPath1, base);
	strcat(inputPath1, "input_Odd.txt");
	
	char inputPath2[101];
	strcpy(inputPath2, base);
	strcat(inputPath2, "input_Even.txt");
	
	char outputPath[101];
	strcpy(outputPath, base);
	strcat(outputPath, "output.txt");
	
	LinkedList lst_odd;
	LinkedList lst_even;
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
		load(fin1, lst_odd);
		fin1.close();
		fin2.open(inputPath2);
		if(!fin2.is_open())
			cout << "Can not open even file" << endl;
		else
		{
			load(fin2, lst_even);
			fin2.close();
			
			lst.head = mergeList(lst_odd.head, lst_even.head);

			fout.open(outputPath);
			if(!fout.is_open())
				cout << "Can not create file" << endl;
			else
			{
				save(fout, lst);
				cout << "Merge successfully." << endl;
				fout.close();
			}
		}
	}
}
