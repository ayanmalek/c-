#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of rows : ";
	cin >> n;
	int i,j,k;
	int nsp = n-1;
	int nst = 1;
	
	for (int i=1;i<=n;i++){
		//space
		for(int j=1;j<=nsp;j++){
			cout<<" ";   
		}
		nsp--;
		//star
		for(int k=0;k<nst;k++){
			cout<<"*";
		}
		nst+=2; 
		cout<<endl;
	}
	return 0;
}
