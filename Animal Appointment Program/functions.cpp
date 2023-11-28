#include "tree.h"



//Siqi Wen  CS202  11/12/2021
//This file contains the implementations of the
//member functions in the four classes in the .h
//file and the implementations of the member functions
//in the class for the data structure, which will support
//inserting, removing, retrieving and displaying the
//elements in the data structure. The data structure involved
//is a 2-3 tree, whose node contains five pointers. And each
//node either has one child or two children.





//Default Constructor - initialize all data members.
appointment::appointment(): animal_name(""), price(0), date(""), time_slot("")
{

}



//This function takes no argument and returns nothing,
//it reads in information for an appointment and stores
//them in the data members.
void appointment::get_info_appointment()
{
	cout << "\n\nEnter the animal name: ";
	getline(cin, animal_name);
	//cin.ignore(100, '\n');
	cout << "\nThe animal name you entered was: " << animal_name << "\n";

	cout << "\n\nEnter the price for the ticket: ";
	cin >> price;
	cin.ignore(100, '\n');
	cout << "\nThe price you entered was: " << price << "\n";

	cout << "\n\nEnter the date for the visit: ";
	getline(cin, date);
	//cin.ignore(100, '\n');
	cout << "\nThe date you entered was: " << date << "\n";

	cout << "\n\nEnter the time slot of the visit\n"
	     << "(for example: 2pm-5pm): ";
	getline(cin, time_slot);
	//cin.ignore(100, '\n');
	cout << "\nThe time slot you entered was: " << time_slot << "\n";
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator== (const appointment& operand2) const
{
	if(!animal_name.compare(operand2.animal_name))
                return true;
        return false;
}



//This function is a member function, it takes a string
//as an argument, it would compare the data member
//with the argument and return a bool value.
bool appointment::operator== (const string name) const
{
	if(!animal_name.compare(name))
		return true;
	return false;
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator!= (const appointment& operand2) const
{
	if(!animal_name.compare(operand2.animal_name))
                return false;
        return true;
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator< (const appointment& to_compare) const
{
	if(animal_name.compare(to_compare.animal_name) < 0)
                return true;
        return false;
}




//This function is a member function, it takes a string
//as an argument, it would compare the data member
//with the argument and return a bool value.
bool appointment::operator< (const string name) const
{
	if(animal_name.compare(name) < 0)
                return true;
        return false;
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator<= (const appointment& to_compare) const
{
	if(animal_name.compare(to_compare.animal_name) <= 0)
                return true;
        return false;
}



//This function is a member function, it takes a string
//as an argument, it would compare the data member
//with the argument and return a bool value.
bool appointment::operator<= (const string name) const
{
	if(animal_name.compare(name) <= 0)
                return true;
        return false;
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator>= (const appointment& to_compare) const
{
	if(animal_name.compare(to_compare.animal_name) >= 0)
                return true;
        return false;
}



//This function is a member function, it takes a string
//as an argument, it would compare the data member
//with the argument and return a bool value.
bool appointment::operator>= (const string name) const
{
	if(animal_name.compare(name) >= 0)
                return true;
        return false;
}



//This function is a member function, it takes an appointment object
//as an argument(passed by reference), it would compare the data member
//with the argument and return a bool value.
bool appointment::operator> (const appointment& to_compare) const
{
	if(animal_name.compare(to_compare.animal_name) > 0)
                return true;
        return false;
}



//This function is a member function, it takes a string
//as an argument, it would compare the data member
//with the argument and return a bool value.
bool appointment::operator> (const string name) const
{
	if(animal_name.compare(name) > 0)
                return true;
        return false;
}



//This function takes a string as an argument, it would
//compare the data member: animal_name with the argument
//and check if they match. If they match, 1 will be returned;
//otherwise, 0 will be returned.
int appointment::find_a_match(string input_name)
{
	if(!animal_name.compare(input_name))
		return 1;
	return 0;
}




//Default Constructor	
aquarium::aquarium(): aquarium_name(nullptr)
{
}




//Copy Constructor		
aquarium::aquarium(const aquarium& source): aquarium_name(nullptr)
{
	if(source.aquarium_name)
	{
		aquarium_name = new char[strlen(source.aquarium_name)+1];
		strcpy(aquarium_name, source.aquarium_name);
	}
}



//Destructor
aquarium::~aquarium()
{
	remove_aquarium();
}



//This function takes no argument and returns nothing, it
//deallocate the dynamic memory and reset the pointer to NULL.
void aquarium::remove_aquarium()
{
	if(aquarium_name)
	{
		delete []aquarium_name;
		aquarium_name = NULL;
	}
}




void aquarium::get_info_aqua()
{
	char input[100];

	cout << "\n\n\nEnter the aquarium animal's name: ";
	cin.get(input, 100, '\n');
	cin.ignore(100, '\n');

	aquarium_name = new char[strlen(input)+1];
	strcpy(aquarium_name, input);

	get_info_appointment();
}





//Copy one aquarium from the argument into the current object,
//but we first need to deallocate the memory that the current
//object is pointing at.
aquarium& aquarium::operator= (const aquarium& operand2)
{
	//check if there is self assignment taking place
	if(this == &operand2)
		return *this;
	
	//To avoid memory leak
	if(aquarium_name)
		delete []aquarium_name;

	if(operand2.aquarium_name)
	{
		aquarium_name = new char[strlen(operand2.aquarium_name)+1];
		strcpy(aquarium_name, operand2.aquarium_name);

		animal_name = operand2.animal_name;
		price = operand2.price;
		date = operand2.date;
		time_slot = operand2.time_slot;
	}

	return *this;      //return the current object
}
	


//This function is a non-member function, it takes an ostream object and
//an aquarium object as arguments (both passed by reference), it will
//display the data members and return an ostream object by reference.
ostream& operator<< (ostream& out_aqua, const aquarium& to_display)
{
        if(!to_display.aquarium_name)
                throw to_display.aquarium_name;

        out_aqua << "\nAquarium name: " << to_display.aquarium_name
		 << "\nAnimal name: " << to_display.animal_name
		 << "\nPrice: " << to_display.price
		 << "\nDate: " << to_display.date
		 << "\nTime slot: " << to_display.time_slot;

        return out_aqua;
}



//Default Constructor
wild_drivethru::wild_drivethru(): wild_name("")
{
}



//This function takes no argument and returns nothing,
//it will read in information and store it in the data
//members.
void wild_drivethru::get_info_wild_drivethru()
{
	get_info_appointment();
}



//This function is a non-member function, it takes an ostream object and
//a wild_drivethru object as arguments (both passed by reference), it will
//display the data members and return an ostream object by reference.
ostream& operator<< (ostream& out_wild, const wild_drivethru& to_display)
{
        out_wild << "\nWild Zoo name: " << to_display.wild_name
                 << "\nAnimal name: " << to_display.animal_name
                 << "\nPrice: " << to_display.price
                 << "\nDate: " << to_display.date
                 << "\nTime slot: " << to_display.time_slot;

        return out_wild;
}



//This function is a non-member function, it takes an istream object and
//a wild_drivethru object as arguments (both passed by reference), it will
//read in information and return an istream object by reference.
istream& operator>> (istream& in_wild, wild_drivethru& to_read)
{
	in_wild >> to_read.wild_name;
	return in_wild;
}






//Default Constructor
petting_zoo::petting_zoo(): petting_zoo_name("")
{
}



//This function takes no argument and returns nothing,
//it displays the information of the data members.
void petting_zoo::display_petting_zoo()
{
	cout << "\nPetting Zoo name: " << petting_zoo_name
	     << "\nAnimal name: " << animal_name
             << "\nPrice: " << price
             << "\nDate: " << date
             << "\nTime slot: " << time_slot;
}



//This function takes no argument and returns nothing, it reads
//in information and store them into the data members.
void petting_zoo::get_info_petting_zoo()
{
	cout << "\n\nEnter the name for the Petting Zoo: ";
	getline(cin, petting_zoo_name);
	//cin.ignore(100, '\n');

	get_info_appointment();
}



/*

		aquarium* ptr_array[2];
		node* child[3];
*/
//This is the default constructor for the node class.
//It initializes the data members.
node::node()
{
	ptr_array[0] = ptr_array[1] = NULL;
	child[0] = child[1] = child[2] = NULL;
}




/*
node::node(const node& source)
{
	if(source.get_aquarium_zero())
	{
		&get_aquarium_zero()(&source.get_aquarium_zero());
	}
	if(source.get_aquarium_one())
        {
                &get_aquarium_one()(&source.get_aquarium_one());
        }
	go_left() = source.go_left();
	go_middle() = source.go_middle();
	go_right() = source.go_right();
}
*/




//This is the desturctor for the node class, it will
//call another function to reset the data members.
node::~node()
{
	remove_a_node();
}



//This function takes no argument and returns nothing. It
//resets the data members in the node class to their zero
//equivalent values. This will be called in the destructor.
void node::remove_a_node()
{
	if(ptr_array[0])
	{
		ptr_array[0]->remove_aquarium();
		delete ptr_array[0];
		ptr_array[0] = NULL;
	}
	if(ptr_array[1])
        {
                ptr_array[1]->remove_aquarium();
                delete ptr_array[1];
                ptr_array[1] = NULL;
        }
	child[0] = child[1] = child[2] = NULL;
}



//This function takes no argument and returns an aquarium pointer
//by reference.
aquarium*& node::get_aquarium_zero()
{
	return ptr_array[0];
}



//This function takes no argument and returns an aquarium pointer
//by reference.
aquarium*& node::get_aquarium_one()
{
	return ptr_array[1];
}



//This function takes no argument and returns a node pointer
//by reference.
node*& node::go_left()
{
	return child[0];
}



//This function takes no argument and returns a node pointer
//by reference.
node*& node::go_middle()
{
	return child[1];
}



//This function takes no argument and returns a node pointer
//by reference.
node*& node::go_right()
{
	return child[2];
}



//Constructor - initialize the data members.
tree::tree(): root(nullptr)
{
}





tree::tree(const tree& )
{

}



//Destructor - reset the data members to
//their zero equivalent values.
tree::~tree()
{
	remove_a_tree();
}



//This function takes no argument and returns an integer.
//It would deallocate all memory for the tree and reset
//the root pointer to NULL. If the tree was empty before
//deleting, then 0 will be returned. It we deleted the
//tree successfully, then a positive integer will be returned.
int tree::remove_a_tree()
{
	if(!root)
		return 0;

	return remove_all_in_tree(root);
}



//This function takes a node pointer as an argument(passed
//by reference), an integer will be returned. It would
//deallocate all memory for the tree. If the tree was empty
//before deleting, then 0 will be returned. It we deleted the
//tree successfully, then a positive integer will be returned.
int tree::remove_all_in_tree(node*& root)
{
	if(!root)    //Empty tree or finished traversing
		return 0;

	if(!root->go_left() && !root->go_middle() && !root->go_right())
	{
		if(root->get_aquarium_zero())
		{
			root->get_aquarium_zero()->remove_aquarium();
			delete root->get_aquarium_zero();
			root->get_aquarium_zero() = NULL;
		}
		if(root->get_aquarium_one())
                {
                        root->get_aquarium_one()->remove_aquarium();
                        delete root->get_aquarium_one();
                        root->get_aquarium_one() = NULL;
                }
		delete root;
		root = NULL;
		return 1;
	}
	return remove_all_in_tree(root->go_left()) + remove_all_in_tree(root->go_middle()) + remove_all_in_tree(root->go_right());
}



//This function takes an aquarium object, and it would add the
//object to the tree and return the tree by reference.
tree& tree::operator+= (const aquarium& op2)
{
	this->insert(root, op2);
	return *this;
}



//This function takes a node pointer and an aquarium object,
//it would insert the object into the tree.
void tree::insert(node*& root, const aquarium& to_add)
{
	if(!root->go_left() && !root->go_right())
	{
		if(root->get_aquarium_zero() && root->get_aquarium_one())
		{
			root->go_left() = new node;
			root->go_right() = new node;
			if((*(root->get_aquarium_zero())) > to_add)
			{
				root->go_left()->get_aquarium_one() = const_cast<aquarium*> (&to_add);
				root->go_right()->get_aquarium_zero() = root->get_aquarium_one();
				root->get_aquarium_one() = NULL;
			}
			else if((*(root->get_aquarium_one())) > to_add)
			{
				root->go_left()->get_aquarium_one() = root->get_aquarium_zero();
				root->get_aquarium_zero() = const_cast<aquarium*> (&to_add);
				root->go_right()->get_aquarium_zero() = root->get_aquarium_one();
				root->get_aquarium_one() = NULL;
			}
			else if((*(root->get_aquarium_one())) < to_add)
			{
				root->go_left()->get_aquarium_one() = root->get_aquarium_zero();
				root->get_aquarium_zero() = NULL;
				root->go_right()->get_aquarium_zero() = const_cast<aquarium*> (&to_add);
			}
		}

		else if(root->get_aquarium_zero())
		{
			if((*(root->get_aquarium_zero())) < to_add)
				root->get_aquarium_one() = const_cast<aquarium*> (&to_add);
			else if((*(root->get_aquarium_zero())) > to_add)
			{
				root->get_aquarium_one() = root->get_aquarium_zero();
				root->get_aquarium_zero() = const_cast<aquarium*> (&to_add);
			}
		}
		else if(root->get_aquarium_one())
		{
			if((*(root->get_aquarium_one())) > to_add)
				root->get_aquarium_zero() = const_cast<aquarium*> (&to_add);
			else if((*(root->get_aquarium_one())) < to_add)
			{
				root->get_aquarium_zero() = root->get_aquarium_one();
				root->get_aquarium_one() = const_cast<aquarium*> (&to_add);
			}
		}
		return;
	}
	
	if(root->get_aquarium_zero() && (*(root->get_aquarium_zero())) > to_add)
		insert(root->go_left(), to_add);
	if(root->get_aquarium_one() && (*(root->get_aquarium_one())) < to_add)
		insert(root->go_right(), to_add);
	if(!root->get_aquarium_one() && (*(root->get_aquarium_zero())) < to_add)
		insert(root->go_right(), to_add);
	if(!root->get_aquarium_zero() && (*(root->get_aquarium_one())) > to_add)
		insert(root->go_left(), to_add);
	if((*(root->get_aquarium_zero())) < to_add && (*(root->get_aquarium_one())) > to_add)
		insert(root->go_middle(), to_add);
}



//This function takes a string and an ostream object as arguments,
//it would check if there's a match.
void tree::find_one_in_tree(const string some_name, ostream& out)
{
	if(!root)
	{
		cout << "\n\n\nEmpty tree...cannot retrieve...\n\n\n";
		return;
	}

	int match = 0;
	int num = 0;
	node* hold = NULL;
	int another_empty = 0;
	find_one(root, some_name, match, hold, num, another_empty);

	if(match)
	{
		cout << "\n\n\nCongrats! We found a matching aquarium animal!\n\n";
		if(num == 1)
			out << (*(root->get_aquarium_zero()));
		else if(num == 2)
			out << (*(root->get_aquarium_one()));
	}
	else
		cout << "\n\n\nSorry, there is no match with: " << some_name << "\n\n\n";
}



//This function takes two node pointers, a string, three integers as arguments, it
//would check if there's a match.
void tree::find_one(node*&root,const string some_name,int&match,node*&hold,int&num,int&another_empty)
{
	if(!root)
		return;
	if((*(root->get_aquarium_zero())) == some_name)
	{
		if(!root->get_aquarium_one())
                        another_empty = 1;
                else
                        another_empty = 2;

		match = 1;
		num = 1;
		hold = root;
		return;
	}
	if((*(root->get_aquarium_one())) == some_name)
	{
		if(!root->get_aquarium_zero())
                        another_empty = 1;
                else
                        another_empty = 2;

		match = 1;
		num = 2;
		hold = root;
		return;
	}

	if(!root->get_aquarium_zero())
	{
		if((*(root->get_aquarium_one())) > some_name)
			find_one(root->go_left(), some_name, match, hold, num, another_empty);
		if((*(root->get_aquarium_one())) <= some_name)
			find_one(root->go_right(), some_name, match, hold, num, another_empty);
	}
	else if(!root->get_aquarium_one())
        {
                if((*(root->get_aquarium_zero())) > some_name)
                        find_one(root->go_left(), some_name, match, hold, num, another_empty);
                if((*(root->get_aquarium_zero())) <= some_name)
                        find_one(root->go_right(), some_name, match, hold, num, another_empty);
        }
	else
	{
		if((*(root->get_aquarium_zero())) > some_name)
			find_one(root->go_left(), some_name, match, hold, num, another_empty);
		if((*(root->get_aquarium_zero())) <= some_name && (*(root->get_aquarium_one())) >= some_name)
			find_one(root->go_middle(), some_name, match, hold, num, another_empty);
		if((*(root->get_aquarium_one())) < some_name)
                        find_one(root->go_right(), some_name, match, hold, num, another_empty);
	}
}



//This function takes an ostream object and display
//all in the tree.
void tree::display_all(ostream& out)
{
	if(!root)
	{
		cout << "\n\n\nEmpty tree...cannot display...\n\n\n";
		return;
	}

	display_all(root, out);
}



//This function takes a node pointer and an ostream object as arguments,
//it would display all in the tree.
void tree::display_all(node*& root, ostream& out)
{
	if(!root)
		return;

	display_all(root->go_left(), out);

	if(!(root->get_aquarium_zero()) || !(root->get_aquarium_one()))
	{
		if((root->get_aquarium_zero()))
			out << (*(root->get_aquarium_zero()));
		else
			out << (*(root->get_aquarium_one()));
		display_all(root->go_right(), out);
	}
	else
	{
                out << (*(root->get_aquarium_zero()));
		display_all(root->go_middle(), out);
		out << (*(root->get_aquarium_one()));
		display_all(root->go_right(), out);
	}
}



//This functions takes a string as an argument and would remove one
//item from the tree.
void tree::remove_one(const string some_name)
{
	if(!root)
	{
		cout << "\n\n\nEmpty tree...cannot remove one item...\n\n\n";
		return;
	}

	int match = 0;
        int num = 0;
        node* hold = NULL;
	int another_empty = 0;
        find_one(root, some_name, match, hold, num, another_empty);

        if(match)
        {
		if(another_empty == 2 && num == 1)
		{
			remove_one(root->go_middle(), hold, num);
		}
		else
		{
			remove_one(root->go_right(), hold, num);
		}
		cout << "\n\n\nCongrats! Removed successfully!\n\n\n";
	}
	else
		cout << "\n\n\nSorry, there is no match with: " << some_name << "\n\n\n";
}



//This function takes two node pointers and an integer
//as arguments, it would remove one item in the tree.
void tree::remove_one(node*& root, node*& hold, int num)
{
	if(!root->go_left())
	{
		if(root->get_aquarium_zero())
		{
			if(num == 1)
			{		
				hold->get_aquarium_zero()->remove_aquarium();
				hold->get_aquarium_zero() = root->get_aquarium_zero();
				root->get_aquarium_zero() = NULL;
			}
			if(num == 2)
			{
				hold->get_aquarium_one()->remove_aquarium();
                                hold->get_aquarium_one() = root->get_aquarium_zero();
				root->get_aquarium_zero() = NULL;
			}
		}
		else
		{
			if(num == 1)
                        {
                                hold->get_aquarium_zero()->remove_aquarium();
                                hold->get_aquarium_zero() = root->get_aquarium_one();
                                root->get_aquarium_one() = NULL;
                        }
                        if(num == 2)
                        {
                                hold->get_aquarium_one()->remove_aquarium();
                                hold->get_aquarium_one() = root->get_aquarium_one();
                                root->get_aquarium_one() = NULL;
                        }
                }

		if(!root->get_aquarium_zero() && !root->get_aquarium_one())
		{
			delete root;
			root = NULL;
		}
		return;
	}
	remove_one(root->go_left(), hold, num);
}


