// Student.cpp
#include "Student.h"
	/*  Text file: Number of Students
					Id
					Student's name
					Gpa
	*/
void loadStudent(ifstream &f, Student &p) 
{
    f >> p.id;
    f.getline(p.name, 100);
    f.getline(p.name, 100);
    f >> p.gpa;
}

void loadStudentArray(ifstream &f, Student a[], int &n)
{
    f >> n;
    for(int i = 0; i < n; i++)
	{
        loadStudent(f, a[i]);
    }
}

float Max_gpa(Student a[], int&n)
{
	float max = a[0].gpa;
	int max_index = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i].gpa > max)
		{	
			max = a[i].gpa;
			max_index = i;
		}
	}
	return max_index;
}



