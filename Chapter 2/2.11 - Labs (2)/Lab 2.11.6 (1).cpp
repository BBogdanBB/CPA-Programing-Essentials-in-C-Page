#include <iostream>
using namespace std;

int main() {
	// your code goes here
	struct Time
	{
		int hours, minutes;
	} startTime, endTime;
	cout<<"Enter start hours and start minutes use a 24-hour clock\n";
	cin>>startTime.hours;
	cin>>startTime.minutes;
	while(startTime.hours<0||startTime.hours>23||startTime.minutes<0||startTime.minutes>59){
		cout<<"Incorect input data. Please re-enter, use a 24-hour clock!\n";
		cin>>startTime.hours;
		cin>>startTime.minutes;
	}
	cout<<"Enter minutes\n";
	cin>>userTime.minutes;
	while(userTime.minutes<0||userTime.minutes>59){
		cout<<"Incorect input data. Please re-enter minutes, minutes can be 0 - 59\n";
		cin>>userTime.minutes;
	}
	cin>>n;

	userTime.hours=(userTime.hours + n/60 + (userTime.minutes+n%60)/60)%24;
	userTime.minutes= (userTime.minutes+n%60)%60;

	cout<<endl<<userTime.hours<<" : "<<userTime.minutes<<endl;
	
	return 0;
}