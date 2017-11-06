#include <iostream>
using namespace std;
int main(void) {
int n;
cout<<"enter a positive integer value greater than 1 and less then 100";

cin>>n;
if(n<1||n>100){
	cout<<"Your value is incorect";
}
else{
n-=2;
cout << endl<<'+';
for(int i = 0; i < n; i++)
cout << '-';
cout << '+' << endl;
for(int i = 0; i < n; i++) {
cout << '|';
for(int j = 0; j < n; j++)
cout << ' ';
cout << '|' << endl;
}
cout << '+';
for(int i = 0; i < n; i++)
cout << '-';
cout << '+' << endl;
}
return 0;
}