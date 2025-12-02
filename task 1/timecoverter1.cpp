#include<iostream>
using namespace std ;
int main(){
	
	int sec,min,hr,totalsec;
	
	cout << "Enter number of hour : "<<endl ;
	cin>>hr;
	
	cout << "Enter number of minute : "<<endl;
	cin>> min;
	
	cout << "Enter number of second : "
	
	cin>>sec;
	
	totalsec=(hr*3600) + (min*60) + sec;
	
	cout<< totalsec;
	
	
return 0;	
}
