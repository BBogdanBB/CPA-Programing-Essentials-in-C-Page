#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter n\n";
	cin>>n;
	unsigned long long answ=1;
	for(int i=0;i<n/2;i++){
		answ+=4+i*8;
	}
	cout<<answ;
	// your code goes here
	return 0;
}