#include <string>
#include <iostream>
int main()
{
	std::string from;
	std::getline(std::cin, from);
	std::string to;
	std::getline(std::cin, to);
	std::string sentence;
	std::getline(std::cin, sentence);
	while(sentence.find(from)!=std::string::npos){
		sentence.replace(sentence.find(from), from.size(), to);
		if(to.find(from)!=std::string::npos)
			break;
	}
// change all occurrences of 'from' into 'to' in the sentence
std::cout << sentence << "\n";
}
