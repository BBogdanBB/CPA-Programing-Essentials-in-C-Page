#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a1 = 2.3;
	float a2 = 2.3;
	float a3 = 2.123456;
	float a4 = 2.123456;
	float a5 = 2.123456;
	cout<< a1<<endl;
	cout<< fixed <<setprecision(2)<<a2<<endl;
	cout << setprecision(6)<< a3 << endl;
	cout << setprecision(2)<< a4 << endl;
	cout << setprecision(0)<< a5 << endl;
	// your code goes here
	return 0;
}