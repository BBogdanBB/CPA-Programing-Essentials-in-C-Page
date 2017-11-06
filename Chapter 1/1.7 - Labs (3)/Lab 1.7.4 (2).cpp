#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float eps = 0.000001;
	float x, y;
	cin>>x;
	cin>>y;
	cout<< (((1/x-1/y<=eps)&&(1/x-1/y>=-eps))?"Results are equal":"Results are not equal")<<" (by "<<fixed<<eps<< " epsilon)" ;
	// your code goes here
	return 0;
}