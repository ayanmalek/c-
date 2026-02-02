#include<iostream>
using namespace std;
int fact(int x){
	int f = 1;
	for (int i=2;i<=x;i++){
		f *= i ;
	} 
	return f;
}
int permutation(int n, int r){
	int npr = fact(n)/fact(n-r);
	return npr;
}
int main(){
	int n;
	cout << "enter n::";
	cin >> n;
	
	int r;
	cout << "enter r::";
	cin >>r;
	int nfact  = fact(n);
	int rfact = fact(r);
	int nrfact = fact(n-r);

	int ncr=nfact / (rfact*nrfact);
	cout << "combination :: "<<ncr;
	
	int npr = permutation(n,r);
	cout << "permutation :: "<<npr;
	
	
	return 0;
}
