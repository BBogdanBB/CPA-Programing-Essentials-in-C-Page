#include <iostream>
#include <string>
using namespace std;
class Matrix
{
    public:
        Matrix(int x, int y){
            if(x<=0||y<=0)
                throw string("Incorrect dimensions");
            dimX = x;
            dimY = y;
            arr=new int*[y];
            for(int i=0; i<y; ++i)
                arr[i]=new int[x];
            for(int i = 0; i<dimY; i++)
                for(int j = 0; j<dimX; j++)
                    arr[i][j] = 0;
        }
        void Add(Matrix* matrix){
            try{
                if(dimX!=matrix->get_dimX()||dimY!=matrix->get_dimY())
                    throw string("Matrices don't fit.");
                for(int i = 0; i<dimY; i++)
                    for(int j = 0; j<dimX; j++)
                        arr[i][j]+=matrix->arr[i][j];
                print();
                }
            catch(string str){
                cout<<str<<endl;
            }
        }
        void print(){
            for(int i = 0; i<dimY; i++){
                for(int j = 0; j<dimX; j++)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        int get_dimX(){
            return dimX;
        }

        int get_dimY(){
            return dimY;
        }
        int **arr;
    private:
        int dimX;
        int dimY;
};
int main(void) {
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);
    Matrix matrix3(3, 3);

    matrix1.Add(&matrix2);

    matrix1.Add(&matrix3);

    matrix2.Add(&matrix3);

    return 0;
}
