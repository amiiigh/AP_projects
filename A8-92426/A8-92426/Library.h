#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>
#include <vector>
#include "Category.h"
using namespace std;

class Library
{
public:
	friend ostream& operator<<(ostream& lout,const Library& lib);
	void set_category(vector<Category> _categories);
	vector<Book> get_books(){return categories[0].get_books();} //this will return uncatgories books!
	vector<Category> get_cat(){return categories;}

private:
	vector<Category> categories;
};

#endif