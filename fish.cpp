// fish.cpp
// purpose: defines the functions of the fish class
// by : Asiyah Mumuney.
// date :04/25/2019

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "fish.h"
#include "fishtank.h"
using namespace std;

/*
Name :Fish
Arguments : none
Return type : none
Purpose: constructor of the fish class
initializes all data members in the fish
class.
*/

Fish :: Fish ()
{
	height = 0;
	width =  0;
	y_speed = 0;
	x_speed = 0;
	lifespan = -1;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			fish[i][j] = ' ';
		}
	}
}

/*
Name :read_fish
Arguments : address of an istream
Return type : bool
Purpose: reads in the data for the fish 
from istream, returns false if any of the 
data is missing, otherwise returns true.
*/

bool Fish :: read_fish (istream &input)
{
	string type,contents;
	input >> type;
	if (type == "fish"){
		input >> height;
		input >> width;
		input >> fish_row;
		input >> fish_column;
		input >> y_speed;
		input >> x_speed;
		input >> lifespan;
		input >> fish_name;

		for (int i = 0; i < (height+1); i++){
			getline (input,contents);
			for (int j = 0; j < contents.length(); j++){
				fish[i][j] = contents[j];
			}
			
		}

		return true;
	}

	else {
		return false;
	}
	
}

/*
Name :get_name
Arguments : none
Return type : string
Purpose: returns the name of the fish.
This function is created becasue the name 
of the fish is a private data member. 
Therefore only functions of the class can
access the name. This function allows
functions outside the class use the name 
of the fish.
*/

string Fish :: get_name ()
{
	return fish_name;
} 

/*
Name :set_name
Arguments : string name
Return type : none
Purpose: sets the name of the fish.
The reason for this is the same as above 
for get_name
*/

void Fish :: set_name (string name)
{
	fish_name = name;
}      

/*
Name :set_pos
Arguments : int row, int col
Return type : none
Purpose: sets the initial positions of the fish.
The reason for this is the same as above 
for get_name
*/

void Fish :: set_pos ( int row, int col)
{
	fish_row = row;
	fish_column = col;
}

/*
Name :get_height
Arguments : none
Return type : int
Purpose: gets the height of the fish
The reason for this is the same as above 
for get_name
*/

int Fish :: get_height ()
{
	return height;
}

/*
Name :get_width
Arguments : none
Return type : int
Purpose: gets the width of the fish
The reason for this is the same as above 
for get_name
*/

int Fish :: get_width()
{
	return width;
}

/*
Name :lifetime
Arguments : none
Return type : int
Purpose: gets the lifetime of the fish
The reason for this is the same as above 
for get_name
*/

int Fish :: lifetime ()
{
	return lifespan;
}

/*
Name :move
Arguments : int tank_hgt, tank_wid
Return type : void
Purpose: for every second, move the tank 
speed indexes, when at the end of the tank,
wrap around.
*/

void Fish :: move ( int tank_hgt, int tank_wid)
{
	
	if ((fish_column + width + x_speed) < tank_wid){
		fish_column = fish_column + x_speed;
	}
	else {
		fish_column = 0;
	}
	/*
	else if ((fish_column + x_speed) < tank_wid){
		
	}
	*/

	if ((fish_row + height + y_speed) < tank_hgt){
		fish_row = fish_row + y_speed;
	}
	else {
		fish_row = 0;
		 //wrap around
	}
	// consider calling tank's update at.
}        

/*
Name :draw
Arguments : FishTank *tank
Return type : void
Purpose: draws the fish on the tank
*/
 
void Fish :: draw (FishTank *tank)
{ 
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			int row = (int) fish_row;
			int column = (int) fish_column; 
			tank -> update_at (row+i, column+j, fish[i][j]);
		}
	}
}        
  
/*
Name :print
Arguments : none
Return type : void
Purpose: prints the fish to cout.
*/       
void Fish :: print ()
{
	for (int i = 0; i < (height+1); i++){
		for (int j = 0; j < width; j++){
			cout << fish[i][j];
		}

		cout << endl;
	}
}

/*
Name :string2int
Arguments : string s
Return type : int
Purpose: takes in a string and returns an integer
*/

int Fish :: string2int(string s) 
{
    stringstream ss(s);
    int result;
    ss >> result;
    if (ss.fail())
        throw logic_error("ERROR: " + s + " is not a numerical value");
    return result;
}
