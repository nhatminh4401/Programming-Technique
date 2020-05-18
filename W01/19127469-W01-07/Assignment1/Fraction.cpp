// Fraction.cpp
#include "Fraction.h"

void loadFraction(ifstream &f, Fraction &p){
    f >> p.num;
    f >> p.denom;
}

void loadFractionArray(ifstream &f, Fraction a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        loadFraction(f, a[i]);
    }
}

int compare(Fraction p1, Fraction p2){
    int x = p1.num * p2.denom - p1.denom * p2.num;
    if(x < 0){
        return -1;
    }
    else if(x == 0){
        return 0;
    }
    else{
        return 1;
    }
}

Fraction maxFraction(Fraction a[], int n){
    Fraction ans = a[0];
    for(int i = 0; i < n; i++){
        if(compare(a[i], ans) == 1) {// it means a[i] > ans
            ans = a[i];
        }
    }
    return ans;
}


void saveFraction(ofstream &f, Fraction p){
    f << p.num << " " << p.denom << endl;
}
