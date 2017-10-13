#include "Library.h"
#include "Category.h"

void Library::set_category(vector<Category> _categories)
{
	categories = _categories;
}
void Library::clear()
{
	categories.clear();
}