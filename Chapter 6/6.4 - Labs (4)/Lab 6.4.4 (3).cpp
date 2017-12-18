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

class LengthValidator : public StringValidator
{
    public:
        LengthValidator(int min, int max);
        bool isValid(std::string input);
    private:
        MinLengthValidator min_validator;
        MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max):
    min_validator(min), max_validator(max){}

bool LengthValidator::isValid(std::string input)
{
    return ( min_validator.isValid(input) && max_validator.isValid(input) );
}
// Your code here
class PatternValidator:public StringValidator{
    public :
        PatternValidator(char pattern){
            switch(pattern){
                    case 'D' : this->pattern="\\d";
                    break;
                    case 'A' : this->pattern="[A-Z]";
                    break;
                    case 'a' : this->pattern="[a-z]";
                    break;
                    case 'u' : this->pattern="\\W";
                    break;
                }
        }
        bool isValid(std::string input){
            std::regex reg(pattern);
            return std::regex_search(input, reg);
        }
    private:
        std::string pattern;
};
class PasswordValidator : public StringValidator{
    public:
        PasswordValidator(int min, int max){
            length_validator = new LengthValidator(min, max);
            has_lower = new PatternValidator('a');
            has_upper = new PatternValidator('A');
            has_digit = new PatternValidator('D');
            has_spacial = new PatternValidator('u');
        }
        bool isValid(std::string input){
            return length_validator->isValid(input)&&has_digit->isValid(input)
                &&has_lower->isValid(input)&&has_upper->isValid(input)&&has_spacial->isValid(input);
        }
    private:
        LengthValidator *length_validator;
        PatternValidator *has_upper;
        PatternValidator *has_lower;
        PatternValidator *has_digit;
        PatternValidator *has_spacial;
};


using namespace std;
void printValid(StringValidator &validator, string input)
{
cout << "The string '" << input << "' is "
<< (validator.isValid(input) ? "valid" : "invalid");
}
int main()
{
    PasswordValidator validator(8, 8);
    printValid(validator, "P@ssw0rd");
    return 0;
}
