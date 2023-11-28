#include "tree.h"




//Siqi Wen  CS202  11/12/2021
//This is a test program for the Animal Appointment Scheduling Program.
//It will test out different functions based on the user's choice.
//A menu will be provided. Based on the user's choice, specific missions
//will be completed by invoking different functions in main. For example,
//adding animals of some specific type; retrieve animals of specific type,
//removing animals of specific type, we can also display and remove all
//animals of all types.



int main()
{
	welcome();

	int a_task = 0;         //Create an int variable for user's choice from menu.

	tree balanced_tree;

	vector <wild_drivethru> wild_animals;
	vector <petting_zoo> petting_animals;
	
	int wild_index = 0;
	int petting_index = 0;

	ostream& out_show = cout;
	istream& in_enter = cin;

	do
	{
		menu(a_task);

		if(a_task == 1)  //Add an animal in an Aquarium.
		{
			do
			{
				aquarium one_aqua_animal;
				one_aqua_animal.get_info_aqua();

				balanced_tree += one_aqua_animal;

				cout << "\n\n\nAdd another aquarium animal?\n";
			}while(again());
		}
		if(a_task == 2)  //Add an animal in a Wild Drive-thru Zoo.
		{
			do
			{
				wild_drivethru a_wild;

				cout << "\n\nEnter the name for the Wild Drive-thru zoo: ";
				in_enter >> a_wild;
				in_enter.ignore(100, '\n');
				a_wild.get_info_wild_drivethru();

				wild_animals.push_back(a_wild);

				cout << "\n\n\n\nThe info of this wild animal is:\n";
				out_show << a_wild;

				cout << "\n\n\nWanna add another wild animal?";

			}while(again());
		}
		if(a_task == 3)  //Add an animal in a Petting Zoo.
		{
			do
			{
				petting_zoo a_petting;

				a_petting.get_info_petting_zoo();
				petting_animals.push_back(a_petting);

				cout << "\n\n\n\nThe info of this petting animal is:\n";
				a_petting.display_petting_zoo();

				cout << "\n\n\nWanna add another petting animal?";

			}while(again());
		}
		if(a_task == 4)  //Find an animal in an Aquarium.
		{
			string a_name;
			cout << "\n\n\nEnter an aquarium animal name for retrieving: ";
			getline(cin, a_name);

			balanced_tree.find_one_in_tree(a_name, out_show);
		}
		if(a_task == 5)  //Find an animal in a Wild Drive-thru Zoo.
		{
			if(retrieve_in_wildvec(wild_animals, wild_index))
			{
				cout << "\n\n\nWe found a matching wild animal!\n"
				     << "\nHere is the info:\n\n";
				out_show << wild_animals[wild_index];
			}
			else
				cout << "\n\n\nSorry, no matching wild animal...\n\n";


		}
		if(a_task == 6)  //Find an animal in a Petting Zoo.
		{
			if(retrieve_in_pettingvec(petting_animals, petting_index))
			{
				cout << "\n\n\nWe found a matching petting animal!\n"
                                     << "\nHere is the info:\n\n";
				petting_animals[petting_index].display_petting_zoo();
			}
			else
                                cout << "\n\n\nSorry, no matching petting animal...\n\n";
		}
		if(a_task == 7)  //Remove an animal from an Aquarium.
                {
			string animal_name;
			cout << "\n\n\nEnter an aquarium animal name to be removed: ";
			getline(cin, animal_name);

			balanced_tree.remove_one(animal_name);
                }
		if(a_task == 8)  //Remove an animal from a Wild Drive-thru Zoo.
                {
			if(!wild_animals.size())
				cout << "\n\n\nEMPTY...Cannot remove...\n\n\n";
			else
			{
				cout << "\n\n\nThere is/are " << wild_animals.size()
			     	     << " wild animal(s) in the vector.\n\n";

				if(retrieve_in_wildvec(wild_animals, wild_index))
				{
					wild_animals.erase(wild_animals.begin() + wild_index);
					cout << "\n\nCongrats! We removed this wild animal.\n\n";
				}
				else
					cout << "\n\n\nSorry, no matching wild animal...\n";

				cout << "\n\nNow, there is/are " << wild_animals.size()
			     	     << " wild animal(s) in the vector...\n\n";
			}
                }
		if(a_task == 9)  //Remove an animal from a Petting Zoo.
                {
			if(!petting_animals.size())
                                cout << "\n\n\nEMPTY...Cannot remove...\n\n\n";
                        else
                        {
                                cout << "\n\n\nThere is/are " << petting_animals.size()
                                     << " petting animal(s) in the vector.\n\n";

                                if(retrieve_in_pettingvec(petting_animals, petting_index))
                                {
                                        petting_animals.erase(petting_animals.begin()+petting_index);
					cout << "\n\nCongrats! We removed this petting animal.\n\n";
                                }
                                else
                                        cout << "\n\n\nSorry, no matching petting animal...\n";

                                cout << "\n\nNow, there is/are " << petting_animals.size()
                                     << " petting animal(s) in the vector...\n\n";
                        }
                }
		if(a_task == 10)  //Display all animals from all Aquariums.
                {
			balanced_tree.display_all(out_show);
                }
		if(a_task == 11)  //Display all animals from all Wild Drive-thru Zoos.
                {
			if(!wild_animals.size())
				cout << "\n\n\nThere is NO animals in the Wild "
				     << "Drive-thru Zoos. Add some now!\n\n";
			else
			{
				cout << "\n\n\nHere are all the wild animals in "
			     	     << "the Wild Drive-thru Zoos:\n\n";

				for(int i = 0; i < wild_animals.size(); ++i)
				{
					out_show << wild_animals[i];
					cout << "\n\n";
				}
			}
                }
		if(a_task == 12)  //Display all animals from all Petting Zoos.
                {
			if(!petting_animals.size())
				cout << "\n\n\nThere is NO animals in "
				     << "Petting Zoos. Add some now!\n\n";
			else
			{
				cout << "\n\n\nHere are all the wild animals in "
			     	     << "the Petting Zoos:\n\n";

				for(int i = 0; i < petting_animals.size(); ++i)
				{
					petting_animals[i].display_petting_zoo();
					cout << "\n\n";
				}
			}
                }
		if(a_task == 13)  //Remove all animals from all Aquariums.
                {
			if(!balanced_tree.remove_a_tree())
				cout << "\n\n\nThere was no aquarium animals in the"
				     << " tree, no need to remove...\n\n\n";
			else
				cout << "\n\n\nCongrats! We removed all aquarium "
				     << "animals successfully!\n\n\n";

                }
		if(a_task == 14)  //Remove all animals from all Wild Drive-thru Zoos.
                {
			if(!wild_animals.size())
				cout << "\n\n\nEMPTY...No need to remove...\n\n\n";

			else
			{
				wild_animals.clear();

				if(!wild_animals.size())
					cout << "\n\n\nCongrats! You removed all animals "
				     	     << "from all Wild Drive-thru Zoos!\n\n\n";
			}
                }
		if(a_task == 15)  //Remove all animals from all Petting Zoos.
                {
			if(!petting_animals.size())
				cout << "\n\n\nEMPTY...No need to remove...\n\n\n";

			else
			{
				petting_animals.clear();

				if(!petting_animals.size())
					cout << "\n\n\nCongrats! You removed all animals "
				     	     << "from all Petting Zoos!\n\n\n";
			}
                }

		if(a_task != 16)
			cout << "\n\n\nCheck menu again?\n";

	}while(a_task != 16 && again());  //Call again function. Continue until user wants to stop.

	cout << "\n\n\n\n\nThank you for using our program!\nHave a great day!\n\n\n\n\n";

	return 0;
}




//Output the welcome message and explain what the program can do.
void welcome()
{
	cout << "\n\n\n\nWelcome to our Animal Appointment Scheduling program!\n\n\n";
}



//This function asks the user if they want to do it again by
//prompting the user for an input, true or false will be returned.
bool again()
{
	char answer;                              //Create a character variable
	do
	{
		cout << "\n\n\n\nPlease enter Y/y or N/n: ";
        	cin >> answer;                       //Read in the user's answer.
        	cin.ignore(100, '\n');
        	answer = toupper(answer);            //Convert the character to an uppercase letter
        	if (answer != 'Y' && answer != 'N')
        		cout << "\n\nYou entered a wrong letter. Please enter Y/y or N/n.";
	}while(answer != 'Y' && answer != 'N'); //continue until the uppercase letter is Y or N
	if (answer == 'Y')                      //This function will return true if answer is Y
        	return true;
	return false;                           //Return false if answer is N
}



//This function takes an integer as an argument and it will show the user the menu, and
//prompts the user to enter a choice in terms of which task the user wants to do.
void menu(int & task)
{
	cout << "\n\n\n\nHere is the menu:\n\n"
	     << "Enter 1 - Add an animal in an Aquarium.\n\n"
	     << "Enter 2 - Add an animal in a Wild Drive-thru Zoo.\n\n"
	     << "Enter 3 - Add an animal in a Petting Zoo.\n\n"
	     << "Enter 4 - Find an animal in an Aquarium.\n\n"
	     << "Enter 5 - Find an animal in a Wild Drive-thru Zoo.\n\n"
	     << "Enter 6 - Find an animal in a Petting Zoo.\n\n"
	     << "Enter 7 - Remove an animal from an Aquarium.\n\n"
	     << "Enter 8 - Remove an animal from a Wild Drive-thru Zoo.\n\n"
	     << "Enter 9 - Remove an animal from a Petting Zoo.\n\n"
	     << "Enter 10 - Display all animals from all Aquariums.\n\n"
	     << "Enter 11 - Display all animals from all Wild Drive-thru Zoos.\n\n"
	     << "Enter 12 - Display all animals from all Petting Zoos.\n\n"
	     << "Enter 13 - Remove all animals from all Aquariums.\n\n"
	     << "Enter 14 - Remove all animals from all Wild Drive-thru Zoos.\n\n"
	     << "Enter 15 - Remove all animals from all Petting Zoos.\n\n"
	     << "Enter 16 - Exit.\n\n\n\n\n"
	     << "Now, please enter a number (1-16): ";
        do
        {
        	cin >> task;               //Read in the user's answer.
		cin.ignore(100, '\n');
		if(task < 1 || task > 16)
	        	cout << "\n\nYou entered a wrong number!\n\nPlease enter "
			     << "a number between 1 and 16(inclusive): ";
        }while(task < 1 || task > 16);  //Repeat until user enters a proper number.
}



//This function takes a vector and an integer as arguments, both passed
//by reference. It would check for the matching animal name in the vector,
//and store the corresponding index number into the second argument. If
//there's a matching name, 1 will be returned, otherwise, 0 will be returned.
int retrieve_in_wildvec(vector <wild_drivethru> &vect, int & index)
{
	if(!vect.size())
	{
		cout << "\n\n\nEMPTY...Cannot retrieve...\n\n\n";
		return 0;
	}
	else
	{
		string a_name;
                cout << "\n\nEnter the animal's name for retrieving: ";
                getline(cin, a_name);

		int match = 0;

		for(int i = 0; !match && i < vect.size(); ++i)
		{
			if(vect[i].find_a_match(a_name))
			{
				match = 1;
				index = i;
			}
		}
		return match;
	}
}




//This function takes a vector and an integer as arguments, both passed
//by reference. It would check for the matching animal name in the vector,
//and store the corresponding index number into the second argument. If
//there's a matching name, 1 will be returned, otherwise, 0 will be returned.
int retrieve_in_pettingvec(vector <petting_zoo> &vect, int & index)
{
	if(!vect.size())
	{
		cout << "\n\n\nEMPTY...Cannot retrieve...\n\n\n";
		return 0;
	}
	else
	{
		string a_name;
                cout << "\n\nEnter the animal's name for retrieving: ";
                getline(cin, a_name);

		int match = 0;

		for(int i = 0; !match && i < vect.size(); ++i)
		{
			if(vect[i].find_a_match(a_name))
			{
				match = 1;
				index = i;
			}
		}
		return match;
	}
}
