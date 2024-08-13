// simulation.h
// purpose: creates the simulation class
// and declares its data members and functions.
// by : Asiyah Mumuney.
// date :04/25/2019

#ifndef Simulation_H
#define Simulation_H
#include "fish.h"
#include "fishtank.h"

class Simulation
{
public:
        Simulation();
        bool setup (string filename);
        void run (bool single_step, int fps);
        ~Simulation ();
		

private:
        FishTank Tank;
        int no_of_fishes;
        int no_of_cycles;

        struct node{
        	Fish element;
        	node *next;
        };
        node *first;
        int string2int(string s);
        node *new_node(Fish aries, node *next);
        void add_to_front (Fish aries);
        void remove_from_position (int position);
        node *remove_from_position (int position, node *firstnode);
        node *remove_first (node *firstNode);
        void decrease_lifetime ();
        void removeFirst();
        bool  isEmpty(node *first);
        bool isEmpty();
        
        


        


        // create linked list of fishes here.
        // also make any dead fish removed from tank.
};

#endif