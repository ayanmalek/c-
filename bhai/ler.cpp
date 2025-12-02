#include<iostream>
using namespace std;
int main(){
int n ,i ,j;
cout << "enter rows:";
cin>>n;
//j<=i
//j<=n-i
//j<=2*n-1
//j<=2*n-i
// 1 
// 1 3 
// 1 3 5 
// 1 3 5 7 
// j=j+2
for (i=1;i<=n;i++){
	for (j=1;j<=n-i;j++){
		cout <<" ";	
	}
	for (int k=1;k<=i;k++){
		cout << k ;
	}

	cout << endl;
}
return 0;
}
