//Function.cpp
#include "Function.h"

void inputArray(int *&a, int &n){
	cout << "Enter n: \n";
	cin >> n;
	
	a = new int[n];
	
	for(int i = 1; i <= n; i++){
		cout << "Enter a[" << i << "]: ";
		cin >> *(a + i);
	}
}

double median(int *a, int &n)
{
	if(n % 2 == 0)
		return (double) (a[n/2] + a[n/2 + 1])/2;
	else
		return (double) a[n/2 + 1];
}
