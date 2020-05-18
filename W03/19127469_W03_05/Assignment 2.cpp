#include<iostream>
using namespace std;

int doSomething(int *x, int *y){
	int temp = *x;
	*x = *y * 10; 
	*y = temp * 10; 
	return *x + *y;
}

int main(){
	int x = 2, y = 3, z;
	z = doSomething(&x, &y);
	cout << x << " " << y << " " << z << endl;
	return 0;
}
