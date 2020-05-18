//main.cpp
#include "Function.h"

int main(void){
	int *a;
	int n, m;
	inputArray(a, n);
	
	cout << "========================" << endl;
	cout << "The median is: " << median(a, n);
	delete a;
	
	
}
