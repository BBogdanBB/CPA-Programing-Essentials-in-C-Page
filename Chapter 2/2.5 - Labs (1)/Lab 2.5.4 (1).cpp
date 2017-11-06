#include <iostream>
using namespace std;

int main() {
	
	int choise, a, b;
	cout<<"MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice?\n";
	cin>>choise;
	while(choise!=0){
		cout<<"Enter first number\n";
		cin>>a;
		cout<<"Enter second number\n";
		cin>>b;
		switch(choise) {
			case 1: cout<<a+b<<endl;
			break;
			case 2: cout<<a-b<<endl;
			break;
			case 3: cout<<a*b<<endl;
			break;
			case 4: cout<<a/b<<endl;
			break;
			default: cout<<"Incorect value"<<endl;
			
		}
	cout<<"MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice?\n";
	cin>>choise;
			
	}
	// your code goes here
	return 0;
}