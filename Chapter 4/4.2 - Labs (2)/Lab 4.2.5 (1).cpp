#include <iostream>
using namespace std;

int main() {
	int n;
	unsigned long sum=0;
	// your code goes here
	cin>>n;
	for(int i = 1; i<=n; ++i)
		sum+=i;
	cout<<sum;	
	return 0;
}