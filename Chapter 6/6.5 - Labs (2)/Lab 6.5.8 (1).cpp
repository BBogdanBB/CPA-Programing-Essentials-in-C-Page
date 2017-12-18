#include <iostream>
#include <regex>
#include <math.h>
#include <vector>

class IPAddress{
    public:
        IPAddress(std::string ipaddr){
            addr = ipaddr;
        }
        void print(){
            std::cout<<addr<<std::endl;
        }
        bool check(){
            std::regex reg("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");
            return std::regex_match(addr, reg);
        }
    private:
        std::string addr;
};
class Network{
    public:
        Network(std::string name){
            this->name = name;
        }
        void Add(IPAddress addr){
            addresses.push_back(addr);
        }
        void PrintAll(){
            std::cout<<name<<":\n";
            for(int i = 0; i<addresses.size(); i++){
                addresses[i].print();
            }
        }
    private:
        std::vector<IPAddress> addresses;
        std::string name;
};
using namespace std;
int main()
{
    Network net1("Network 1");
    Network net2("Network 2");
    IPAddress *ipaddr;
    cout<<"Enter five ipaddresses\n";
    string ip;
    for(int i = 0; i<5; i++){
        do{
            cout<<"Enter "<<i+1<<" ipaddress\n";
            getline(cin, ip);
            ipaddr = new IPAddress(ip);
        }
        while(!ipaddr->check());
        if(i<=2)
            net1.Add(*ipaddr);
        if(i>=2)
            net2.Add(*ipaddr);
    }

    net1.PrintAll();
    net2.PrintAll();

}
