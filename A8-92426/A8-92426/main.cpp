#include <iostream>
#include <fstream>
#include "Bookeater.h"
#include "Library.h"
#include "Input.h"

using namespace std;

int main()
{
	string in;
	Input inp;
	cin >> in; 
	while (in != "exit")
	{
		inp.prossess_command(in);

		cin >> in;
	}
	return 0;
}