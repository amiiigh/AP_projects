#ifndef BOOKEATER_H_
#define BOOKEATER_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Library.h"
#include "Book.h"
#include "Category.h"
#include <fstream>

using namespace std;

class Bookeater
{
public:
	Bookeater();
	Bookeater(string _user,string _pass);
	void set_pass(string pass);
	void set_user(string uname);
	void set_library(vector<Category> category);
	void set_fav_books(vector<Book> fav_books);
	void set_friends_name(vector<string>_friends);
	void load_data(string user);
	void init_friends_name(string line);
	void save_data();
	bool have_this(string book_name);
	bool have_this_shelf(string shelf_name);
	bool friend_with(string fname);
	string get_pass() {return password;}
	string get_user() {return username;}
	Library get_lib() {return my_lib;}
	vector<Book> get_fav(){return favorite;}
	vector<string> get_friends(){return friends_name;}
	bool get_admin(){ return admin;}
	int get_index(){return index;}
	void set_index(int count){ index = count;}
	void clear();
private:
	string username;
	string password;
	//int uniqe_ID;
	int index;
	Library my_lib;
	//vector<Bookeater> friends;
	vector<string> friends_name;
	vector<Book> favorite;
	vector<string> recent_act;
	bool admin;
};

#endif