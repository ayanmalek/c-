#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of rows : ";
	cin >> n;
	int i,j,k;
	int nsp = n-i;
	int nst = 2*i-1;
	
	for (int i=1;i<=n;i++){
		for(int j=1;j<=nsp;j++){
			cout<<" ";   
		}
		for(int k=0;k<nst;k++){
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
