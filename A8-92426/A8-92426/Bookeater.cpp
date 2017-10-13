#include "Bookeater.h"
#include <sstream>
Bookeater::Bookeater()
{
	username = "";
	password = "";
	index =0 ;
	admin = false;
}

Bookeater::Bookeater(string _user,string _pass)
{
	username = _user;
	password = _pass;
	index =0;
	admin = false ; 
}

void Bookeater::load_data(string user)
{
	int i=0;
	fstream file;

	vector<Category> categories;
	vector<Book> books;

	string address="./Data/Users/";
	address += user;
	file.open(address.c_str());

	string temp;

	username = user; //set username
	getline (file,temp); // get pass
	password = temp; //set password
	if (user == "admin" )
		admin = true;
	
	else
	{
		getline (file,temp); //get junk
		getline (file,temp); //get first category

		//cout << "in the process of loading "<<endl;
		//cout << tmep<<endl;

		while (temp[0] != '-')
		{
			temp = temp.substr(1,temp.size()-1);

			//cout << "after substr " <<temp << endl;

			categories.push_back(Category(temp));
			getline (file ,temp);
			while (temp[0] != '#' && temp[0] != '-')
			{
				books.push_back(Book(temp));
				getline (file ,temp);
			}
			categories[i].set_books(books);
			books.clear();
			i++;
		}
		set_library(categories); //set all books and categories

		getline (file , temp);
		while (temp[0] != '-') // favorite books
		{
			favorite.push_back(Book(temp));
			getline (file , temp);
		}
		getline (file , temp); // get friends
		init_friends_name(temp);
		getline(file , temp); // get junk
		getline(file , temp);// get index
		index = atoi(temp.c_str());
		// getline (file , temp); //get recent activity
		// while (getline (file , temp))
		// {
		// 	recent_act.push_back(temp);
		// }
	}
	file.close();	
}

void Bookeater::save_data()
{
	stringstream ss;
	string address = "./Data/Users/";
	address += username;
	fstream file;
	file.open(address.c_str(),fstream::out);
	//writing user data 
	file << password <<endl;
	file <<"----\n";
	file << my_lib ;
	file <<"----\n";
	for(int i=0 ; i< favorite.size(); i++)
	{
		file << favorite[i] ;
	}
	file <<"----\n";
	for(int j=0 ; j< friends_name.size(); j++)
	{
		file << friends_name[j] << ' ';
	}
	file <<"\n----\n";
	ss << index ;
	file << ss.str();
	file.close();

}

void Bookeater::init_friends_name(string line)
{
	char c;
	string name = "";
	for (int i = 0 ; i < line.size()+1 ; i++)
	{

		c = line[i];
		if (c != ' ')
			name += c;
		else if (c == ' ')
		{
			friends_name.push_back(name);
			name = "";
		}
	}
}

void Bookeater::set_pass(string pass)
{
	password = pass;
}

void Bookeater::set_user(string uname)
{
	username = uname;
}

void Bookeater::set_library(vector<Category> category)
{
	my_lib.set_category(category);
}

void Bookeater::set_fav_books(vector<Book> fav_books)
{
	favorite = fav_books ;
}

void Bookeater::set_friends_name(vector<string>_friends)
{	
	friends_name = _friends;
}

bool Bookeater::have_this(string book_name)
{
	for (int i=0 ; i< my_lib.get_cat().size(); i++)
	{
		for (int j=0 ; j< my_lib.get_cat()[i].get_books().size(); j++)
		{
			if (my_lib.get_cat()[i].get_books()[j].get_name() == book_name)
				return true;
		}
	}
	return false ;
}

bool Bookeater::have_this_shelf(string shelf_name)
{
	for (int i =0 ; i<my_lib.get_cat().size(); i++)
	{
		if(my_lib.get_cat()[i].get_name() == shelf_name)
			return true;
	}
	return false;
}

bool Bookeater::friend_with(string fname)
{
	for (int i=0 ; i< friends_name.size() ; i++)
	{
		if (fname == friends_name[i])
			return true;
	}
	return false;
}