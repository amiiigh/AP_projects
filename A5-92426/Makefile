a.out : main.o
	g++ *.o 
main.o : main.cpp AccountBook.o
	g++ -c main.cpp 
AccountBook.o : AccountBook.cpp Contact.o 
	g++ -c AccountBook.cpp 
Contact.o : Contact.cpp Contact.h
	g++ -c Contact.cpp 