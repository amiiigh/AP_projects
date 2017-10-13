#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

class Book;

class Category
{

public:
	Category();
	Category(string _name);
	void set_books(vector<Book> _book);
	vector<Book> get_books() const{return books;}
	string get_name() const {return name;}
private:
	string name;
	vector<Book> books;

};

#endif