#include <iostream>
#include <string>
class StringValidator
{
    public:
        virtual ~StringValidator() {};
        virtual bool isValid(std::string input) = 0;
};
class ExactValidator : public StringValidator{
    public:
        virtual bool isValid(std::string input);
};

bool ExactValidator::isValid(std::string input){

            return (input.size()>=6);
};
class DummyValidator : public StringValidator {
    public:
        virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input)
{
    return true;
}

using namespace std;
void printValid(StringValidator &validator, string input)
{
    cout << "The string '" << input << "' is " << (validator.isValid(input) ? "valid" : "invalid");
}

int main()
{
    DummyValidator dummy;
    printValid(dummy, "hello");
    cout << endl;
    ExactValidator exact;
    printValid(exact, "hello");
    cout << endl;
    printValid(exact, "secret");
    return 0;
}
