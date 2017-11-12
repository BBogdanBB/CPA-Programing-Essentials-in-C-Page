#include <string>
#include <iostream>
#include <cctype>


void CheckForDublicate(std::string val, std::string &sentence) {
	std::string strToRemove = val+" "+val;
	while(sentence.find(strToRemove+" ")!=std::string::npos){
		sentence.replace(sentence.find(strToRemove), strToRemove.size(), val);
	}
	//std::cout<<val<<std::endl;

}
int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);
	std::string buffer="";
	for(int i = 0; i<sentence.size(); i++){
		if(isalpha(sentence[i])){
			buffer+=sentence[i];
			
		}
		else{
			CheckForDublicate(buffer, sentence);
			buffer="";
			
		}
	}

	// manipulate the sentence here
	std::cout << sentence << "\n";
}