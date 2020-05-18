// main.cpp
#include "Fraction.h"

int main()
{
    Fraction a[100];
    int n = 0;
    ifstream f1;
    
    f1.open("D:/input.txt");
    
    if(!f1.is_open())
	{
        cout << "Can not open file" << endl;
    }
    else
	{
        loadFractionArray(f1, a, n);
        sortArrayIncrease(a, n);
        ofstream f2;
        f2.open("D:/output.txt");
        if(!f2.is_open())
		{
            cout << "Can not create file" << endl;
        }
        else
		{
            for(int i = 0; i < n; i++)
            {
            	f2 << a[i].num << " " << a[i].denom << endl;
			}
            f2.close();
        }

        f1.close();
    }
    return 0;
}
