#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
class FlightBooking {
public:
FlightBooking(int id, int capacity, int reserved);
void printStatus();
bool reserveSeats(int number_ob_seats);
bool canceReservations(int number_ob_seats);
private:
int id;
int capacity;
int reserved;
};
// ...
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->capacity = capacity;
    this->id = id;
    if(reserved*100./capacity>105.)
        this->reserved = (int)capacity*1.05;
    else
        this->reserved = reserved;
// Save data to members according to limits
}
void FlightBooking::printStatus()
{
    std::cout<<"Flight "<<this->id<<" : "<<this->reserved<<"/"<<this->capacity<<" (";
    std::cout<< std::fixed <<std::setprecision(0)<<((double)this->reserved/this->capacity)*100;
    std::cout<<"%) seats reserved \n";
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
    if((number_ob_seats+this->reserved)*100./this->capacity < 105.){
        this->reserved+=number_ob_seats;
        return true;
    }
    std::cout<<"Cannot perform this operation\n";
// try to add reservations and return 'true' on success
// keep the limits in mind
    return false;
}

bool FlightBooking::canceReservations(int number_ob_seats)
{
    if(number_ob_seats < this->reserved){
        this->reserved -= number_ob_seats;
        return true;
    }
    std::cout<<"Cannot perform this operation\n";
// try to cancel reservations and return 'true' on success
// keep the limits in mind
    return false;
}
int main() {
    std::string command="";
    int reserved = 0,
    capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    int k;
    while(command!="quit"){
        booking.printStatus();
        std::cout << "What would you like to do?: \n";
        std::getline(std::cin, command);
        if(command.find("add")!=std::string::npos){

            std::istringstream ss(command.erase(0, 4));
            ss >> k;
            booking.reserveSeats(k);
        }
        if(command.find("cancel")!=std::string::npos){
            std::istringstream ss(command.erase(0, 7));
            ss >> k;
            booking.canceReservations(k);
        }
    }



return 0;
}
