#include "Function.h"

void inputArray(int *&a, int &n)
{
	cout << "Enter n: ";
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout << "Enter a[" << i << "]: ";
		cin >> a[i];
	}
}

void saveArray(ofstream &fout, int *a, int n)
{
	fout.write((char*)&n, sizeof(n));
	for(int i = 0; i < n; i++)
	{
		fout.write((char*)&a[i], sizeof(a[i]));
	}
}

void loadArray(ifstream &fin, int *&a, int &n)
{
	fin.read((char*) &n, sizeof(n));
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		fin.read((char*)&a[i], sizeof(a[i]));
	}
}

void outputArray(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

double median(int *a, int &n)
{
	if(n % 2 == 0)
		return (double) (a[n/2 -1] + a[n/2])/2;
	else
		return (double) (a[n/2]);
}

void sortArray(int *a, int &n)
{
	int temp;
	for(int i = 0; i<n; i++)
	{		
		for(int j= i + 1; j<n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void menu(int *a, int &n, ofstream &fout, ifstream &fin)
{
	char base[] = {"D:/"}; //<---------Modify the link here
	char inputPath[101];
	strcpy(inputPath, base);
	strcat(inputPath, "input.bin"); //<-------Modify the name of input file here
	
	char outputPath[101];
	strcpy(outputPath, base);
	strcat(outputPath, "output.bin"); //<-------Modify the name of output file here
	int k;
	
	fout.open(outputPath);
	if(!fout.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{

		fin.open(inputPath);
	}
	
	if(!fin.is_open())
		cout << "Can not open file" << endl;
	
	else
	{
		do
		{
			cout << "\n==============MAIN MENU==============" << endl;
			cout << "0-quit" <<endl;
			cout << "1-Enter an array of integers from keyboard and the program will save the array to a binary file." << endl;
			cout << "2-Loads an array of integers from a binary file. The program will find the median and output to console." << endl;
			cout << "Choose number: " << endl;
			cin >> k;
		
			switch(k)
			{
				case 0:
					{
						"----------------The program is ended---------------";
						break;
					}
				case 1:
					{
						
						inputArray(a, n);
						saveArray(fout, a, n);
						fout.close();
						break;
					}
				case 2:
					{
						
						loadArray(fin, a, n);
						cout << "==================================\n";
						outputArray(a, n);
						sortArray(a, n);
						cout << "\nThe median of the array is: " << median(a, n);
						fin.close();
						break;
					}
				default:
					{
						cout << "Please enter number from 0 - 2. \n";
						cin >> k;
						break;
					}
			}
		}
		while(k != 0);
	}
}
