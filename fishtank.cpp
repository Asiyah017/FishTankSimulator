// fishtank.cpp
// purpose: defines the functions of the fishtank class
// by : Asiyah Mumuney.
// date :04/25/2019

#include <iostream>
#include <fstream>
#include <sstream>
#include "fish.h"
using namespace std;

/*
Name :FishTank
Arguments : none
Return type : FishTank
Purpose: the constructor of the class
initializes all data members.
*/

FishTank :: FishTank ()
{
    width  = 0;
    height = 0;
    for ( int i = 0; i < MAX_HGT; i++){
        for (int j = 0; j < MAX_WID; j++){
            tank[i][j] = ' ';
        }
    }
}

/*
Name :FishTank
Arguments : int hgt, int wid
Return type : FishTank
Purpose: same as constructor except
that it sets width to wid and height to 
hgt and then constructs the tank 
with those dimensions.
*/

FishTank :: FishTank ( int hgt, int wid)
{
        width  = wid;
        height = hgt;
        for ( int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                tank[i][j] = ' ';
            }
        }
}

/*
Name :set_height
Arguments : int hgt
Return type : bool
Purpose: sets the height based on the given value
if the given value is positive and less than the max height
and then returns false, else returns true
*/

bool FishTank :: set_height (int hgt)
{
        if ((hgt > 0) and (hgt < MAX_HGT)){
                height = hgt;
                return true;
        }
        else {
                return false;
        }
}

/*
Name :set_width
Arguments : int wid
Return type : bool
Purpose: sets the width of the tank
if it meets the condition that it is 
positive and less than the max width
*/
       
bool FishTank :: set_width (int wid)
{
        if ((wid > 0) and (wid < MAX_WID)){
            width = wid;
                return true;
        }
        else {
                return false;
        }
}

/*
Name :get_height
Arguments : none
Return type : int
Purpose: gets the height of the tank
*/

int FishTank :: get_height ()
{
        return height;
}

/*
Name :get_width
Arguments : none
Return type : int
Purpose: returns the width of the tank
*/

int FishTank :: get_width ()
{
        return width;
}

/*
Name :clear_tank
Arguments : none
Return type : void
Purpose: clears the tank by filling it 
with spaces
*/

void FishTank :: clear_tank ()
{
        for ( int i = 0; i < MAX_HGT; i++){
            for (int j = 0; j < MAX_WID; j++){
                tank[i][j] = ' ';
            }
        }        
}

/*
Name :update_at
Arguments : int row, int col, char c
Return type : void
Purpose: inserts a character in a particular 
index of the tank.
*/
       
void FishTank :: update_at (int row, int col, char c)
{
        tank [row][col] = c;
}

/*
Name :show_tank
Arguments : none
Return type : void
Purpose: prints the tank and its contents to cout
*/

void FishTank :: show_tank ()
{
    
        for ( int i = 0; i < height; i++){
                for ( int j = 0; j < width; j++){
                        cout << tank [i][j];
                }
                cout << endl;
        }
}
       

