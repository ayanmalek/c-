#include<iostream>
using namespace std;
int main(){
	
	int n;
	cout << "Enter no of rows :";
	cin >> n;
	
	int m =n-1;//new lines
	
	int nsp=1;//nsp=number os space
	
	//for printing upper line 
	// 1234567

	for (int i=1;i<=2*n-1;i++){
		cout <<i;
	}
	cout << endl;
	
	//for lower 1 2 3  and 5 6 7 
	//123 567
	//12   67
	//1     7
	
	for(int i=1;i<=m;i++){
		//number
		int a=1;
		for(int j=1;j<=m+1-i;j++){
			cout<<a;
			a++;
		}
		//space
		for(int k=1;k<=nsp;k++){
			cout << " ";
			a++;
		}
		nsp+=2;
		//number
		for(int j=1;j<=m+1-i;j++){
			cout<<a;
			a++;
		}
		cout << endl;
	}
	
	return 0;
}
