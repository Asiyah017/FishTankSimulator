// simulation.cpp
// purpose: defines the functions of the simulation class
// by : Asiyah Mumuney.
// date :04/25/2019

#include <iostream>
#include <fstream>
#include <sstream>
#include "fish.h"
#include "fishtank.h"
#include "simulation.h"
#include "termfuncs.h"
#include <unistd.h>

using namespace std;

/*
Name :Simulation
Arguments : none
Return type : Simulation
Purpose: teh constructor of the class
initializes all data members of the class.
*/

Simulation :: Simulation ()
{
	no_of_fishes = 0;
	no_of_cycles = 0;
    first = nullptr;
}

/*
Name :setup
Arguments : string filename
Return type : bool
Purpose: reads in the data for the fish and tank and stores 
it in their respective data members.
*/

bool Simulation :: setup (string filename)
{
    ifstream infile;
             infile.open (filename.c_str());
        string contents, type, hgt, wid;
        int height, width;
        getline (infile, contents);
        stringstream ss (contents);
        ss >> type >> hgt >> wid;
       
        height = string2int (hgt);
        width = string2int (wid);

        Tank.set_height (height);
        Tank.set_width (width);

        Fish aries;
        while (aries.read_fish (infile)){
            add_to_front(aries);
            no_of_fishes++;
        }
        
        infile.close ();

        return true;

}

/*
Name :run
Arguments : bool single_step, int fps
Return type : void
Purpose: this functions runs the whole simulation.
It draws the fishes on the tank, shows the tank, sleeps,
decreases lifetime of fishes, clears tank, moves the fishes,
increases no of cycles and repeats the whole process again 
while the user does not enter q
*/

void Simulation :: run (bool single_step, int fps)
{
    char input;
    
    input = 's';
    if (single_step == false){
        while (input != 'q'){
            node *temp = first;
            for (int i = 0; i < no_of_fishes; i++){
                //temp -> element.print ();
                temp -> element.draw (&Tank);
                temp = temp -> next;
            }
            
            Tank.show_tank();

            usleep (fps);
            decrease_lifetime (); 
            Tank.clear_tank();

            temp = first;
            for ( int i = 0; i < no_of_fishes; i++){
                temp -> element.move (Tank.get_height(), Tank.get_width());
                temp = temp -> next;
            }
            no_of_cycles++;
            input = getacharnow(10);
            
        }
    }
}

/*
Name :new_node
Arguments : fish aries
Return type : *node (pointer to a node)
Purpose: creates a new node and passes the arguments
of the function as data elements of the node.
*/

Simulation :: node *Simulation :: new_node (Fish aries, node *next)
{
    node *result = new node;
    result -> element = aries;
    result -> next    = next;

    return result;
}

/*
Name :add_to_front
Arguments : Fish aries
Return type : void
Purpose: adds teh given fish to the front of the 
linked list.
*/

void Simulation :: add_to_front (Fish aries)
{
    first = new_node (aries,first);
}

/*
Name :string2int
Arguments : string s
Return type : int
Purpose: takes in a string and returns an integer
*/

int Simulation :: string2int(string s) 
{
    stringstream ss(s);
    int result;
    ss >> result;
    if (ss.fail())
        throw logic_error("ERROR: " + s + " is not a numerical value");
    return result;
}

/*
Name :remove_from_position
Arguments : int position
Return type : void
Purpose: takes in the position of the node
 and calls the function that removes it.
 The functions are seperated because the latter performs 
 a recursive call and we don't want it to recurse every action. 
*/

void Simulation :: remove_from_position (int position)
{
    first = remove_from_position (position,first);
}

/*
Name :remove_from_position
Arguments : int position, node *firstnode
Return type : *node (pointer to a node)
Purpose: removes the positionth node of a 
linked list.
*/

Simulation :: node *Simulation :: remove_from_position ( int position , 
    node *firstnode)
{
    if (position == 0){
        return remove_first (firstnode);
    }
    else {
        firstnode -> next = remove_from_position (position-1, 
            firstnode -> next);
        return firstnode;
    }
}

/*
Name :remove_first
Arguments : node *firstnode
Return type : *node (pointer to a node)
Purpose: removes the first node in the linked list
*/

Simulation :: node  *Simulation :: remove_first (node *firstNode)
{
    node *toDiscard = firstNode;    
    node *newFirstNode = firstNode -> next;      
    delete toDiscard;
    first = newFirstNode;
    return newFirstNode;
}

void Simulation :: decrease_lifetime ()
{
    int lifetime;
    node *temp;
    temp = first;
    for ( int i = 0; i < no_of_fishes; i++){
        lifetime = temp -> element.lifetime();
        if (lifetime != -1){
        lifetime = lifetime - no_of_cycles;
        }
        if (lifetime == 0){
            remove_from_position (i);
            --no_of_fishes;
        }
    }
}

bool Simulation :: isEmpty(node *first)
{
    return first == nullptr;    
}

bool Simulation :: isEmpty()
{
    return isEmpty(first);
}

Simulation::~Simulation() 
{        
    while (not isEmpty())
        removeFirst(); 
}

void Simulation :: removeFirst() 
{        
    first = remove_first(first); 
}



