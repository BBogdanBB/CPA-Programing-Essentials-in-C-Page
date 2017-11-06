#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin>>n;
	int vector[5] = {50, 20, 10, 5, 1};
	int k;
	for(int i=0; i<5;i++){
		k = n/vector[i];
		n%=vector[i];
		for(int j=0;j<k;j++)
			cout<<vector[i]<<" ";
	}
	
return 0;
}
