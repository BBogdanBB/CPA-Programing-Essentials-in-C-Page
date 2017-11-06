#include <iostream>
using namespace std;
int main(void) {
	int n;
	cout<<"Enter 2<h<9\n";
	cin>> n;
	if(n<=2||n>=9)
	cout<<"Incorect input data\n";
	else  {
	int maxStrLength = 55;
	int period = 16;
	for(int h = 0;h<n;h++){
		for(int i = 1;i<=maxStrLength;i++){
			if(n-1==h&&((i>period-n&&i<period+n)||(i>2*period-n&&i<2*period+n)||(i>3*period-n&&i<3*period+n))||((i-h)%period==0&&i>8)||((i+h)%period==0&&i>8))
			{
				cout<<"*";
			}
			else{
				cout<<" ";
			}
				
		}
		cout<<"\n";
	}
}
	return 0;
}