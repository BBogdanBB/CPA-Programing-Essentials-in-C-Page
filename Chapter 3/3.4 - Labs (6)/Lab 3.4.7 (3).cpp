#include <iostream>
using namespace std;

struct Date
{
	int year, month, day;
};
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
int dayOfYear(Date date) {
	int sum = 0;
	for(int i=1;i<date.month;i++){
		sum+=monthLength(date.year, i);
	}
	return sum+date.day;
}
int main(void) {
Date d;
cout << "Enter year month day: ";
cin >> d.year >> d.month >> d.day;
cout << dayOfYear(d) << endl;
return 0;

}
