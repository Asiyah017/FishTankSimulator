#
#  Makefile for SimFishy project
#
#  A Makefile file lets you use the "make" Unix command to build a file or program.
#  It's a big help when you have multiple files to keep track of!
#
#  To use it, you can make a .o file by typing, for example:  make simft.o
#  To make the whole project (which will require all the .cpp files to
#  be compiled to .o files) you type "make simft" or even just "make".
#
#  Notice the compilation and linking commands that make generates and
#  runs for you!
#
#  Typing "make clean" will remove simft and all the .o files.
#

CXX      = clang++
CXXFLAGS = -g -Wall -Wextra

##
## If you add a separate linked list implementation,
## include its .o file here and a rule for the .o file below.
##
simft: simft.o fishtank.o fish.o simulation.o termfuncs.o
	$(CXX) $(CXXFLAGS) simulation.o simft.o fishtank.o fish.o termfuncs.o -o simft

simft.o:  simft.cpp fishtank.h
	$(CXX) $(CXXFLAGS) simft.cpp -c

simulation.o: simulation.cpp fish.h fishtank.h
	$(CXX) $(CXXFLAGS) simulation.cpp -c

fishtank.o:  fishtank.cpp fishtank.h 
	$(CXX) $(CXXFLAGS) fishtank.cpp -c

fish.o:  fish.cpp fish.h
	$(CXX) $(CXXFLAGS) fish.cpp -c

termfuncs.o:  termfuncs.cpp
	$(CXX) $(CXXFLAGS) termfuncs.cpp -c

clean:
	rm -rf simft simft.o fishtank.o fish.o simulation.o termfuncs.o
