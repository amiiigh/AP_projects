#include "Instagholam.h"
#include <iterator>

Instagholam::Instagholam()
{
	current_user = NULL;
	admin_log = false;
}

void Instagholam::register_user(string uname,string pass)
{
	fstream file;
	string address;
	address = USER_PATH + uname;
	file.open(address.c_str(), fstream::out);
	file.close();
	file.open("./Data/Users_list",ios::out | ios::in | ios::app);
	if (!file.is_open())
	{
		throw Ex("can't regester now (file problem)!");
		return;
	}
	file << uname <<endl;
	file.close();
	current_user = new User;
	current_user->set_user(uname);
	current_user->set_pass(pass);
	current_user->save_data();
}

void Instagholam::logout()
{
	if (current_user!= NULL)
		delete current_user;
	if (admin_log == true)
		admin_log =false;

	// cout << "logout ....!"<<endl;
	users_list.clear();
}

void Instagholam::login(string user,string pass)
{
	if (available_this(user))
	{
		if (user != "ghodrat")
		{
			if (is_kicked(user))
			{
				throw Ex("You have been kicked from Instagholam because of users' reports!");
			}
			current_user = new User;
			current_user->set_user(user);
			current_user->load_data();
			if (current_user->get_password() == pass)
			{
				// cout << "data loaded!"<<endl;
				current_user->load_news();
				current_user->load_requests();
				current_user->save_data();
				current_user->load_data();

			}

			else //throw ex wrong pass
			{
				delete current_user;
				throw Ex("wrong password ! try again...");
			}
		}

		else
		{
			admin = new Admin;
			admin_log =true;
			admin->set_user(user);
			admin->load_data();
			if (admin->get_password() == pass)
			{
				admin->load_news();
				admin->save_data();
			}

			else 
			{
				delete admin;
				admin_log = false;
				throw Ex("wrong password ! try again...");
			}
		}

	}

	else 
	{
		throw Ex("there is no such a user!");
	}
}

void Instagholam::load_users_list()
{
	fstream file ;
	string temp;
	file.open("./Data/Users_list");
	while(getline(file,temp))
	{
		users_list.push_back(temp);
	}

	file.close();
}

bool Instagholam::available_this(string username)
{
	fstream file ;
	string address = USER_PATH + username;
	file.open(address.c_str());
	if(file.is_open())
	{
		file.close();
		return true;
	}
	else 
		return false;
}

bool Instagholam::is_kicked(string uname)
{
	fstream file;
	file.open("./Data/Users_list");
	string temp;
	while(getline(file ,temp))
	{
		if (temp == uname)
			return false;
	}	
	return true;
	
}