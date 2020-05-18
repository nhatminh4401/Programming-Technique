//Function.cpp
#include "Function.h"

void inputLabsAndStations(int **&labstations, int &nlab, int *&labs)
{
	cout << "Enter nlab: ";
	cin >> nlab;
	
	labstations = new int*[nlab];
	labs = new int[nlab];
	for(int i = 1; i <= nlab; i++)
	{
		cout << "Enter nstation in lab " << i << ": ";
		cin >> labs[i];
		
		labstations[i] = new int[labs[i]];
	}
	
	for(int i = 1; i <= nlab; i++)
	{
		for(int j = 1; j <= labs[i]; j++)
		{
			labstations[i][j] = 0;	
		}	
	}
}

void login(int **labstations)
{
	int id; 
	int nlab;
	int labs;
	cout << "Enter the 5 digit ID number of the user logging in: \n";
	cin >> id;
	cout << "Enter the lab number the user is logging in: " << endl;
	cin >> nlab;
	cout << "Enter computer station number the user is logging in: " << endl;
	cin >> labs;
	labstations[nlab][labs] = id;
}

void searchId(int **labstations, int &nlab, int *labs)
{
	int id;
	cout << "\nEnter the 5 digit ID number of the user to search: \n";
	cin >> id;
	
	for(int i = 1; i <= nlab; i++)
	{
		for(int j = 1; j <= labs[i]; j++)
		{
			if(labstations[i][j] == id)
			{
				cout << "\nUser " << id << " is in lab " << i << " and station " << j << endl;
				return;
			}
		}
	}
	cout << "\nCan not find the ID, the user logged off.\n";
}

void logoff(int **labstations, int &nlab, int *labs)
{
	int id;
	cout << "\nEnter the 5 digit ID number of the user to find: \n";
	cin >> id;
	
	for(int i = 1; i <= nlab; i++)
	{
		for(int j = 1; j <= labs[i]; j++)
		{
			if(labstations[i][j] == id)
				{
					labstations[i][j] = 0;
					break;
				}
		}
	}
	
	cout << "\nUser " << id << " is logged off. \n";
}

void printLabStatus(int **labstations, int &nlab, int *labs)
{
	cout << "Lab\tStation" << endl;
	for(int i = 1; i <= nlab; i++)
	{
		cout << i << ": ";
		for(int j = 1; j <= labs[i]; j++)
		{
			cout <<"\t"<< labstations[i][j] << "\t";
		}
		cout << endl;	
	}
	cout << endl;
}

void menu(int **labstations, int &nlab, int *labs)
{
	int k;
	
	do
	{
		cout << "==============MAIN MENU==============" << endl;
		cout << "0-Quit" << endl;
		cout << "1-Simulate login" << endl;
		cout << "2-Simulate logoff" << endl;
		cout << "3-Search" << endl;
		cout << "\n Choose number: " << endl;
		cin >> k;
		
		switch(k)
		{
			case 0:
				{
					cout << "-----------------The program is ended-------------------\n";
					break;
				}
			case 1:
				{
					login(labstations);
					printLabStatus(labstations, nlab, labs);
					break;
				}
			case 2:
				{
					logoff(labstations, nlab, labs);
					printLabStatus(labstations, nlab, labs);
					break;
				}
			case 3:
				{
					searchId(labstations, nlab, labs);
					break;
				}
			default:
				{
					cout << "Please choose number from 0 - 3. \n";
					break;
				}
				
		}
	}
	while(k != 0);	
}

void delMemory(int **labstations, int &nlab, int *labs)
{
	for(int i = 1; i <= nlab; i++)
	{
		delete[] labstations[i];
	}
	delete []labs;
	delete []labstations;
}

