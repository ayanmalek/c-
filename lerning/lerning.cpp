#include<iostream>
using namespace std;
int main(){
int i,n,k;

cout<< "no of rows:";
cin>>n;
int a=90;
for (i=1;i<=n;i++){
	
	for(int j=1;j<=n-i;j++){
	cout <<(char)(a)<<" ";
	a--;
	
	 
	} 
//	for(k=0;k<=i;k++){
//		cout<<k;
//	}
//	for (int k)
	cout << endl;
}
	
return 0;
}
