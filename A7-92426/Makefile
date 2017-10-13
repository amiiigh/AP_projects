a.out : main.o
	g++ *.o 
main.o : main.cpp functions.o classes.o
	g++ -c main.cpp 
functions.o : functions.cpp classes.o 
	g++ -c functions.cpp 
classes.o : classes.cpp classes.h
	g++ -c classes.cpp 