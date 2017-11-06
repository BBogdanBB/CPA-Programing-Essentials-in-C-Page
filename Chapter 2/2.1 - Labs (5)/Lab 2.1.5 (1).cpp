#include <iostream>
using namespace std;
int main(void) {
int year;
cout << "Enter a year: ";
cin >> year;
if(year%4!=0)
	cout<<"\nCommon year";
else if(year%100!=0)
	cout<<"\nLeap year";
else if(year%400!=0)
	cout<<"\nCommon year";
else
	cout<<"\nLeap year";
// Insert your code here
return 0;
}