#include <iostream>
using namespace std;
int main(void) {
int c0;
cout<<"Enter natural number\n";
cin>>c0;
int counter=0;
while(c0!=1){
	
	counter++;
	if(c0%2==0)
		c0/=2;
	else
		c0=c0*3+1;
	cout<<c0<<endl;
	
}
cout<<"steps="<<counter;
return 0;
}
