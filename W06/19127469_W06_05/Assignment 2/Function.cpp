#include "Function.h"

bool isPalindrome(int l, int r, char* s){
	if(l == r)
		return 1;
		
	if(s[l] != s[r])
		return 0;
		
	if(l < r + 1)
		return isPalindrome(l + 1, r - 1, s);	
	
	return 1;	
}
