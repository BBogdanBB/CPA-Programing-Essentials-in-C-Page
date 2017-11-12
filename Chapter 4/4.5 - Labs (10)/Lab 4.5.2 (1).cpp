#include <iostream>
#include <string> 

using namespace std;

int main(void) {
	int part = 0, countNumInPart = 1, j=0, countCharInPart=0;
	string ipAddr;
	getline(cin, ipAddr);
	for(int i=0; i<ipAddr.size(); i++){
		if(((int)ipAddr[i]>57||(int)ipAddr[i]<48)&&ipAddr[i]!='.'){
			cout<<"Only digits and dots allowed";
			return 0;
		}
		if(ipAddr[i]=='.'){
			if(part>255)
			{
				cout<<"Too big a value of a part ";
				return 0;
			}
			part = 0;
			countNumInPart = 1;
			countCharInPart = 0;
			j++;
			if(j>3){
				cout<<"Too many parts";
				return 0;
			}
		}
		else{
			part=part*countNumInPart+(((int)ipAddr[i])%48);
			countNumInPart=10;
			countCharInPart++;
			if(countCharInPart>3){
				cout<<"Too many characters in a part";
				return 0;
			}
		}
	}
	if(j<3){
		cout<<"Incorrect parts count.";
		return 0;
	}

	cout<<"Correct IP";
	return 0;	
}