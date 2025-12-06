#include<iostream>
using namespace std;
int main(){
	
	int n;
	cout << "Enter no of rows :";
	cin >> n;
	
	int m =n-1;//new lines
	
	int nsp=1;//nsp=number os space
	
	//for printing upper line 
	//*******

	for (int i=1;i<=2*n-1;i++){
		cout << "*";
	}
	cout << endl;
	
	//for lower stars and space 
	//*** ***
	//**   **
	//*     *
	
	for(int i=1;i<=m;i++){
		//star
		for(int j=1;j<=m+1-i;j++){
			cout<<"*";
		}
		//space
		for(int k=1;k<=nsp;k++){
			cout << " ";
		}
		nsp+=2;
		//star
		for(int j=1;j<=m+1-i;j++){
			cout<<"*";
		}
		cout << endl;
	}
	
	return 0;
}
