#include <iostream>
using namespace std;
class Tree {
    public:
        virtual void Drow(){};
};

class Tree1 : public Tree{
    public:
        void Drow(){
            cout<<"Drawing 1:\n /\\ \n//\\\\\n";
        }
};

class Tree2 : public Tree{
    public:
        void Drow(){
            cout<<"Drawing 2:\n /\\ \n/**\\\n";
        }
};

class Tree3 : public Tree{
     public:
        void Drow(){
            cout<<"Drawing 3:\n /\\ \n/++\\\n";
        }
};
int main()
{
    Tree *t[3];
    t[0] = new Tree1();
    t[1] = new Tree2();
    t[2] = new Tree3();

    for(int i = 0; i<3; ++i){
        t[i]->Drow();
    }
}
