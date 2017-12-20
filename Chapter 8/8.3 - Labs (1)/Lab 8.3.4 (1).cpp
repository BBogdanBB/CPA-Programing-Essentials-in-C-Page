#include <iostream>
#include <string>

using namespace std;

struct Node
{

	int value;
	Node* leftChild;
	Node* rightChild;
	Node() : Node(0) { };
	Node(int value)
	{
		this->value = value;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	string Print()
	{
		string s = "";
		if (leftChild != nullptr) s += leftChild->Print();
		s.append(to_string(value));
		s.append(" ");
		if (rightChild != nullptr) s += rightChild->Print();
		return s;
	}
};

class BinaryTree
{

public:
	Node root;
	void Add(int value);
	bool Find(int value);
	BinaryTree(int value)
	{
		root = Node(value);
	}

};
bool BinaryTree::Find(int value)
{
	Node* temp = &this->root;
	while (temp != nullptr && temp->value != value)
	{
		if (temp->value > value) temp = temp->leftChild;
		else temp = temp->rightChild;
	}
	return temp != nullptr && temp->value == value;
}
void BinaryTree::Add(int value)
{
	if (!Find(value))
	{
		Node* temp = &this->root;
		while (temp->value != value)
		{
			if (temp->value > value)
			{
				if (temp->leftChild != nullptr)
					temp = temp->leftChild;
				else break;
			}
			else
			{
				if (temp->rightChild != nullptr)
					temp = temp->rightChild;
				else break;
			}
		}

		if (temp->value > value)
			temp->leftChild = new Node(value);
		else
			temp->rightChild = new Node(value);

	}
}
ostream& operator<<(ostream& os, BinaryTree& tree)
{
	os << tree.root.Print();
	return os;
}

int main()
{
	cout << "Input key nodes, or type \"q\" for quit" << endl;

	int node;
	string str;
	cin >> str;
	BinaryTree tree(atoi(str.c_str()));
	do
	{
		cin >> str;
		if (str == "q") break;
		node = atoi(str.c_str());
		tree.Add(node);
	} while (true);

	cout << tree << endl;

	return 0;
}
