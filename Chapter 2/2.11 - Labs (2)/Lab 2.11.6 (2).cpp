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
	cout<<"Enter end hours and end minutes use a 24-hour clock\n";
	cin>>endTime.hours;
	cin>>endTime.minutes;
	while((endTime.hours<0||endTime.hours>23||endTime.minutes<0||endTime.minutes>59)&&((endTime.hours>startTime.hours)||(endTime.hours==startTime.hours&&endTime.minutes>=startTime.minutes))){
		cout<<"Incorect input data. Please re-enter minutes, minutes can be 0 - 59\n";
		cin>>endTime.hours;
		cin>>endTime.minutes;
	}
	
	Time diff;
	diff.hours= ((endTime.hours*60+endTime.minutes) - (startTime.hours*60 + startTime.minutes))/60;
	diff.minutes = ((endTime.hours*60+endTime.minutes) - (startTime.hours*60 + startTime.minutes))%60;

	cout<<endl<<diff.hours<<" : "<<diff.minutes<<endl;
	
	return 0;
}