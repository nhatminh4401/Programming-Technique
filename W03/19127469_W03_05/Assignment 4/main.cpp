//main.cpp
#include "Function.h"

int main(void){
	int *a;
	int n, m;
	inputArray(a, n);
	m = Max_element(a, n);
	cout << "========================" << endl;
	if(m == -1)
		cout << "There is no mode." << endl;
	else
		cout << "The mode is: " << m << endl;
	delete a;
	
	
}
