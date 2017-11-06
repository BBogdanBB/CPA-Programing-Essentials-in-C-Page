#include <iostream>
using namespace std;
int main(void) {
int sys;
float m, ft, in;
cout<<"Which system do you uses to input dat\n";
cin>>sys;
if(sys==0){
	cin>>m;
	ft=3.28084*m;
	in = (ft - ((int)ft))*12;
	ft = (int)ft;
	cout<<ft<<"'"<<in<<"\"";
}
	
else
{
	cin>>ft;
	cin>>in;
	m = ft*0.3048+0.0254*in;
	cout<<m<<"m";
}

// Insert your code here

return 0;
}
