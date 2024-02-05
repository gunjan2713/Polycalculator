#specifies the dependencies
output: main.o polycalculator.o linkedlist.o 
#compilatin command and then links these object files together into an executable 
	g++ main.o polycalculator.o linkedlist.o -o output
#specifies target main.o that depends on ource file main.cpp
main.o: main.cpp
#compilation command
	g++ -c main.cpp
polycalculator.o: polycalculator.cpp polycalculator.h 
	g++ -c polycalculator.cpp
linkedlist.o: linkedlist.cpp linkedlist.h 
	g++ -c linkedlist.cpp
#removes all the files in the current directory with the .o extension
clean:
	rm *.o output