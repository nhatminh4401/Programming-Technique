#include "Function.h"

//int mergeFile(char *file1, char *file2)
//{
//	ifstream f1 ;
//	ofstream f2;
//	
//	int l = strlen(file1); //length of file1's string path
//
//	int count = 0;
//	do
//	{
//		count++; // count the element of the array where the file's name appears
//	}
//	while(file1[l - 1 - count] != '/');
//	
//	char a[MAX]; //a static array to save the file's name     
//	int k = 0;
//	for(int i = l - count; i <= l; i++) //we must use i <= l to take '\0' from file1 into b, to make sure that b has '\0'
//	{
//		a[k++] = file1[i];  // EX: "D:/test.txt"  -> a = "test.txt"
//	}
//
//	char b[MAX];
//	if(file2[strlen(file2) - 1] != '/' )
//	{
//		strcpy(b, file2);
//		strcat(b, "/");
//	}
//	else
//		strcpy(b, file2);
//		
//	strcat(b, a); 
//	
//	char c[MAX]; 
//	char buffer[MAX];
//	int i = 1;
//	f2.open(b, ios::out | ios::binary);
//	int count_check = 0;
//	do
//	{
//		itoa(i, buffer, 10);
//		i++;
//		strcpy(c, file1);
//		strcat(c, ".part");
//		strcat(c, buffer);
//		
//	
//		f1.open(c, ios::in | ios::binary);
//		if(f1 == NULL)
//		{
//			cout << "No more part is found. ";
//			break;
//		}
//		else
//		{
//			count_check++;
//			f1.seekg(0, ios::end);
//			int total_bytes = f1.tellg();
//			char buf[total_bytes];
//			
//			f1.read(buf, total_bytes);
//			f2.write(buf, total_bytes);
//			f1.close();
//		}
//	}
//	while(true);
//	f2.close();
//	return count_check;
//}

int mergeFile(char *file1, char *file2)
{
	
	int l = strlen(file1); //length of file1's string path

	int count = 0;
	do
	{
		count++; // count the element of the array where the file's name appears
	}
	while(file1[l - 1 - count] != '/');
	
	char a[MAX]; //a static array to save the file's name     
	int k = 0;
	for(int i = l - count; i <= l; i++) //we must use i <= l to take '\0' from file1 into b, to make sure that b has '\0'
	{
		a[k++] = file1[i];  // EX: "D:/test.txt"  -> a = "test.txt"
	}

	char b[MAX];
	if(file2[strlen(file2) - 1] != '/' )
	{
		strcpy(b, file2);
		strcat(b, "/");
	}
	else
		strcpy(b, file2);
		
	strcat(b, a); 
	
	char c[MAX]; 
	char buffer[MAX];
	int i = 1;
	FILE *f2= fopen(b, "wb");
	if(!f2)
	{
		cout << "Can not create file.";
		return 0;
	}
	int count_check = 0;
	do
	{
		itoa(i, buffer, 10);
		i++;
		strcpy(c, file1);
		strcat(c, ".part");
		strcat(c, buffer);
		
	
		FILE *f1 = fopen(c, "rb");
		if(f1 == NULL)
		{
			cout << "No more part is found. ";
			break;
		}
		else
		{
			count_check++;
			char buf[MAX_BUF];
			int t = 0;
			do
			{
				t = fread(buf, 1, MAX_BUF, f1);
				fwrite(buf, 1, t, f2);
			}
			while(t == MAX_BUF);
			fclose(f1);
		}
	}
	while(true);
	fclose(f2);
	return count_check;
}

