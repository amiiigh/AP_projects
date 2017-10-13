#include "Post.h"

void Post::set_title(string _title)
{
	title = _title;
}

void Post::set_author(string _auth)
{
	author = _auth;
}

void Post::set_date(string _date)
{
	published_date = Date(_date);
}	

void Post::set_date_now()
{
	published_date.get_now();
}

void Post::set_liked_vec(vector<string> temp)
{
	liked_by = temp;
}

void Post::set_likes_line(string temp)
{
	likes_line = temp;
}

void Post::set_img_path(string path)
{
	img_path = path;
}

void Post::set_liked(string fnames)
{
	liked_by.clear();
	char c;
	string temp ="";
	for (int i=0 ; i< fnames.size(); i++)
	{
		c = fnames[i];
		if (c != ' ')
			temp += c;
		if (c ==' ' || i == fnames.size()-1) 
		{
			liked_by.push_back(temp);
			temp.clear();
		}
	}
}

void Post::set_text(string _text)
{
	text.clear();
	text = _text ;
}

bool Post::operator==(const Post& second_post)
{
	if (title == second_post.get_title() && author == second_post.get_author() &&
		img_path == second_post.get_img() && text == second_post.get_text() )
		return true;
	return false;
}


ostream& operator<<(ostream& out,Post ps)
{
	out << '#' <<endl;
	out << ps.title << endl;
	out << ps.author << endl;
	out << ps.img_path << endl;
	out << ps.published_date << endl;
	if (ps.liked_by.size()==0)
		out << '-'<<endl;
	for (int i=0 ; i< ps.liked_by.size(); i++)
	{
		out << ps.liked_by[i];
		if (i != ps.liked_by.size()-1)
			out << ' ';
		else
			out << endl	;
	}
	out << ps.text <<endl;
	return out;
}