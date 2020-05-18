#include<iostream>

using namespace std;

struct Person {
	char* name;
	int age;
	Person* father;
	Person* mother;
};

int COUNT(Person* p) {
	if(p == NULL)
		return 0;
		
	int c1 = COUNT(p->father);
	int c2 = COUNT(p->mother);
	
	return c1 + c2 + 1;
}

int main(){
	
	
	return 0;
}
