// main.cpp
#include "Area.h"

int main()
{
    Circle a[100];
    int n = 0;
    ifstream f1;
    
    f1.open("D:/input.txt");
    
    if(!f1.is_open())
	{
        cout << "Can not open file" << endl;
    }
    else
	{
        loadDataArray(f1, a, n);
        
        ofstream f2;
        f2.open("D:/output.txt");
        if(!f2.is_open())
		{
            cout << "Can not create file" << endl;
        }
        else
		{
            f2 << Sum_Area(a, n) << endl;
            f2.close();
        }

        f1.close();
    }
    return 0;
}
