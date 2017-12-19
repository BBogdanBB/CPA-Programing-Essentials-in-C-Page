#include <iostream>
#include <string>
using namespace std;
class SimpleClass
{
    public:
        SimpleClass(int min_, int max_, int val_):min(min_), max(max_), val(val_){}
        void Add(int val){
            try{
                if(this->val+val<min||this->val+val>max)
                    throw string("Value could exceed limit.");
                this->val+=val;

            }
            catch(string str){
                cout<<str<<endl;
            }
        }

        void subtract(int val){
            try{
                if(this->val-val<min||this->val-val>max)
                    throw string("Value could exceed limit.");
                this->val+=val;
            }
            catch(string str){
                cout<<str<<endl;;
            }
        }
        void print(){
            cout<<this->val<<endl;
        }

    private:
        int min;
        int max;
        int val;
};
int main(void) {
    SimpleClass c1(0, 10, 5), c2(0, 100, 9);


    c1.Add(15);
    c2.Add(15);
    c2.subtract(90);
    c1.print();
    c2.print();


}
