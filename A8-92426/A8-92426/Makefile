a.out: main.o
	g++ *.o

main.o: main.cpp Bookeater.o Library.o Input.o
	g++ -c main.cpp 

Input.o: Bookeater.o Input.cpp Functions.cpp
	g++ -c Input.cpp  Functions.cpp

Bookeater.o: Bookeater.cpp Book.o Library.o
	g++ -c Bookeater.cpp 

Library.o: Library.cpp Category.o
	g++ -c Library.cpp 

Book.o: Book.cpp Category.o
	g++ -c Book.cpp 

Category.o: Category.cpp 
	g++ -c 	Category.cpp