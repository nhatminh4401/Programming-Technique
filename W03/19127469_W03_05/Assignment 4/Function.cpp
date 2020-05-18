//Function.cpp
#include "Function.h"

void inputArray(int *&a, int &n){
	cout << "Enter n: \n";
	cin >> n;
	
	a = new int[n];
	
	for(int i = 0; i < n; i++){
		cout << "Enter a[" << i << "]: ";
		cin >> *(a + i);
	}
}

int Max_element(int *a, int &n){
	int max = 0;
	for(int i = 1; i < n; i++){
		if(freq(a, n, i) > freq(a, n, max))
			max = i;
	}
	if (freq(a, n, max) == 1)
		return -1;
	else
		return a[max];
}

int freq(int *a, int &n, int k){
	int count = 0;
	for(int i = 0; i < n; i++)
		if( a[i] == a[k] )
			count++;
	return count;
}
