#include <string>
#include <iostream>
#include <cctype>

std::string ToUpper(std::string buffer){
    std::string str="";
    for(int i = 0; i<buffer.size(); ++i){
        str+=toupper(buffer[i]);
    }

    return str;

}
std::string PlusSpices(std::string buffer){
    std::string str=" ";
    for(int i = 0; i<buffer.size(); ++i){
        str+=buffer[i];
        str+=' ';
    }
    return str;
}

int main()
{
    int startPoz;
    char startChar;
    std::string sentence, buffer="";
    bool isEndWord=false, isStratWord=false;
    std::getline(std::cin, sentence);
    for(int i = 0; i<sentence.size(); ++i){
        if(sentence[i]=='*'||sentence[i]=='_'){
            if(!isStratWord){
                startChar = sentence[i];
                isStratWord = true;
                continue;
            }

            if(isStratWord){
                    if(sentence[i] != startChar){
                        buffer = "";
                        isStratWord=false;
                        isEndWord=false;
                        continue;
                    }
                isEndWord = true;
                isStratWord = false;
            }
        }
        if(isStratWord){
            buffer+=sentence[i];
            }
        if(isEndWord){
                if(startChar=='_'){
                    sentence.replace(sentence.find('_'+buffer+'_'), buffer.size()+2, PlusSpices(buffer));
                }
                else{
                    sentence.replace(sentence.find('*'+buffer+'*'), ('*'+buffer+'*').size(), ToUpper(buffer));
                }
                buffer="";
                isStratWord=false;
                isEndWord=false;
            }
    }
    while(sentence.find('*')!=std::string::npos){
        sentence.erase(sentence.find('*'), 1);
    }
    while(sentence.find('_')!=std::string::npos){
        sentence.erase(sentence.find('_'), 1);
    }
    std::cout<<sentence;
}
