#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char* cstr)
{
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;
	while (front < back)
	{
		if( *front != *back)
		{
			return false;
		}
		*front++; 
		*back--;
 	}
	return true;
}

int main(void){
	char *s;
	char temp[101];
	cout << "Input your string:\n";
	cin.getline(temp,101);
	s = new char[strlen(temp) + 1];
	strcpy(s, temp);
	if(isPalindrome(s) == true)
		cout << "Your string is a palindrome." << endl;
	else
		cout << "Your string is not a palindrome." << endl;
}
