#include "Function.h"

void inputArray(Date *&a, int &n)
{
	cout << "Enter n: ";
	cin >> n;
	a = new Date[n];
	for(int i = 0; i < n; i++)
	{
		cout << "Enter Day, Month, Year[" << i << "]: ";
		cin >> a[i].Day;
		cin >> a[i].Month;
		cin >> a[i].Year;
		
	}
}

void saveArray(ofstream &fout, Date *a, int n)
{
	fout.write((char*)&n, sizeof(n));
	for(int i = 0; i < n; i++)
	{
		fout.write((char*)&a[i], sizeof(a[i]));
	}
}

void loadArray(ifstream &fin, Date *&a, int &n)
{
	fin.read((char*) &n, sizeof(n));
	a = new Date[n];
	for(int i = 0; i < n; i++)
	{
		fin.read((char*)&a[i], sizeof(a[i]));
	}
}

void outputArray(Date *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i].Day << "/";
		cout << a[i].Month << "/";
		cout << a[i].Year << endl;
	}
}

int newest_date(Date *a, int n)
{
	Date max = a[0];
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i].Day + a[i].Month*30 + a[i].Year*365 > a[i+1].Day + a[i+1].Month*30 + a[i+1].Year*365)
		{
			max = a[i]; count = i;
		}
	}
	return count;
}


void menu(Date *a, int &n, ofstream &fout, ifstream &fin)
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
						int count = newest_date(a, n);
						cout << "The newest date is:\n";
						cout << a[count].Day << "/";
						cout << a[count].Month << "/";
						cout << a[count].Year << endl;
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
