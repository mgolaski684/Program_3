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
};
int counter = 1;
void enter_func(int data_value, Bin_Tree* root) {
	//This is for when the list is empty on the left side
	//The lines below tells the function that if the new number is greater than the root node put it on the leftside
	if (root->data > data_value && !root->lnode) {
		Bin_Tree* Nnode = new Bin_Tree(data_value);
		root->lnode = Nnode;
		cout << "\nLeft of the Number on the level above it: " << Nnode->data << " Level of the Binary Tree: " << counter;
	}
	//This is for when the list isn't empty on the right side
	else if (root->data > data_value&& root->lnode) {
		counter = counter + 1;
		enter_func(data_value, root->lnode);
	}
	//This is assuming the List is empty on the right side
	//The line below tells the function that if the new number is greater than the root node fill in the first right node.
	if (root->data < data_value && !root->rnode) {
		Bin_Tree* Nnode = new Bin_Tree(data_value);
		root->rnode = Nnode;
		cout << "\nRight of the Number on the level above it: " << Nnode->data << " Level of the Binary Tree: " << counter;
	}
	//This is for when the list isn't empty on the right side
	else if (root->data < data_value && root->rnode) {
		//The Counter below now adds a level each time a position is filled in the Binary Tree
		counter = counter + 1;
		//The function below then adds the data value on in the new level the counter just created.
		enter_func(data_value, root->rnode);
	}

};
//void delete_func(int data_value, Bin_Tree* root) {
	//if (root == NULL) return data_value;

	//if (data_value < root->data)
		//root->lnode = delete_func(root->lnode, data_value);

	//else if (data_value > root->data)
		//root->rnode = delete_func(root->rnode, data_value);
//}

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
};