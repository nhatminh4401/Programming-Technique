//main.cpp
#include "Function.h"

int main(){
	int l = 0;
	char t[MAX];
	char *s;

	cout << "Enter a string: ";
	cin.getline(t, MAX);
	
	s = new char[strlen(t) + 1];
	strcpy(s, t);
	int r = strlen(s) - 1;
	
	if(isPalindrome(l, r, s) == 0)
		cout << "Not a palindrome. ";
	else	
		cout << "Is a palindrome. ";
	delete s;
	return 0;
}
