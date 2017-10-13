#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include "Bookeater.h"
#include "Library.h"

using namespace std;

bool user_available(string user);
ostream& operator<<(ostream& lout,const Library& lib);
ostream& operator<<(ostream& bout,const Book& bk);
string log_of_user(string line);


#endif