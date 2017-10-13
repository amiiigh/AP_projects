#ifndef POST_H_
#define POST_H_

#include "Date.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Post
{

public:
	friend ostream& operator<<(ostream& out, Post ps);
	void set_title(string _title);
	void set_author(string _auth);
	void set_date(string _date);
	void set_date_now();
	void set_img_path(string path);
	void set_liked(string fnames);
	void set_liked_vec(vector<string> temp);
	void set_text(string _text);
	void set_likes_line(string temp);
	string get_title()const{return title;}
	string get_author()const{return author;}
	string get_date(){return published_date.convert();}
	vector<string> get_liked()const{return liked_by;}
	string get_text()const{return text;}
	string get_img()const{return img_path;}
	string get_likes_line(){return likes_line;}
	bool operator==(const Post& second_post);
	
private:
	string likes_line;
	string title;
	string author;
	Date published_date;
	string img_path;
	vector<string> liked_by;
	string text;

};

#endif