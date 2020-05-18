#include "Function.h"



void copyFile(char *file1, char *link)
{
	FILE *f1 = fopen(file1, "rb");
	int len = strlen(file1); //length of file1
	
	int count = 0;
	char a[MAX]; // a static array to save the link.
	if(link[strlen(link) - 1] != '/' )
	{
		strcpy(a, link);
		strcat(a, "/");
	}
	else
		strcpy(a, link);
		
	do
	{
		count++; // count the element of the array where the file's name appears
	}
	while(file1[len - 1 - count] != '/');
	
	char b[MAX]; //a static array to save the file's name
	int k = 0;
	for(int i = len - count; i <= len; i++) //we must use i <= l to take '\0' from file1 into b, to make sure that b has '\0'
	{
		b[k++] = file1[i]; 
	}

	strcat(a, b);
	link = a;

	FILE *f2 = fopen(link, "wb");
	
	if (f1 == NULL || f2 == NULL)
		return;
	char buf[MAX_BUF];
	
	do
	{
		count = fread(buf, 1, MAX_BUF, f1);
		fwrite(buf, 1, count, f2);
	}
	while (count == MAX_BUF);
	
	
	fclose(f1);
	fclose(f2);
}


