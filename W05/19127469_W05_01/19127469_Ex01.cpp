//main.cpp
#include "Function.h"

int main(){
	
    int height, width;
    
    cout << "***Note: for RAM 8GB -> Max of height and width is 1680!!!***" << endl;
    cout << "~~ Recommend for RAM 8GB -> height: 680, width: 1000 ~~" << endl;
    cout << "***Note: for RAM 4GB -> Max of height and width is 1180!!!***" << endl;
    cout << "~~ Recommend for RAM 4GB -> height: 480, width: 700 ~~" << endl;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;
    
	drawFlag(height, width);
}
