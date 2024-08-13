

// A simple example of a client of a class representing 
// points in the X, Y plane.
//
// Mark A. Sheldon
// Tufts University
// Sprint 2013

#include <iostream>
#include <string>

#include "Point.h"

using namespace std;

int main()
{
        Point p1(-1, 2), p2(3, 4);

        Point p3 = p1.add(p2);
     
        cout << "p3:  ";
        p3.print();
        cout << endl;
}