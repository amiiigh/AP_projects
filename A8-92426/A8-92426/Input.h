#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Bookeater.h"
#include "Library.h"
#include "Functions.h"
#include "Category.h"

using namespace std;

class Input
{

public:
	Input();
	//Input(string _command);
	void prossess_command(string command);
	void init_book_database();
	bool Book_available_in_main(string book_name);
private:
	Library Mlib;
	Bookeater current_user;
	bool available;

};

#endif