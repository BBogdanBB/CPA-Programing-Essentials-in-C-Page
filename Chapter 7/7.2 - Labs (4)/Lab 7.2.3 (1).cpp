#include <iostream>
using namespace std;
float div(float arg1, float arg2) {
    if(arg2 == 0.0)
        throw string("Your input is not valid. You can't divide by zero");
    return arg1/arg2;
}
int main(void) {
    float a, b;
	while(cin >> a) {
		try {
			cin >> b;
			cout << div(a, b) << endl;
		} catch (string &problem) {
			cout << "Are you kidding me?" << endl;
			cout << problem << endl;
		}
	}

return 0;
}
