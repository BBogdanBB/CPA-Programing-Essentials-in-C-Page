#include <iostream>
#include <string>
using namespace std;
    class Person
    {
        public:
            string name;
            int age;
            string Name(){
                return name;
            }
            void SayHello(){
                cout<<"Hello";
            }
    };

    void print(Person* person)
    {
        cout << person->name << " is "<< person->age << " years old" << endl;
    }
    int main()
    {
        Person person;
        person.name = "Harry";
        person.age = 23;
        cout << "Meet " << person.Name()<<endl;
        print(&person);
        person.SayHello();
        return 0;
}
