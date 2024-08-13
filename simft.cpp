// simft.cpp
// purpose: the main to the simulation
// calls simulation's functions 
// which calls on functions of other classes.
// by : Asiyah Mumuney.
// date :04/25/2019

#include <iostream>
#include <string>
#include "fish.h"
#include "fishtank.h"
#include "simulation.h"
#include "termfuncs.h"
#include <unistd.h>
using namespace std;


const int FPS = 5;              
const bool stepbystep = false;  

int main(int argc, char *argv[])
{
	Simulation s;

	if (argc == 1) {
		cout << "Filename needed\n";
		return 1;
	}
	if (not s.setup(string(argv[1])))
		return 1;

	s.run(stepbystep, FPS);

	return 0;
}

