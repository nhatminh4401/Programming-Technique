#include <iostream>
#define source A
#define dest C
#define temp B
using namespace std;
int i = 1;

void hn_tower(int n, char source, char dest, char temp)
{
	if(n == 1)
	{
		cout << i++ << ". Move disk 1 from rod " << source << " to rod " << dest << endl;
		return;	
	}
		
	else
	{
		
		hn_tower(n - 1, A, B, C);
		cout << i++ << ". Move disk " << n << " from rod "<< source << " to rod " << dest << endl;
		hn_tower(n - 1, B, C, A);
	}
}

int main(){
	int n;  
	cout << "Enter number of disks: ";
	cin >> n;
	cout << endl;
    hn_tower(n, 'A', 'C', 'B'); // A, B and C are names of rods  
    return 0;  
}

