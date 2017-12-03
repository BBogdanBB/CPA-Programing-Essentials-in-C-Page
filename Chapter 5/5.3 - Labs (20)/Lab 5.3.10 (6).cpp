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
void Transform(int &num, int &den){
    int start = (num>=den)? num : den;
    for(; start>0; --start){
        if(num%start == 0 && den%start == 0){
            num/=start;
            den/=start;
            return;
        }
    }
}
class Fraction{
    public:
        Fraction(int numerator, int denominator){
            this->numerator = numerator;
            this->denominator = denominator;
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
            Transform(num, den);
            return Fraction(num, den);
        }

        Fraction Minus(Fraction that){
            int den = denominator*that.GetDen();
            int num = numerator * that.GetDen() - that.GetNum()*denominator;
            Transform(num, den);
            return Fraction(num, den);
        }
        Fraction Times(Fraction that){
            int den = denominator*that.GetDen();
            int num = numerator * that.GetNum();
            Transform(num, den);
            return Fraction(num, den);
        }
        Fraction By(Fraction that){
            int den = denominator*that.GetNum();
            int num = numerator * that.GetDen();
            Transform(num, den);
            return Fraction(num, den);
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

    //Fraction fraction(-6, -5);
    std::cout << fraction1.toString() + " + " + fraction2.toString() + " = " + (fraction1.Plus(fraction2)).toString()<<std::endl;
    std::cout << fraction1.toString() + " - " + fraction2.toString() + " = " + (fraction1.Minus(fraction2)).toString()<<std::endl;
    std::cout << fraction1.toString() + " * " + fraction2.toString() + " = " + (fraction1.Times(fraction2)).toString()<<std::endl;
    std::cout << fraction1.toString() + " / " + fraction2.toString() + " = " + (fraction1.By(fraction2)).toString()<<std::endl;

    return 0;
}
