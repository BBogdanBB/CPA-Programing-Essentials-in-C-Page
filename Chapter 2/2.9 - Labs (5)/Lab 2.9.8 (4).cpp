#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
double vector[] = { 1., 2., 3., 4., 5. };
int n = sizeof(vector) / sizeof(vector[0]);
double ArithmeticMean=0;
double HarmonicMean=0;
double GeometricMean=1;
double RootMeanSquare;
for(int i=0;i<n;i++){
	ArithmeticMean+=vector[i];
	HarmonicMean+=1/vector[i];
	GeometricMean*=vector[i];
	RootMeanSquare+=pow(vector[i], 2);
}
// Insert your code here
cout << "Arithmetic Mean = " << ArithmeticMean/n << endl;
cout << "Harmonic Mean = " << n/HarmonicMean << endl;
cout << "Geometric Mean = " << pow(GeometricMean, 1./n) << endl;
cout << "RootMean Square = " << pow(RootMeanSquare/n, 1./2) << endl;
cout << endl;
return 0;
}
