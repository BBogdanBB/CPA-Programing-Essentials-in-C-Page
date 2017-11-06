#include <iostream>
using namespace std;
int main(void) {
long n;
cout << "Number of iterations? \n";
cin >> n;
double answ=2;
n=abs(n);
if(n==0)
	answ=1;
for(int i = 0; i<n-1; i++){
	answ*=2;	
}
// Insert your code here
cout << 1./answ<< endl;
return 0;
}
