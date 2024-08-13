/*
 * This program demonstrates the use of an getacharnow(time), which
 * returns when a character is available on cin or after time tenths
 * of a second, whichever happens first.
 * If the time expires with no character arriving, it returns '\0'
 *
 * The program prints a character 20 times on the first line of the
 * terminal over and over unless the user types a character.  If the
 * character is 'q', the program terminates, otherwise, it starts
 * displaying that character 20 times over and over again.
 *
 * Mark A. Sheldon, Tufts University, Spring 2019
 */
#include <iostream>
#include <unistd.h>

#include "files/termfuncs.h"

using namespace std;

const int WAIT_TIME = 250000;

int main()
{
     char c = '-';
     char new_c;

     while (c != 'q') {
	  screen_clear();
	  screen_home();
	  for (int i = 0; i < 20; ++i)
	       cout << c;
	  cout.flush();
	  usleep(WAIT_TIME);
	  new_c = getacharnow(0);  // try to get a character
	  if (new_c != '\0')       // if we got one
	       c = new_c;          //      use the new character
     }
     return 0;
}
