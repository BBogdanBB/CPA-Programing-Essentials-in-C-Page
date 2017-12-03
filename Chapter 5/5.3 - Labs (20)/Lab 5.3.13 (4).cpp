#include <iostream>
using namespace std;
class Node
{
    public:
        Node(int val);
        ~Node();
        int value;
        Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
    //cout << "+Node" << endl;
}
Node::~Node()
{
    //cout << "-Node" << endl;
}
class List
{
    public:
        List();
        ~List();
        void push_front(int value);
        bool pop_front(int &value);
        int size();
        void push_back(int value);
    private:
        Node* head;
        Node* tail;
};

List::List()
{
    head = tail =  nullptr;
}
List::~List(){
    while(head){
        Node *nnode = head->next;
        delete head;
        head = nnode;
    }
}
int List::size(){
    int counter = 0;
    Node *curr = head;
    while(curr){
        curr = curr->next;
        counter++;
    }
    delete curr;
    return counter;
}
void List::push_front(int value)
{
    Node* new_head = new Node(value);
    if(!head){
        head = tail = new_head;
        return;
    }
    new_head->next = head;
    head=new_head;
}
void List::push_back(int value)
{
    Node* new_tail = new Node(value);
    if(!head){
        head = tail = new_tail;
        return;
    }
    tail->next = new_tail;
    tail = new_tail;
}
bool List::pop_front(int &value)
{
    if(head!=nullptr){
        value = head->value;
        Node *newNode = head;
        head = newNode->next;
        delete newNode;
        return true;
    }
    //delete head;
// implement the pop
// don't forget to delete the popped node!
// and fix the return value
    return false;
}

int main()
{
    List list;
//
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    int value = 0;
    while (list.pop_front(value))
    {
        cout << value << endl;
    }
    return 0;
}
