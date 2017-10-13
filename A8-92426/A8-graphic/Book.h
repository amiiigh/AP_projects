#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <vector>
#include "Category.h"
using namespace std;

class Category;

class Book
{
public:
	Book(string all);
	friend ostream& operator<<(ostream& bout,const Book& bk);
	string get_name(){return name;}
	void print_for_show();
	string get_all(){return all_data;}

private:
	vector<Category> category;
	string all_data;
	string name;
	string publisher;
	string writer;
	int pub_year;

	//vector <Bookeater*> liked_by;
	
};

#endif