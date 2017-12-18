#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
class Part{
    public:
        virtual void print(){}
};
class Engine:public Part{
    public:
        Engine(float capac):capacity(capac){}
        void print(){

            cout<<"Engine: "<<setprecision(1)<<fixed<<capacity<<endl;
        }
    private:
        float capacity;
};
class Wheel:public Part{
    public:
        Wheel(int diamtr):diameter(diamtr){}
        void print(){
            cout<<"Wheel: "<<diameter<<"inches"<<endl;
        }
    private:
        int diameter;
};
class Chassis:public Part{
    public:
        Chassis(string chassis_type):type(chassis_type){}
        void print(){
            cout<<"Chassis: "<<type<<endl;
        }
    private:
        string type;
};
class Light:public Part{
    public:
        Light(string light_type):type(light_type){}
        void print(){
            cout<<"Light: "<<type<<endl;
        }
    private:
        string type;
};
class Body:public Part{
    public:
        Body(string body_color):color(body_color){}
        void print(){
            cout<<"Body: "<<color<<endl;
        }
    private:
        string color;
};
class Car{
    public:
        Car(){
            engine = nullptr;
            body = nullptr;
            chassis = nullptr;
        }
        void Add(Part *part){
            if (dynamic_cast<Engine*>(part)){
                if(engine == nullptr)
                    this->engine = dynamic_cast<Engine*>(part);
                else
                    cout<<"Engine already exist\n";
                return;
            }

            if (dynamic_cast<Body*>(part)){
                if(body == nullptr)
                    this->body = dynamic_cast<Body*>(part);
                else
                    cout<<"Body already exist\n";
                return;
            }

            if (dynamic_cast<Chassis*>(part)){
                if(chassis == nullptr)
                    this->chassis = dynamic_cast<Chassis*>(part);
                else
                    cout<<"Chassis already exist\n";
                return;
            }

            if(dynamic_cast<Wheel*>(part)){
                bool g = false;
                for(int i = 0; i<4; i++){
                    if(wheel[i]==nullptr){
                        g=!g;
                        wheel[i] = dynamic_cast<Wheel*>(part);
                        break;
                    }
                }
                if(!g)
                    cout<<"All wheels already exist\n";
                return;
            }

            if(dynamic_cast<Light*>(part)){
                bool g = false;
                for(int i = 0; i<10; i++){
                    if(light[i]==nullptr){
                        g=!g;
                        light[i] = dynamic_cast<Light*>(part);
                        break;
                    }
                }
                if(!g)
                    cout<<"All lights already exist\n";
                return;
            }


        }
        void print(){
            if(engine !=nullptr)
                engine->print();

            for(int i = 0; i<4; i++){
                if(wheel[i]==nullptr)
                    continue;
                wheel[i]->print();
            }

            if(chassis !=nullptr)
                chassis->print();

            for(int i = 0; i<10; i++){
                if(light[i]==nullptr)
                    continue;
                light[i]->print();
            }

            if(body !=nullptr)
                body->print();
        }
    private:
        Engine *engine;
        Body *body;
        Chassis *chassis;
        Wheel *wheel[4] = {nullptr,nullptr,nullptr,nullptr};
        Light *light[10]= {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

};
int main()
{
    Car car;
    car.Add(new Engine(1.0f));
    car.Add(new Body("Black"));
    car.Add(new Chassis("Normal"));
    car.Add(new Wheel(16));
    car.Add(new Wheel(16));
    car.Add(new Wheel(16));
    car.Add(new Wheel(16));
    car.Add(new Light("Type 1"));
    car.Add(new Light("Type 1"));
    car.Add(new Light("Type 2"));
    car.Add(new Light("Type 2"));
    car.Add(new Light("Type 3"));
    car.Add(new Light("Type 3"));
    car.Add(new Light("Type 4"));
    car.Add(new Light("Type 4"));
    car.Add(new Light("Type 5"));
    car.Add(new Light("Type 5"));
    car.print();
}
