#include "Book.h"
#include <cstdlib>
Book::Book(string all)
{
	name ="";
	writer="";
	publisher= "";
	pub_year = 0;
	all_data = all;
	string temp ;
	char c;


	for (int i=0 ; i< all.size(); i++)
	{
		c = all[i];
		if (c != '/')
			temp += c;
		else if ( name == "")
		{
			name = temp ;
			temp = "";
		}
		else if (writer == "")
		{
			writer = temp;
			temp = "";
		}
		else if (publisher =="")
		{
			publisher = temp ;
			temp = "";
		}
		if (i == all.size()-1)
		{
			pub_year = atoi(temp.c_str());
		}
	}
}

void Book::print_for_show()
{
	cout << " Book name : " << name <<endl;
	cout << " writer : "<< writer << endl;
	cout << " publisher : "<< publisher <<endl;
	cout << " published year : "<< pub_year <<endl;

}
