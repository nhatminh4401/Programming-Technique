#include "Function.h"

void splitFile_1(char *file1, char *file2, int numpart)
{
	ifstream f1 ;
	ofstream f2;
	f1.open(file1, ios::in | ios::binary);
	
	if(!f1)
		cout << "Can not Opened file.";
	
	f1.seekg(0, ios::end);
	int total_bytes = f1.tellg();
	
	int part_byte = total_bytes / numpart;
	
	int l = strlen(file1); //length of file1's string path
	int count = 0;
	char a[MAX]; 
	strcpy(a, file1);

	do
	{
		count++; // count the element of the array where the file's name appears
	}
	while(file1[l - 1 - count] != '/');
	
	char b[MAX]; //a static array to save the file's name     
	int k = 0;
	for(int i = l - count; i <= l; i++) //we must use i <= l to take '\0' from file1 into b, to make sure that b has '\0'
	{
		b[k++] = file1[i];  
	}
	char c[MAX];
	
	if(file2[strlen(file2) - 1] != '/' )
	{
		strcpy(c, file2);
		strcat(c, "/");
	}
	else
		strcpy(c, file2);
		
	strcat(c, b); 
	char f2_part[MAX];

	char buf[part_byte];
	for(int i = 1; i <= numpart; i++)
	{
		char buffer[MAX];
		itoa(i, buffer, 10);
		
		strcpy(f2_part, c);
		
		strcat(f2_part, ".part");
		strcat(f2_part, buffer);
		cout << f2_part << endl;
		if(i == numpart)
		{
			f1.read(buf,total_bytes - part_byte*(i-1));
			f2.open(f2_part, ios::out | ios::binary);
			f2.write(buf, total_bytes - part_byte*(i-1));
			f2.close();
			break;
		}
		
		f1.read(buf, part_byte);
		f2.open(f2_part, ios::out | ios::binary);
		f2.write(buf, part_byte);
		f2.close();
		
	}
	f1.close();
}

void splitFile_2(char *file1, char *file2, int sizeapart)
{
	ifstream f1 ;
	ofstream f2;
	f1.open(file1, ios::in | ios::binary);
	
	if(!f1)
		cout << "Can not Opened file.";
	
	f1.seekg(0, ios::end);
	int total_bytes = f1.tellg();
	
	int numpart = total_bytes / sizeapart;
	
	int l = strlen(file1); //length of file1's string path
	int count = 0;
	char a[MAX]; 
	strcpy(a, file1);

	do
	{
		count++; // count the element of the array where the file's name appears
	}
	while(file1[l - 1 - count] != '/');
	
	char b[MAX]; //a static array to save the file's name     
	int k = 0;
	for(int i = l - count; i <= l; i++) //we must use i <= l to take '\0' from file1 into b, to make sure that b has '\0'
	{
		b[k++] = file1[i];  
	}

	char c[MAX];
	if(file2[strlen(file2) - 1] != '/' )
	{
		strcpy(c, file2);
		strcat(c, "/");
	}
	else
		strcpy(c, file2);
		
	strcat(c, b); 
	
	char f2_part[MAX];

	char buf[sizeapart];
	for(int i = 1; i <= numpart; i++)
	{
		char buffer[MAX];
		itoa(i, buffer, 10);
		
		strcpy(f2_part, c);
		
		strcat(f2_part, ".part");
		strcat(f2_part, buffer);
		cout << f2_part << endl;
		if(i == numpart)
		{
			f1.read(buf,total_bytes - sizeapart*(i-1));
			f2.open(f2_part, ios::out | ios::binary);
			f2.write(buf, total_bytes - sizeapart*(i-1));
			f2.close();
			break;
		}
		
		f1.read(buf, sizeapart);
		f2.open(f2_part, ios::out | ios::binary);
		f2.write(buf, sizeapart);
		f2.close();
		
	}
	f1.close();
}

