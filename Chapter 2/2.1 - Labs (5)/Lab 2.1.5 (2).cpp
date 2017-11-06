#include <iostream>
using namespace std;
int main(void) {
float grossprice, taxrate, netprice, taxvalue;
cout << "Enter a gross price: ";
cin >> grossprice;
cout << "Enter a tax rate: ";
cin >> taxrate;
if(grossprice>0&&taxrate>0&&taxrate<100)
{
netprice = grossprice/((100+taxrate)/100);
taxvalue = grossprice - netprice;
cout<<endl;
cout << "Net price: " << netprice << endl;
cout << "Tax value: " << taxvalue << endl;
}
else
	cout<<endl<<"incorect input data";
return 0;
}