// Student.h
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    unsigned short int id;
    char name[100];
    float gpa;
};

void loadStudent(ifstream &f, Student &p);
void loadStudentArray(ifstream &f, Student a[], int &n);
float Max_gpa(Student a[], int&n);

#endif

