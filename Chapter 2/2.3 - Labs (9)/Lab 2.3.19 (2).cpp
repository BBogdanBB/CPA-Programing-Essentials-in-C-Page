#include <iostream>
using namespace std;
int main(void) {
double pi4 = 0.;
long n;
cout << "Number of iterations? \n";
cin >> n;
for(int i = 0; i<n; i++){
	pi4+=(double)(i%2==0)?(1./(2*i+1)):(-1./(2*i+1));
}
// Insert your code here
cout.precision(20);
cout << "Pi = " << (pi4 * 4.) << endl;
return 0;
}
