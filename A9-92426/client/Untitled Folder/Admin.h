#ifndef ADMIN_H_
#define ADMIN_H_

#include "User.h"

class Admin :public User
{
public:
	Admin();
	void load_data();
	void save_data();
	void delete_user(string name);
	void load_reports();
	void load_friends();
	vector<string> get_reports(){return reports;}
private:

	int report_index;
	vector<string>reports;
};

#endif