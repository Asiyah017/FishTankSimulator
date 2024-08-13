
// fish.h
// purpose: creates the class and declares data
// members and functions.
// by : Asiyah Mumuney.
// date : 04/25/2019

#include <iostream>
#include "fishtank.h"

using namespace std;

#ifndef FISH_H
#define FISH_H

class Fish
{
public:
        Fish();
        bool read_fish(istream &input);
        string get_name();
        void set_name (string name);
        void set_pos (int row, int col);
        int get_height ();
        int get_width ();
        int lifetime();
        void move (int tank_hgt, int tank_wid);
        void draw (FishTank *tank);
        void print ();

private:
	int height, width, lifespan;
        float fish_row, fish_column, y_speed, x_speed;
        string fish_name;
        static const int MAX_HGT = 30;
        static const int MAX_WID = 60;
        char fish [MAX_HGT][MAX_WID];
        int string2int(string s);
        
};

#endif


