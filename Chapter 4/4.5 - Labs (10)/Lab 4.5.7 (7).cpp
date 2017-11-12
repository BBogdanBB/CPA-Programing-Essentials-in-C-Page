#include <string>
#include <iostream>
int main()
{
	std::string password;
	std::getline(std::cin, password);
	
	bool isUpper=false, isLower=false, isDigit=false, isSpecial=false, isLong = (password.size()>=8);
	int symbol;
	for(int i = 0; i<password.size(); i++){
		symbol = (int)password[i];

		if(symbol>=97&&symbol<=122)
			isLower = true;
		else if(symbol>=65&&symbol<=90)
			isUpper = true;
		else if(symbol>=48&&symbol<=57)
			isDigit = true;
		else
			isSpecial = true;

	}
	//std::cout<<isUpper<<isLower<<isDigit<<isSpecial<<isLong;
	if(!isLong)
		std::cout<<"The password must be 8 characters long\n";
	if(!isUpper)
		std::cout<<"The password must have at least one upper case letter\n";
	if(!isLower)
		std::cout<<"The password must have at least one lower case letter\n";
	if(!isDigit)
		std::cout<<"The password must have at least one digit\n";
	if(!isSpecial)
		std::cout<<"The password must have at least one special character\n";
	if(isLong&&isSpecial&&isDigit&&isLower&&isUpper)
		std::cout<<"The password is valid";

// manipulate the password here
// and print validation result
return 0;
}
