#include <iostream>
#include <sstream>

using namespace std;
class FarmAnimal{
    public:
        FarmAnimal(double water_consumption);
        double getWaterConsumption();
// ...
    private:
        double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
    this->water_consumption = water_consumption;
}
double FarmAnimal::getWaterConsumption() {
    return water_consumption;
}
class Cow : public FarmAnimal{
    public:
        Cow(double weight);
};
Cow::Cow(double weight) : FarmAnimal(weight/100 * 8.6){}
class Sheep : public FarmAnimal{
    public:
        Sheep(double weight);
};
Sheep::Sheep(double weight) : FarmAnimal(weight/10 * 1.1){}
class Horse : public FarmAnimal{
    public:
        Horse(double weight);
};
Horse::Horse(double weight) : FarmAnimal(weight/100 * 6.8){}
class ConsumptionAccumulator
{
    public:
        ConsumptionAccumulator();
        double getTotalConsumption();
        void addConsumption(FarmAnimal animal);
    private:
        double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator(){this->total_consumption = 0;}

double ConsumptionAccumulator::getTotalConsumption()
{
    return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
    total_consumption += animal.getWaterConsumption();
}

bool ParseLine(string input, FarmAnimal &animal){
    string num;
    double weight;
    stringstream ss;
    int poz = input.find(" ");
    if(poz==string::npos||poz>5)
        return false;
    string a = input.substr(0, poz);
    num = input.substr(poz+1);
    if(num.size()<1)
        return false;
    ss<<num;
    ss>>weight;
    if(a == "cow"){
        animal = Cow(weight);
        return true;
    }
    if(a == "sheep"){
        animal = Sheep(weight);
        return true;
    }
     if(a=="horse"){
        animal = Horse(weight);
        return true;
     }
    return false;
}
int main()
{
    ConsumptionAccumulator accumulator;
    string input;
    bool g = false;
    do{
        getline(cin, input);
        if(input == "")
            break;
        FarmAnimal animal(0);
        g = ParseLine(input, animal);
        if(g){
            accumulator.addConsumption(animal);
        }
        else{
            cout<<"Incorect input \n";
        }
    }
    while(input!="");
    cout << accumulator.getTotalConsumption();
    return 0;
}
