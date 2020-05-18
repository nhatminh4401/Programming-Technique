//main.cpp
#include "Function.h"

int main(void){
	int n, k, x;
	cout << "Enter n: ";
	cin >> n;
	cout << "\n1. Fibonacci";
	cout << "\nf(" << n << ") = " << fibo(n);
	
	cout << "\n\n2. x(n), y(n)";
	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nx(" << n << ") = " << xn_yn_1(n);
	cout << "\ny(" << n << ") = " << xn_yn_2(n);
	
	cout << "\n\n3. x(n)";
	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nx(" << n << ") = " << xn(n); 
	
	cout << "\n\n4. C(n, k)";
	cout << "\nEnter n: ";
	cin >> n; 
	cout << "\nEnter k: ";
	cin >> k;
	cout << "\nC(" << n << ", " << k << ") = " << c_nk(n, k); 
	
	cout << "\n\n5. To Binary";
	cout << "\nEnter x: ";
	cin >> x;
	toBinary(x);
	
	cout << "\n\n6. Sum of digits\n";
	cout << x << endl;
	cout << "Sum of digits: " << sumOfDigits(x);
}
