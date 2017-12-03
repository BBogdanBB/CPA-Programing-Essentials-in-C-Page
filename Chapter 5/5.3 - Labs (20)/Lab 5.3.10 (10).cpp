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
class Point2D{
    public:
        Point2D(double x, double y){
            this->x = x;
            this->y = y;
        }
        //string toString();
        //double toDouble();
        double GetX(){
            return this->x;
        }
        double GetY(){
            return this->y;
        }
// ...
        double distanceTo(Point2D that){
            return sqrt(pow((that.GetX() - this->GetX()), 2) + pow((that.GetY() - this->GetY()), 2));
        }
     private:
        double x;
        double y;
};
class Line2D{
    public:
        Line2D(double slope, double y_intercept){
            this->slope = slope;
            this->y_intercept = y_intercept;
        }

        Line2D(Point2D pointA, Point2D pointB){
            this->slope = (pointB.GetY() - pointA.GetY())/(pointB.GetX() - pointA.GetX());
            this->y_intercept = pointB.GetY() - this->slope * pointB.GetX();
        }
        string toString(){
            string znak = (this->y_intercept>=0)?" + ":" - ";
            return "y = " + to_string(this->slope) + 'x'+ znak + to_string(abs(this->y_intercept));
        }
        bool contains(Point2D point){
            return point.GetY() == this->slope * point.GetX() + this->y_intercept;
        }

// ...
    private:
        double slope;
        double y_intercept;
};

void Parse(double &x1, double &y1, std::string str){
    string buffer = "";
    bool g = true;
    for(int i = 0; i<str.size(); i++){
        if(std::isdigit(str[i])||str[i] == '-'||str[i]=='.'){
            buffer+=str[i];
        }
        else{
            std::istringstream ss1(buffer);
            if(g){
                g = false;
                ss1>>x1;
            }
            else{
                ss1>>y1;
            }
            buffer = "";
        }
    }
    if(buffer!=""){
        std::istringstream ss1(buffer);
        ss1>>y1;
    }
}
int main(void){
    double x, y;
    std::string input;

    std::getline(std::cin, input);
    Parse(x, y, input);
    Point2D p1(x, y);

    std::getline(std::cin, input);
    Parse(x, y, input);
    Point2D p2(x, y);

    Line2D line(p1, p2);

    std::getline(std::cin, input);
    Parse(x, y, input);
    Point2D p3(x, y);

    cout<<(line.contains(p3)?"collinear":"not collinear");
    return 0;
}
