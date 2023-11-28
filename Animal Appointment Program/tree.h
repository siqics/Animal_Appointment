#include "animal_appointment.h"




//Siqi Wen  CS202  11/15/2021
//This file contains the class interfaces for the node
//and the tree. This data structure will be used for
//the hierarchy in the animal_appointment.h file.
//The tree is a balanced tree - 2-3 tree. There are
//5 pointers in each node. In every node, there is
//either one data item or two data items. When there
//is only one data item, the node is either a leaf,
//or it has two children; when there are two data
//items in the node, the node is either a leaf or
//has three children.




class node
{
	public:
		node();
		~node();
		void remove_a_node();
		aquarium*& get_aquarium_zero();
		aquarium*& get_aquarium_one();
		node*& go_left();
		node*& go_middle();
		node*& go_right();

	private:
		aquarium* ptr_array[2];
		node* child[3];
};



class tree
{
	public:
		tree();
		tree(const tree& );
		~tree();
		int remove_a_tree();
		void find_one_in_tree(const string some_name, ostream& out);
		void display_all(ostream& out);
		void remove_one(const string some_name);
		tree& operator+= (const aquarium& );

	private:
		node* root;
		int remove_all_in_tree(node*& root);
		void insert(node*& root, const aquarium& to_add);
		void find_one(node*& root, const string some_name, int&, node*&, int&, int&);
		void display_all(node*& root, ostream& out);
		void remove_one(node*& root, node*&hold, int num);
};
