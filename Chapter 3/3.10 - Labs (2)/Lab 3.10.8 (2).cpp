#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Collection {
int elno;
int *elements;
};
void AddToCollection(Collection &col, int element) {
	int *arr;
	if(col.elno == 0)
	{
		arr = new int[1];
		col.elements = arr;
		col.elements[0] = element;
		col.elno++;
		return;
	}
	arr = new int[col.elno+1];
	for(int i = 0; i<col.elno; ++i){
		arr[i] = col.elements[i];
	}
	arr[col.elno] = element;
	col.elno++;
	delete[] col.elements;
	col.elements = arr;
}
void PrintCollection(Collection col) {
cout << "[ ";
for(int i = 0; i < col.elno; i++)
cout << col.elements[i] << " ";
cout << "]" << endl;
}
int main(void) {
Collection collection = { 0, NULL };
int elems;
cout << "How many elements? ";
cin >> elems;
srand(time(NULL));
for(int i = 0; i < elems; i++)
AddToCollection(collection, rand() % 100 + 1);
PrintCollection(collection);
delete[] collection.elements;
return 0;
}