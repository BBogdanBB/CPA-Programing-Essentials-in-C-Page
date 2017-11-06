#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"Enter n\n";
	cin>>n;
	unsigned long long answ=1;
	for(int i=1;i<=n;i++){
		answ*=i;
	}
	cout<<answ;
	// your code goes here
	return 0;
}