#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
class FlightBooking {
    public:
        FlightBooking(int id, int capacity, int reserved);
        FlightBooking();
        void printStatus();
        bool reserveSeats(int number_ob_seats);
        bool canceReservations(int number_ob_seats);
        int getId() { return id; };
    private:
        int id;
        int capacity;
        int reserved;
};

FlightBooking::FlightBooking()
{
    id = 0; capacity = 0; reserved = 0;
}
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
void printBooking(FlightBooking *booking){
    for(int i = 0; i < 10; ++i){
        if(booking->getId()!=0)
            booking->printStatus();
        booking++;
    }
}
void create_new_flight(std::string command, FlightBooking ( &arr )[10] ){
    std::string id = command.substr(0, command.find(' '));
    std::string capas = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id);
    std::istringstream ss2(capas);
    int id_i, capas_i;
    ss1 >> id_i;
    ss2 >> capas_i;
    bool g;
    for(int i = 0; i<10;++i){
       if(arr[i].getId()==id_i)
            break;
       if(arr[i].getId()==0){
            g = true;
            arr[i] = FlightBooking(id_i, capas_i, 0);
            break;
       }
    }
    if(!g)
        std::cout<<"Cannot perform this operation\n";

}
void add_flight(std::string command,  FlightBooking ( &arr )[10] ){
    std::string id = command.substr(0, command.find(' '));
    std::string capas = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id);
    std::istringstream ss2(capas);
    int id_i, capas_i;
    ss1 >> id_i;
    ss2 >> capas_i;
    bool g;
    for(int i = 0; i<10;++i){
       if(arr[i].getId()==id_i){
            g = true;
            arr[i].reserveSeats(capas_i);
            break;
       }
    }
    if(!g)
        std::cout<<"Cannot perform this operation\n";

}
void cancel_flight(std::string command,  FlightBooking ( &arr )[10] ){
    std::string id = command.substr(0, command.find(' '));
    std::string capas = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id);
    std::istringstream ss2(capas);
    int id_i, capas_i;
    ss1 >> id_i;
    ss2 >> capas_i;
    //std::cout<<id_i<<" "<<capas_i;
    bool g;
    for(int i = 0; i<10;++i){
       if(arr[i].getId() == id_i){
            g = true;
            arr[i].canceReservations(capas_i);
            break;
       }
    }
    if(!g)
        std::cout<<"Cannot perform this operation\n";

}
void delete_flight(std::string command,  FlightBooking ( &arr )[10] ){
    std::string id = command.substr(0, command.find(' '));
    std::string capas = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id);
    std::istringstream ss2(capas);
    int id_i, capas_i;
    ss1 >> id_i;
    ss2 >> capas_i;
    bool g;
    for(int i = 0; i<10;++i){
       if(arr[i].getId()==id_i){
            g = true;
            arr[i] = FlightBooking();
            break;
       }
    }
    if(!g)
        std::cout<<"Cannot perform this operation\n";

}
bool IsFlightInSystem(FlightBooking *f){
    int i = 0;
    do
    {
        if((*f).getId()!=0)
            return true;
        f++;
        i++;
    }
    while(i<10);
    return false;
}
int main() {
    FlightBooking booking[10];

    printBooking(booking);
    std::string command="";
    int k;
    std::cout<<"No flights in the system\n";
    while(command!="quit"){
        std::cout << "What would you like to do?: \n";
        std::getline(std::cin, command);
        if(command.find("create") == 0){
            create_new_flight(command.erase(0, 7), booking);
            printBooking(booking);
        }
        if(command.find("add") == 0){
            add_flight(command.erase(0, 4), booking);
            printBooking(booking);
         //   booking.reserveSeats(k);
        }
        if(command.find("cancel") == 0){
            cancel_flight(command.erase(0, 7), booking);
            printBooking(booking);
           // booking.canceReservations(k);
        }
        if(command.find("delete") == 0){
            delete_flight(command.erase(0, 7), booking);
            printBooking(booking);
        }
        if(!IsFlightInSystem(booking)){
            std::cout<<"No flights in the system\n";
        }
    }




return 0;
}
