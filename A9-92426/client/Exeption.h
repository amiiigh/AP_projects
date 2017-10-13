#ifndef EXEP_H_
#define EXEP_H_
#include <iostream>
#include <string>

using namespace std;
class Ex
{
public:
	Ex(string error_inform);
	string get_message(){return message;}
private:
	string message;
	
};

#endif