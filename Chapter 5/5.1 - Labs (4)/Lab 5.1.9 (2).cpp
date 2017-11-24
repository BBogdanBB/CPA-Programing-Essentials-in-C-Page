#include <iostream>
#include <string>
using namespace std;
    class Square
    {
        public:
            Square(double side);
            void set_side(double side);
            void print();
        private:
            double side;
            double area;
// Your code here
    };
    void Square::set_side(double side){
        if(side<0)
            return;
        Square::side = side;
        Square::area = Square::side*Square::side;
    }
    Square::Square(double side)
    {
        this->side = side;
        this->area = side * side;
    }
    void Square::print()
    {
        cout << "Square: side=" << this->side << " area=" << this->area << endl;
    }

int main()
{
    Square s(4);
    s.print();
    s.set_side(2.0);
    s.print();
    s.set_side(-33.0);
    s.print();
    return 0;
}
