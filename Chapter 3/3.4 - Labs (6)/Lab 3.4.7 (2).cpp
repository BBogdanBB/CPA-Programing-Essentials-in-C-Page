#include <iostream>
using namespace std;
bool isLeap(int year) {
	if(year%4!=0&&year%400!=0)
		return false;
	return true;
}

int monthLength(int year, int month) {
	if(month<1||month>12)
		return 0;
	int arr[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isLeap(year)&&month==2)
		return (arr[month-1]+1);
	return arr[month-1];
// Insert a new code here
}
int main(void) {
for(int yr = 2000; yr < 2002; yr++) {
for(int mo = 1; mo <= 12; mo++)
cout << monthLength(yr,mo) << " ";
cout << endl;
}
return 0;
}
