#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
    private:
        string name;
        double unit_price;
        int num_items;
        double total_price;
        bool is_change;
    public:
        ShopItemOrder(string name, double unit_price, int num_items);
        void set_name(string name);
        void set_unit_price(double unit_price);
        void set_num_items(int num_items);
        string get_name();
        double get_unit_price();
        int get_num_items();
        double get_total_price();
        void print();
};

ShopItemOrder::ShopItemOrder(string name, double unit_price, int num_items){
    this->name = name;
    this->num_items = num_items;
    this->unit_price = unit_price;
    this->total_price = unit_price*num_items;
}

string ShopItemOrder::get_name(){
    return ShopItemOrder::name;
}
double ShopItemOrder::get_unit_price(){
    return ShopItemOrder::unit_price;
}
int ShopItemOrder::get_num_items(){
    return ShopItemOrder::num_items;
}
double ShopItemOrder::get_total_price(){
    if(ShopItemOrder::is_change){
        ShopItemOrder::is_change = false;
        ShopItemOrder::total_price = ShopItemOrder::num_items*ShopItemOrder::unit_price;
    }
    return ShopItemOrder::total_price;
}
void ShopItemOrder::set_name(string name){
    if(name!="")
        ShopItemOrder::name = name;
}
void ShopItemOrder::set_num_items(int num_items){
    if(num_items<0)
        return;
    ShopItemOrder::num_items = num_items;
    ShopItemOrder::is_change = true;
}
void ShopItemOrder::set_unit_price(double unit_price){
    if(unit_price<0)
        return;
    ShopItemOrder::unit_price = unit_price;
    ShopItemOrder::is_change = true;
}
void ShopItemOrder::print(){
    cout<<"Order: "<<this->name<<" num_items = "<<this->num_items<<" unit_price = "<<this->unit_price<<" total price = "<<this->get_total_price();
}
int main()
{
    ShopItemOrder s("Some", 2.6, 2);
    s.print();
    return 0;
}
