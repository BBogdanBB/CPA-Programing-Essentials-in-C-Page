#include <iostream>
using namespace std;
class Node
{
    public:
        Node(int val);
        ~Node();
        int value;
        Node* next;
        Node* prev;
};

Node::Node(int val) : value(val), next(nullptr), prev(nullptr)
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
        List(List &other);
        void push_front(int value);
        bool pop_front(int &value);
        int size();
        void push_back(int value);
        bool pop_back(int &value);
        int at(int index);
        void insert_at(int index, int value);
        void remove_at(int index);
        Node* Head(){
            return head;
        }
    private:
        Node* head;
        Node* tail;
};

List::List()
{
    head = tail =  nullptr;
}
List::List(List &other)
{
    Node *curr = other.head;
    head = tail = new Node(curr->value);
    Node *temp = head;
    while(curr->next){
        temp->next = new Node(curr->next->value);
        temp->next->prev = temp;
        temp = temp->next;
        curr = curr->next;
        tail = temp;
    }

}
int List::size(){
    int counter = 0;
    Node *curr = head;
    while(curr){
        curr = curr->next;
        counter++;
    }
    return counter;
}
void List::push_front(int value)
{
    Node* new_head = new Node(value);
    if(!head){
        head = tail = new_head;
        return;
    }
    head->prev = new_head;
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
    new_tail->prev = tail;
    tail = new_tail;
}
bool List::pop_front(int &value)
{
    if(!head)
        return false;
    value = head->value;
    if(head == tail){
        delete head;
        head = tail = nullptr;
        return true;
    }
    Node *newNode = head;
    head = newNode->next;
    delete newNode;
    head->prev = nullptr;
    return true;

    //delete head;
// implement the pop
// don't forget to delete the popped node!
// and fix the return value
}
bool List::pop_back(int &value){
    if(!head)
        return false;
    value = tail->value;
    if(head == tail){
        delete head;
        head = tail = nullptr;
        return true;
    }
    Node *nnode = tail;
    tail = tail->prev;
    delete nnode;
    tail->next = nullptr;
    return true;
}

int List::at(int index){
    if(index<0||index>=size())
        throw invalid_argument("index must 0 <= index <= size");
    if(index == 0)
        return head->value;
    if(index == size() - 1)
        return tail->value;

    Node *n = head;
    while(index--)
        n=n->next;

    return n->value;
}

void List::insert_at(int index, int val){
    if(index == 0){
        push_front(val);
        return;
    }
    if(index == size()){
        push_back(val);
        return;
    }

    Node *new_node = new Node(val);
    Node *curr = head;
    --index;
    while(index--)
        curr = curr->next;

    new_node->next = curr->next;
    new_node->prev = curr;
    curr->next = new_node;
    new_node->prev = curr;
    new_node->next->prev = new_node;
}

void List::remove_at(int index){
    if(index == 0){
        pop_front(index);
        return;
    }
    if(index == size()-1){
        pop_back(index);
        return;
    }
    if(index<0 || index>=size())
        return;
    --index;
    Node *curr = head;
    while(index--)
        curr = curr->next;
    Node *temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
    temp->prev = curr;
}
void printList(List &list)
{
    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        cout << "list[" << i << "] == " << list.at(i) << endl;
    }
}

int main()
{
    List list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(4);
    cout << "list1" << endl;
    printList(list1);
    cout << endl;
    List list2(list1);
    cout << "list2" << endl;
    printList(list2);
    cout << endl;
    list1.insert_at(1, 6);
    list2.remove_at(2);
    cout << "list1" << endl;
    printList(list1);
    cout << "list2" << endl;
    printList(list2);
    cout << endl;
    return 0;

}
