#ifndef USER_H_
#define USER_H_

using namespace std;

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Date.h"
#include "Post.h"
#include <ctime>
#include <string>
#include <QTime>
#include "Exeption.h"
#define USER_PATH "./Data/Users/"
#define IMG_PATH "./Data/Images/"

class User
{
public:
	User();
	User(string _username, string _password);
	// ~User();
	void set_user(string uname);
	void set_pass(string pass);
	void set_log();
	string get_username(){return username;}
	string get_password(){return password;}
	void load_data();
	void load_news();
	void save_data();
	void set_fav(vector<Post> newfav);
	void set_up(vector<Post> newups);
	string upload(string file_path);
	string generate_name(string old_path);
	void create_post(string title,string img_path,string text);
	vector<Post> get_up_post(){return up_posts;}
	vector<Post> get_news(){return news;}
	vector<Post> get_fav(){return fav_posts;}
	string get_profpic(){return prof_pic;}
	void set_profpic(string address){prof_pic = address;}
	vector<string> get_reqs(){return frequests;}
	void delete_from_news(Post liked_post);
	bool friend_with(string fname);
	void send_request(string fname);
	void report(string user);
	void load_requests();
	void delete_req(string fname);
	void add_to_friend(string fname);
	int get_nindex(){return news_index;}
	int get_reqindex(){return request_index;}
	void print_up();//for debug
protected:
	string username;
	string password;
	vector<string> friend_name;
	vector<Post> up_posts;
	vector<Post> fav_posts;
	vector<Post> news;
	vector<string>frequests;
	string prof_pic;
	int news_index;
	int request_index;
	bool login;

};

#endif