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
    private:
        Node* head;
};

List::List()
{
    head = nullptr;
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
    new_head->next = head;
    head=new_head;
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
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		int value=0;
		list.pop_front(value);
		cout << "popped " << value << ", size: " << list.size() << endl;
	}
	return 0;
}
