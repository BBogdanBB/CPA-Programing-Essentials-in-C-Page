#include <string>
#include <iostream>


bool StrCompare(std::string str1, std::string str2){
    char c;
    int counter = 0;
    while (str1[counter]) {
    c = str1[counter];
    str1[counter] = tolower(c);
    counter++;
  }
  counter = 0;
   while (str2[counter]) {
    c = str2[counter];
    str2[counter] = tolower(c);
    counter++;
  }

  if(str1.size()!=str2.size())
    return false;

  for(int i = 0; i < str1.size(); ++i){
    for(int j = 0; j < str2.size(); ++j){
        if(str1[i] == str2[j]){
            str1.erase(str1.find(str1[i--]), 1);
            str2.erase(str2.find(str2[j--]), 1);
            break;
        }
    }
  }
  if(str1.size()==0&&str2.size()==0)
    return true;
  return false;
}
int main()
{
    std::string str1, str2;
    std::cin>>str1;
    std::cin>>str2;
    std::cout<<((StrCompare(str1, str2))?"anagrams":"not anagrams");
}
