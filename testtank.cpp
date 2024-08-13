#include <iostream>
#include <string>
#include "fishtank.h"
// #include "simulation.h"

using namespace std;

int main()
{
	FishTank test_tank (10,12);
	test_tank.update_at (4, 6, '&');
	test_tank.show_tank();
	

	return 0;
}
