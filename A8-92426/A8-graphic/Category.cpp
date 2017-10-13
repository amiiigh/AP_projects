#include "Category.h"

Category::Category(string _name)
{
	name = _name ;	
}

Category::Category()
{
	name = "uncat";
}

void Category::set_books(vector<Book> _book)
{
	books = _book ;
}