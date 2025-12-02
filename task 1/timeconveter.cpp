#include<iostream>
using namespace std;
int main(){
	int totalsec,min,hr;
	
	cout << "Enter second: ";
	cin >> totalsec;
	
	hr=totalsec / 3600;
	
	min=(totalsec % 3600) / 60;
	
	int sec = (totalsec % 3600) / 3600;
	
	cout<<hr<< ":" << min << ":" << sec << endl;
	
	
 return 0;
}
