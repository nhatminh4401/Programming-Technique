// main.cpp
#include "Student.h"

int main()
{
    Student a[100];
    int n = 0;
    ifstream f1;
    
    f1.open("D:/input.txt");
    
    if(!f1.is_open())
	{
        cout << "Can not open file" << endl;
    }
    else
	{
        loadStudentArray(f1, a, n);
        ofstream f2;
        f2.open("D:/output.txt");
        if(!f2.is_open())
		{
            cout << "Can not create file" << endl;
        }
        else
		{
			int index = Max_gpa(a,n);
            f2 << a[index].id << endl << a[index].name << endl << a[index].gpa << endl;
            f2.close();
        }

        f1.close();
    }
    return 0;
}
