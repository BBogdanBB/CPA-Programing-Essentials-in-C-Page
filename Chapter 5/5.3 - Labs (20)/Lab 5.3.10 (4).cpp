#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
class User {
    public:
        User():User(0, ""){}
        User(int id, std::string name){
            this->id = id;
            this->name = name;
            this->month = 0;
        }
        int GetId(){
            return this->id;
        }
        int GetMonth(){
            return this->month;
        }
        std::string getName(){
            return this->name;
        }
        void Cancel(){
            this->month = 0;
        }
        void Extend(int month){
            if(this->month+month<0){
                std::cout<<"Cannot perform this operation";
                return;
            }
            this->month+=month;
        }
        void print(){
            std::cout<<"Member "<<this->id<<" : "<<this->name<<", subscription valid for "<<this->month<<" months\n";
        }
    private:
        int id;
        std::string name;
        int month;
};
void PrintAllUsers(User *users){
    bool g;
    int i = 0;
    while(i!=10){
        if((*users).GetId()!=0){
          (*users).print();
          g = true;
        }
        users++;
        i++;
    }
    if(!g)
        std::cout<<"No members in the system"<<std::endl;
}
bool IsId(User *u, int id){
    for(int i = 0; i<10; i++, u++){
        if((*u).GetId()==id)
            return true;
    }
    return false;
}
void CreateNewUser(std::string command, User *u ){
    std::string id = command.substr(0, command.find(' '));
    std::string name = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id);
    int id_i;
    ss1 >> id_i;
    if(id_i==0||name==id || id.size()<1 ||name.size()<1|| IsId(u, id_i)){
        std::cout<<"Cannot perform this operation \n";
        return;
    }
    bool g = false;
    for(int i = 0; i<10; i++, u++){
        if((*u).GetId()==0){
            g = true;
            *u = User(id_i, name);
            break;
        }
    }
    if(!g){
        std::cout<<"Cannot perform this operation \n";
    }
}
void Cancel(std::string command, User *u ){
    std::string id = command.substr(0, command.find(' '));
    std::istringstream ss1(id);
    int id_i;
    ss1 >> id_i;
    bool g;
    for(int i = 0; i<10; i++, u++){
        if((*u).GetId() == id_i){
            (*u).Cancel();
            g = true;
            break;
        }
    }
    if(!g){
        std::cout<<"There is no user with this id \n";
    }
}
void Delete(std::string command, User *u ){
    std::string id = command.substr(0, command.find(' '));
    std::istringstream ss1(id);
    int id_i;
    ss1 >> id_i;
    bool g;
    for(int i = 0; i<10; i++, u++){
        if((*u).GetId() == id_i){
            *u = User();
            g = true;
            break;
        }
    }
    if(!g){
        std::cout<<"There is no user with this id \n";
    }
}
void Extend(std::string command, User *u ){
    std::string id = command.substr(0, command.find(' '));
    std::string num = command.substr(command.find(' ')+1, command.size() - command.find(' '));
    std::istringstream ss1(id), ss2(num);
    int id_i, num_i;
    ss1 >> id_i;
    ss2>> num_i;
    bool g;
    for(int i = 0; i<10; i++, u++){
        if((*u).GetId() == id_i){
            (*u).Extend(num_i);
            g = true;
            break;
        }
    }
    if(!g){
        std::cout<<"There is no user with this id \n";
    }
}
int main() {
    std::cout<<"No members in the system"<<std::endl;
    User users[10];
    std::string command = "";
    while(command!="quit"){
        std::cout << "What would you like to do?: \n";
        std::getline(std::cin, command);
        if(command.find("create") == 0){
            CreateNewUser(command.erase(0, 7), users);
            PrintAllUsers(users);
        }
        else if(command.find("cancel") == 0){
            Cancel(command.erase(0, 7), users);
            PrintAllUsers(users);
        }
        else if(command.find("delete") == 0){
            Delete(command.erase(0, 7), users);
            PrintAllUsers(users);
        }
        else if(command.find("extend") == 0){
            Extend(command.erase(0, 7), users);
            PrintAllUsers(users);
        }
        else
            std::cout<<"Cannot perform this operation \n";

    }
return 0;
}
