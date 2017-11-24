#include <iostream>
#include <string>

using namespace std;

class AdHocSquare
{
    public:
    AdHocSquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double side;
};

class LazySquare
{
    public:
        LazySquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double side;
        double area;
        bool side_changed;
};

AdHocSquare::AdHocSquare(double side){
    this->side = side;
}
void AdHocSquare::set_side(double side){
    if(side<0)
        return;
    AdHocSquare::side = side;
}
double AdHocSquare::get_area(){
    return AdHocSquare::side*AdHocSquare::side;
}

LazySquare::LazySquare(double side){
    this->side = side;
    this->area = side*side;
}
void LazySquare::set_side(double side){
    LazySquare::side = side;
    LazySquare::side_changed = true;
}
double LazySquare::get_area(){
    if(LazySquare::side_changed)
    {
        LazySquare::area = LazySquare::side*LazySquare::side;
        LazySquare::side_changed = !LazySquare::side_changed;
    }
    return LazySquare::area;
}
