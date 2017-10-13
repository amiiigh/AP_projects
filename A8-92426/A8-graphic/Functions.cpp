#include "Functions.h"


bool user_available(string user)
{
	fstream file ;
	string address = "./Data/Users/";
	address += user;
	file.open(address.c_str());
	if (file.is_open())
	{
		file.close();
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& bout,const Book& bk)
{
	//Franny and Zooey/J.D. Salinger/Little, Brown and Company/1955
	bout << bk.all_data << endl;
	return bout;
}

ostream& operator<<(ostream& lout,const Library& lib)
{
	for (int i=0 ; i< lib.categories.size() ; i++)
	{
		lout << '#'<< lib.categories[i].get_name()<<endl;
		for (int j=0 ; j< lib.categories[i].get_books().size() ;j++)
		{
			lout << lib.categories[i].get_books()[j];
		}
	}
	return lout;
}

string log_of_user(string line)
{
	char c;
	string temp = "";
	for (int i=0 ; i< line.size(); i++)
	{
		c = line[i];
		if (c !=' ')
			temp +=c;
		else 
			return temp;
	}
}