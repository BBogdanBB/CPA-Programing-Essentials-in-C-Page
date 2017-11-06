#include <iostream>
using namespace std;
int main(void) {
int vector[] = {1, 7, 3, 8, 3, 7, 1};
bool ispalindrome = true;
int n = sizeof(vector) / sizeof(vector[0]);
// Insert your code here
for(int i=0; i<n/2; i++){
	if(vector[i]!=vector[n-i-1]){
		ispalindrome=false;
		break;
	}
}
if(ispalindrome)
cout << "It's a palindrome";
else
cout << "It isn't a palindrome";
cout << endl;
return 0;
}
