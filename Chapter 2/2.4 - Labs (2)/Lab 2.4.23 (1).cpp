#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	int counter=0;
	for(;n;counter+=n&1,n>>=1);
	cout<<counter;
	// your code goes here
	return 0;
}