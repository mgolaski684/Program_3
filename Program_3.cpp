#include <iostream>
using namespace std;

class Bin_Tree {
public:
	int data;
	Bin_Tree* root;
	Bin_Tree* lnode;
	Bin_Tree* rnode;
	Bin_Tree(int data_value) {
		data = data_value;
	}
	Bin_Tree* remove(int data_value, Bin_Tree* root) {
		Bin_Tree* temp;
		if (root == NULL)
			return NULL;
		else if (data_value < root->data)
			root->lnode = remove(data_value, root->lnode);
		else if (data_value > root->data)
			root->rnode = remove(data_value, root->rnode);
		else
		{
			temp = root;
			if (root->lnode == NULL)
				root = root->rnode;
			else if (root->rnode == NULL)
				root = root->lnode;
			delete temp;
		}
		return root;
	}
	void Bin_Tree::Bin_Tree remove(int data_value, Bin_Tree* root) {
		root = remove(data_value, root);
	}
};
int counter = 1;
void enter_func(int data_value, Bin_Tree* root) {

	if (root->data > data_value && !root->lnode) {
	Bin_Tree* Nnode = new Bin_Tree(data_value);
	root->lnode = Nnode;
	cout << "\nLeft of the Number on the level above it: " << Nnode->data << " Level of the Binary Tree: " << counter;
	}
	else if (root->data > data_value&& root->lnode) {
		counter = counter + 1;
		enter_func(data_value, root->lnode);
	}
	if (root->data < data_value && !root->rnode) {
		Bin_Tree* Nnode = new Bin_Tree(data_value);
		root->rnode = Nnode;
		cout << "\nRight of the Number on the level above it: " << Nnode->data << " Level of the Binary Tree: " << counter;
	}
	else if (root->data < data_value && root->rnode) {
		enter_func(data_value, root->rnode);
	}

};

int main()
{
	//This is for the actual representation of the Binary Tree.
	cout << "				13";
	cout << "\n		10" << "				15";
	cout << "\n	7" << "		12" << "		14" << "		16";
	cout << "\n6";

	//This code is to use the function created above
	Bin_Tree rootnode(13);
	Bin_Tree* root = &rootnode;
	cout << "\n" << "\nThe root of the Tree:" << rootnode.data;
	enter_func(10, root);
	counter = 1;
	enter_func(15, root);
	counter = 1;
	enter_func(12, root);
	counter = 1;
	enter_func(7, root);
	counter = 1;
	enter_func(16, root);
	counter = 1;
	enter_func(14, root);
	counter = 1;
	enter_func(6, root);
	remove(6, root);
};