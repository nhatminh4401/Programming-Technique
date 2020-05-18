//main.cpp
#include "Function.h"

int main(void)
{
	char base[] = "D:\\";

	char outputPath[101];
	strcpy(outputPath, base);
	strcat(outputPath, "output.txt");
	
	ofstream fout;
	LinkedList lst;
	
	unsigned int n;
	cout << "Enter number: ";
	cin >> n;
	convertNumToList(lst, n);
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
