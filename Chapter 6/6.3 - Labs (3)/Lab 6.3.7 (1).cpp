#include <iostream>
#include <regex>
#include <math.h>
using namespace std;
class IPAddress {
    public:
        IPAddress(string ipaddr){
            this->ipaddr = ipaddr;
        }
        IPAddress(IPAddress *ipaddr){
            this->ipaddr = ipaddr->ipaddr;
        }
        virtual void print(){
            cout<<ipaddr;
        }
    protected:
        string ipaddr;
};

class IPAddressChecked : public IPAddress{
    public:
        IPAddressChecked(string ipaddr) : IPAddress(ipaddr){
            Check(ipaddr);
        }
        IPAddressChecked(IPAddressChecked *ipaddr) : IPAddress(ipaddr){
            Check(this->ipaddr);
        }
        void print(){
            IPAddress::print();
            cout<<" - "<<(checked?"Correct":"Not Correct");
        }
    private:
        bool checked;
        void Check(string ipaddr){
            regex reg("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");
            checked = regex_match(ipaddr, reg);
        }
};

int main()
{
    IPAddress *ipaddr = new IPAddress("1.2.3.4");
    IPAddressChecked *ipaddr1 = new IPAddressChecked("999.29.29.29");
    IPAddressChecked *ipaddr2 = new IPAddressChecked("199.29.29.29");

    ipaddr->print();
    cout<<endl;
    ipaddr1->print();
    cout<<endl;
    ipaddr2->print();
}
