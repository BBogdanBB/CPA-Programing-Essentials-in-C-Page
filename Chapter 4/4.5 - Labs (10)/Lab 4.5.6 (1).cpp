#include <string>
#include <iostream>

int main()
{
	std::string sentence;
	std:int startPoz;
	std::getline(std::cin, sentence);
	while(sentence.find("  ")!=std::string::npos){
		startPoz = sentence.find("  ");
		sentence.replace(startPoz, 2, " ");
	}
	std::cout << sentence << "\n";
}