#include <iostream>
using namespace std;
int main(void) {
unsigned short int val;
bool ispalindrome = true;
cout << "value = ";
cin >> val;
for(int i=0;i<16&&ispalindrome;i++){
	ispalindrome=(((val>>i)&1) == ((val>>15-i)&1));
}
if(ispalindrome)
cout << val << " is a bitwise palindrome" << endl;
else
cout << val << " is not a bitwise palindrome" << endl;
return 0;
}
