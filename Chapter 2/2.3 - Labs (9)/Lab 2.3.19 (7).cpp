#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter n\n";
	cin>>n;
	unsigned long long answ=0, previous=0, curr=1;
	for(int i=1;i<n;i++){
		answ=previous+curr;
		previous = curr;
		curr=answ;
	}
	
	cout<<answ;
	// your code goes here
	return 0;
}