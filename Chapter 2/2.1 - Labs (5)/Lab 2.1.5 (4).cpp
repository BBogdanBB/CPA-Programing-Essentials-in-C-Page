#include <iostream>
using namespace std;
int main(void) {
int year, month, day;
cout<<"Enter number of year\n";
cin>>year;
cout<<"Enter number of month\n";
cin>>month;
cout<<"Enter number of day\n";
cin>>day;
month-=2;
if(month<=0){
	month+=12;
	year--;
}
month=month*83/32;
month+=day;
month+=year;
month+=year/4;
month-=year/100;
month+=year/400;
month%=7;

cout<<month;

return 0;
}
