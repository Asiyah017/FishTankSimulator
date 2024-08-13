// dictionary.cpp
// purpose: provides the meaning of limited words.
// by : Asiyah Mumuney.
// date : 02/14/19

#include <iostream>
#include <fstream>
#include <sstream>
#include "Fish.h"
#include "fishtank.h"
#include "simulation.h"
#include <unistd.h>

using namespace std;


Simulation :: Simulation ()
{
    no_of_fishes = 0;
    no_of_cycles = 0;
    //first -> next = nullptr; 
    first = nullptr;
}

// deconstructor

bool Simulation :: setup (string filename)
{
    ifstream infile;
             infile.open (filename.c_str());
        string contents, type;
        string hgt, wid;
        int height, width;


        // get data for tank
        // should have used infile.
        cout << "before getline" << endl;
        getline (infile, contents);
        cout << "before stringstream" << endl;
        stringstream ss (contents);
        ss >> type;
        ss >> hgt;
        ss >> wid;

        cout << "input: " << type << hgt << wid << endl; 

        height = string2int (hgt);
        width = string2int (wid);

        cout << "Output: " << height << width << endl;
        cout << "after stringstream" << endl;
        Tank.set_height (height);
        Tank.set_width (width);

        cout << "Tank_height: " << Tank.get_height() << endl;
        cout << "Tank_width: " << Tank.get_width() << endl;
        cout << "After sets" << endl;

                

        while (!infile.eof()){
            Fish aries;
            aries.read_fish (infile);
            add_to_front(aries);
            no_of_fishes++;
            
        }

        --no_of_fishes;
        cout << "Fishes: " << no_of_fishes << endl;
        
            infile.close ();
        

        return true;

}

/*void Simulation :: run (bool single_step, int fps)
{



    first -> element.draw (&Tank);
    Tank.show_tank ();
    usleep(500000);
    //decrease lifetime;
    first -> element.move(Tank.get_height(), Tank.get_width());
    first -> element.draw (&Tank);
    Tank.show_tank ();


}

*/
void Simulation :: run (bool single_step, int fps)
{
    string input;
    cout << "Enter q to quit" << endl;
    cin >> input;

    //draw
    cout << "here" << endl;
    

    while (input != "q"){
        cout << "in while loop" << endl;
        node *temp = first;
        for (int i = 0; i < no_of_fishes; i++){
            temp -> element.print();
            //temp -> element.draw (&Tank);
            temp = temp -> next;
        }

        cout << "after while loop" << endl;
        // print tank
        Tank.show_tank();

        cout << "after show tank" << endl;
        usleep (fps);
        //decrease_lifetime (); // if lifetime = o call remove function
        Tank.clear_tank();


        temp = first;
        for ( int i = 0; i < no_of_fishes; i++){
            temp -> element.move (Tank.get_height(), Tank.get_width());
            temp = temp -> next;
        }
        no_of_cycles++;
        cout << "Enter q to quit" << endl;
        cin >> input;

    }

}


Simulation :: node *Simulation :: new_node (Fish aries, node *next)
{
    node *result = new node;
    result -> element = aries;
    result -> next    = next;

    return result;
}


void Simulation :: add_to_front (Fish aries)
{
    first = new_node (aries,first);
}

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
void Simulation :: remove_from_position (int position)
{
    first = remove_from_position (position,first);
}

Simulation :: node *Simulation :: remove_from_position ( int position node *firstnode)
{
    if (position == 0){
        return remove_first (firstnode);
    }
    else {
        firstnode -> next = remove_from_position (position-1, firstnode -> next);
        return firstnode;
    }
}
Simulation :: node  *Simulation :: remove_first (node *firstNode)
{
    Node *toDiscard = firstNode;    
    Node *newFirstNode = firstNode−>next;                // The following are not necessary, but can help us        // detect bugs later        toDiscard−>element = "*** I was deleted ***";        toDiscard−>next    = nullptr;
    delete toDiscard;
    return newFirstNode;
}
void decrease_lifetime ()
{
    int lifetime;
    for ( int i = 0; i < no_of_fishes; i++){
        //lifetime = the fish.lifetime();
        if (lifetime != -1){
        lifetime = lifetime - no_of_cycles;
        }
        if (lifetime == 0){
            remove_from_position (position);
            --no_of_fishes;
        }
    }
}

StringLinkedList::~StringLinkedList() 
{        
    while (not isEmpty())
        removeFirst(); 
}

void StringLinkedList::removeFirst() 
{        
    enforceNonEmpty("Cannot remove first of empty list");
    front = removeFirst(front); 
}

//reduce no of fishes in remove at position
//reduce lifetime in decrease lifetime 
*/