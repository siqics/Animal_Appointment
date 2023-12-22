#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;





//Siqi Wen   CS202  11/10/2021
//This file is a .h file that contains the interfaces of
//a base class and three derived classes. The base class
//is: appointment, which contains three data members: an
//integer for price, a string for date and a string for
//the available time slot. One derived class is: aquarium,
//which contains a char pointer representing the aquarium's
//name; another derived class: wild_drivethro, which contains
//a string for the name of the wild animal-drive through zoo;
//and another derived class: petting_zoo, which contains a
//string for the petting zoo's name and a float number for
//the estimated waiting time of the line to pet an animal.





class appointment
{
	public:
		appointment();
		void get_info_appointment();

		bool operator== (const appointment& ) const;
		bool operator== (const string name) const;
		bool operator!= (const appointment& ) const;
		bool operator< (const appointment& ) const;
		bool operator< (const string name) const;
        	bool operator<= (const appointment& ) const;
        	bool operator<= (const string name) const;
        	bool operator>= (const appointment& ) const;
        	bool operator>= (const string name) const;
        	bool operator> (const appointment& ) const;
        	bool operator> (const string name ) const;
		int find_a_match(string input_name);
	protected:
		string animal_name;
		int price;
		string date;
		string time_slot;
};



class aquarium: public appointment
{
	public:
		aquarium();
		aquarium(const aquarium& source);
		~aquarium();
		void remove_aquarium();

		void get_info_aqua();

		aquarium& operator= (const aquarium&);
		friend ostream& operator<< (ostream& out_aqua, const aquarium& to_display);
	protected:
		char* aquarium_name;
};




class wild_drivethru: public appointment
{
	public:
		wild_drivethru();
                void get_info_wild_drivethru();

                friend ostream& operator<< (ostream&, const wild_drivethru& );
                friend istream& operator>> (istream&, wild_drivethru& );
	protected:
		string wild_name;
};



class petting_zoo: public appointment
{
	public:
		petting_zoo();
		void display_petting_zoo();
                void get_info_petting_zoo();
	protected:
		string petting_zoo_name;
};



//Prototypes
void welcome();            //Output the welcome message.
bool again();              //Ask if the user wants to do again.
void menu(int & task);     //Show the user the menu.
int retrieve_in_wildvec(vector <wild_drivethru> &vect, int & index);
int retrieve_in_pettingvec(vector <petting_zoo> &vect, int & index);
