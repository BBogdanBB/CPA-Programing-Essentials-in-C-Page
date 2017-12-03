#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;
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
            this->slope = (pointA.GetY() - pointB.GetY())/(pointB.GetX() - pointA.GetX());
            this->y_intercept = (pointA.GetX()*pointB.GetY() - pointB.GetX()*pointA.GetY())/(pointB.GetX() - pointA.GetX());
        }
        string toString(){
            return "y = " + this->slope + "x " + this->y_intercept;
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
    double x1, x2, y1, y2;
    std::string input;
    std::getline(std::cin, input);
    Parse(x1, y1, input);
    std::getline(std::cin, input);
    Parse(x2, y2, input);
    Point2D p1(x1, y1);
    Point2D p2(x2, y2);
    std::cout<<p1.distanceTo(p2);
    return 0;
}
