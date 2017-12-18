#include <iostream>
#include <regex>
#include <math.h>
using namespace std;
class Piece {
    public:
        virtual bool Check(string start_position, string end_position){
            regex reg("[a-h][1-8]");
            return regex_match(start_position, reg)&&regex_match(end_position, reg);
        };
};

class Man : public Piece{
    public:
        bool Check(string start_position, string end_position){
            return !(!Piece::Check(start_position, end_position)||
               abs(start_position[0]-end_position[0])!=1||
               end_position[1]-start_position[1]!=1);
        }
};

class King : public Piece{
    public:
        bool Check(string start_position, string end_position){
            return !(!Piece::Check(start_position, end_position)||
                     abs(start_position[0]-end_position[0])-abs(start_position[1] - end_position[1]) != 0);

        }
};

int main()
{
    Piece *man = new Man();
    Piece *king = new King();

    cout<<boolalpha<<man->Check("b1", "c2")<<endl;
    cout<<king->Check("b1", "d3")<<endl;
    cout<<man->Check("b1", "d3")<<endl;
}
