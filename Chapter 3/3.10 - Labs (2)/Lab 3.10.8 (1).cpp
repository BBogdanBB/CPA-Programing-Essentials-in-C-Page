#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void) {
int maxball;
int ballsno;
cout << "Max ball number? ";
cin >> maxball;
cout << "How many balls? ";
cin >> ballsno;
srand(time(NULL));
int *arr = new int[ballsno];
bool has;
for(int i = 0;i<ballsno;i++){
	do
	{
		has = true;
		arr[i] = rand() % maxball + 1;
		for(int j = i-1;j>=0; j--)
			if(arr[j]==arr[i]){
				has=false;
				break;
			}
	}
	while(!has);

}
for(int i = 0; i<ballsno; i++){
	cout<<arr[i]<<" ";
}
delete[] arr;
// Insert your code here
return 0;
}
