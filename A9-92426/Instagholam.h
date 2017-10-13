#ifndef INSTAGHOLAM_H_
#define INSTAGHOLAM_H_

#include <fstream>
#include <cstdlib>
#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Exeption.h"

using namespace std;

#define USER_PATH "./Data/Users/"

class Instagholam
{
public:
	Instagholam();
	// ~Instagholam();
	void init_folders();
	void register_user(string uname,string pass);
	void logout();
	void login(string user,string pass);
	bool available_this(string username);
	void load_users_list();
	bool is_kicked(string uname);

//private:
	User* current_user;
	Admin* admin;
	vector<string>users_list;
	bool admin_log;
};

#endif