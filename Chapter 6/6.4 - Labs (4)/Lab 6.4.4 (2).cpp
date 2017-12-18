#include <iostream>
#include <string>
#include <regex>
class StringValidator
{
    public:
        virtual ~StringValidator() {};
        virtual bool isValid(std::string input) = 0;
};
class MinLengthValidator : public StringValidator{
    public:
        MinLengthValidator(int min){
            this->min = min;
        }
        bool isValid(std::string input){
            return input.size() >= min;
        }
    private:
        int min;
};

class MaxLengthValidator : public StringValidator{
    public:
        MaxLengthValidator(int max){
            this->max = max;
        }
        bool isValid(std::string input){
            return input.size() <= max;
        }
    private:
        int max;
};

class PatternValidator:public StringValidator{
    public :
        PatternValidator(std::string pattern){
            this->pattern = pattern;
        }
        bool isValid(std::string input){
            std::string strreg = "";
            for(int i = 0; i<pattern.size(); i++){
                    switch(pattern[i]){
                        case 'D' : strreg+="\\d";
                        break;
                        case 'A' : strreg+="[a-zA-Z]";
                        break;
                        case '?' : strreg+='.';
                        default: strreg+=pattern[i];
                    }
            }

            std::regex reg(strreg);
            return std::regex_search(input, reg);
        }
    private:
        std::string pattern;

};

using namespace std;
void printValid(StringValidator &validator, string input)
{
    cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid");
}

int main()
{
    cout << "MinLengthValidator" << endl;
    MinLengthValidator min(6);
    printValid(min, "hello");
    cout << endl;
    printValid(min, "welcome");
    cout << endl;
    cout << endl;
    cout << "MaxLengthValidator" << endl;
    MaxLengthValidator max(6);
    printValid(max, "hello");
    cout << endl;
    printValid(max, "welcome");
    cout << endl;
    cout << endl;
    cout << "PatternValidator" << endl;
    PatternValidator digit("D");
    printValid(digit, "there are 2 types of sentences in the world");
    cout << endl;
    printValid(digit, "valid and invalid ones");
    cout << endl;
    return 0;

}
