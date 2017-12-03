#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
using namespace std;
template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
class Fraction{
    public:
        Fraction(int numerator, int denominator){
            this->numerator = numerator;
            this->denominator = denominator;
        }
        std::string toString(){
            string znak = (this->denominator<0&&this->numerator>0||this->numerator<0&&this->denominator>0)?"-":"";
            return znak + (abs(numerator)>abs(denominator)?(to_string(abs(numerator/denominator))+((numerator%denominator != 0)?" " + to_string(abs(numerator%denominator))+"/"+to_string(abs(denominator)):"")):(to_string(abs(numerator)) + "/"+to_string(abs(denominator))));
        }
        double toDouble(){
            return (.0+this->numerator)/this->denominator;
        }
    private:
        int numerator;
        int denominator;
};
void Parse(int &x, int &y, string str){
    string buffer = "";
    str+=" ";
    bool g = true;
    for(int i = 0; i<str.size(); i++){
        if(std::isdigit(str[i])||str[i] == '-'){
            buffer+=str[i];
        }
        else{
            std::istringstream ss1(buffer);
            if(g){
                g = false;
                ss1>>x;
            }
            else{
                ss1>>y;
            }
            buffer = "";
        }
    }
}
int main(void) {
    int num, den;
    std::string input = "";
    std::getline(std::cin, input);
    Parse(num, den, input);
    // parse input and get numerator and denominator
    Fraction fraction(num, den);
    //Fraction fraction(-6, -5);
    std::cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << std::endl;
    return 0;
}
