#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n, numGrad, grad, sum=0;
	int **coursArr;

	cout<<"Enter numbers of courses\n";
	cin>> n;
	coursArr = new int*[n+1];
	coursArr[n] = new int[n];
	for(int i=0; i<n;i++){
		cin>>numGrad;
		coursArr[i] = new int[numGrad+1];
		coursArr[i][0] = numGrad;
		for(int j = 1;j<=numGrad;j++){
			cin>>grad;
			while(grad<1||grad>5)
			{
				cout<<"Incorect grad, must be 1<=grad<=5 re-enter\n";
				cin>>grad;
			}
			coursArr[i][j] = grad;
			sum+=grad;
		}
		coursArr[n][i] = sum;
		sum = 0;
	}
	float finalavrg = 0, curravrg;
	for(int i = 0;i<n;i++){
		curravrg = 1.*coursArr[n][i]/coursArr[i][0];
		finalavrg+=curravrg;
		cout<<"Course "<<i+1<<": final "<<fixed<<setprecision(2)<<curravrg<<", grades: "; 
		for(int j =1; j<=coursArr[i][0]; j++)
			cout<<coursArr[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Overall final "<<fixed<<setprecision(2)<<finalavrg/n;
	for(int i = 0; i<=n; i++)
		delete[] coursArr[i];
	delete[] coursArr;
	return 0;
}