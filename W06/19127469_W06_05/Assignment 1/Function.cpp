#include "Function.h"

int fibo(int n){
	if(n == 0 || n == 1)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

int xn_yn_1(int n){ //x(n)     2. x(n), y(n)
	if(n == 0 )
		return 1;
	return xn_yn_1(n-1) + xn_yn_2(n-1);
}

int xn_yn_2(int n){ //y(n)      2. x(n), y(n)
	if(n == 0)
		return 0;
	return 3*xn_yn_1(n-1) + 2*xn_yn_2(n-1);
}

int xn(int n){   // 3. x(n)
	
	if(n == 0)
		return 1;
	int x = 0;
	for(int i = 1; i <= n; i++)
		x += pow(i, 2)*xn(n - i);
	return x;
}

int c_nk(int n, int k){  // 4. C(n,k)
	if(k == 0 || k == n)
		return 1;
	
	if(k < 0 || n < 0 || n < k)
		return -1; // means can't calculate
	
	if(k > 0 && n > k)
		return c_nk(n - 1, k) + c_nk(n - 1, k - 1);
}

void toBinary(int x){
	if (x == 0) { 
        cout << "0"; 
        return; 
    } 
  
    toBinary(x / 2); 
    cout << x % 2;
}

int sumOfDigits(int x){
	if (x == 0)  
    	return 0;  
    return (x % 10 + sumOfDigits(x / 10));
}
