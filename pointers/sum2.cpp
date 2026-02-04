#include<iostream>
using namespace std;
int main(){
	
	int x;
	int y;
	int *ptr1 = &x;
	int *ptr2 = &y;
	cout << "enter x and y :: ";
	cin >> *ptr1 >> y;
	int z = *ptr1 + *ptr2;
	cout << "sum is " << z;
		
	
	return 0;
}
