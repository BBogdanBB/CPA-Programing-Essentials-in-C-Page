#include <iostream>
using namespace std;
void increment(int &var, int i =1){
	var+=i;
}
// Insert your function here
int main(void) {
int var = 0;
for(int i = 0; i < 10; i++)
if(i % 2)
increment(var);
else
increment(var,i);
cout << var << endl;
return 0;
}
