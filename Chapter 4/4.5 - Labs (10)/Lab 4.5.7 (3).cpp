#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> Split(std::string str) {
    std::vector<std::string> ptr;
    std::string buffer = "";
    for(int i = 0; i<str.size(); i++){
        if(!isalpha(str[i])){
            ptr.push_back(buffer);
            buffer = "";
        }
        else{
            buffer += str[i];
        }
    }
    if(buffer != "")
        ptr.push_back(buffer);
    return ptr;
}
bool StrCompare(std::string str1, std::string str2){
    char c;
    int counter = 0;
    while (str1[counter]) {
    c = str1[counter];
    str1[counter] = toupper(c);
    counter++;
  }
  c='\0';
  counter = 0;
   while (str2[counter]) {
    c = str2[counter];
    str2[counter] = toupper(c);
    counter++;
  }
  return (str2 == str1);
}
int main()
{
    std::vector<std::string> stopWords, sentenceWords;
	std::string stop_words;
	std::getline(std::cin, stop_words);
	std::string sentence;
	std::getline(std::cin, sentence);
    stopWords = Split(stop_words);
    sentenceWords = Split(sentence);
    for(int i = 0; i < stopWords.size(); ++i){
        for(int j = 0; j < sentenceWords.size(); ++j){
            if(StrCompare(stopWords[i], sentenceWords[j])){
                if(j==0)
                    sentence.erase(sentence.find(sentenceWords[j] + " "), sentenceWords[j].size()+1);
                else
                sentence.erase(sentence.find(" " + sentenceWords[j] + " "), sentenceWords[j].size()+1);
            }
        }
    }
// remove stop_words from sentence here
    std::cout << sentence << "\n";
}
