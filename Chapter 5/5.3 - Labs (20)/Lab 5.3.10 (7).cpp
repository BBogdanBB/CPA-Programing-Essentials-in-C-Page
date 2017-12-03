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
            this->reduce();
        }
        int GetDen(){
            return denominator;
        }
        int GetNum(){
            return numerator;
        }
        std::string toString(){
            string znak = (this->denominator<0&&this->numerator>0||this->numerator<0&&this->denominator>0)?"-":"";
            return znak + (abs(numerator)>abs(denominator)?(to_string(abs(numerator/denominator))+((numerator%denominator != 0)?" " + to_string(abs(numerator%denominator))+"/"+to_string(abs(denominator)):"")):(to_string(abs(numerator)) + "/"+to_string(abs(denominator))));
        }
        double toDouble(){
            return (.0+this->numerator)/this->denominator;
        }
        Fraction Plus(Fraction that){
            int den = denominator*that.GetDen();
            int num = numerator * that.GetDen() + that.GetNum()*denominator;
            Fraction f(num, den);
            f.reduce();
            return f;
        }

        Fraction Minus(Fraction that){
            int den = denominator*that.GetDen();
            int num = numerator * that.GetDen() - that.GetNum()*denominator;
            Fraction f(num, den);
            f.reduce();
            return f;
        }
        Fraction Times(Fraction that){
            int den = denominator*that.GetDen();
            int num = numerator * that.GetNum();
            Fraction f(num, den);
            f.reduce();
            return f;
        }
        Fraction By(Fraction that){
            int den = denominator*that.GetNum();
            int num = numerator * that.GetDen();
            Fraction f(num, den);
            f.reduce();
            return f;
        }
        void reduce(){
            int start = (numerator>=denominator)? numerator : denominator;
            for(; start>0; --start){
                if(numerator%start == 0 && denominator%start == 0){
                    numerator/=start;
                    denominator/=start;
                    return;
                }
            }
        }
        int Compare(Fraction that){
            int num1 = numerator * that.GetDen();
            int num2 = that.GetNum() * denominator;
            return (num1 == num2 ? 0 : (num1 < num2 ? -1 : 1));
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
    Fraction fraction1(num, den);

    std::getline(std::cin, input);
    Parse(num, den, input);
    Fraction fraction2(num, den);
    int ans = fraction1.Compare(fraction2);
    std::cout<< fraction1.toString() + (ans == 0 ? " = " : ans == 1 ? " > " : " < ") + fraction2.toString();
    return 0;
}
