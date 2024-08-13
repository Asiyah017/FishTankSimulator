// fishtank.h
// purpose: creates the fishtank class
// and declares its data members and functions.
// by : Asiyah Mumuney.
// date :04/25/2019

#ifndef FISHTANK_H
#define FISHTANK_H

class FishTank
{
public:
       FishTank ();
       FishTank (int hgt, int wid);
       bool set_height (int hgt);
       bool set_width (int wid);
       int get_height ();
       int get_width ();
       void clear_tank ();
       void update_at (int row, int col, char c);
       void show_tank (); 

private:
        static const int MAX_HGT = 50;
        static const int MAX_WID = 200;
        int width, height;
        char tank [MAX_HGT][MAX_WID];
        
};

#endif