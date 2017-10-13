#include "Admin.h"

Admin::Admin()
{
	username = "";
	password = "";
	report_index = 0;

}


void Admin::load_data()
{
	fstream file ;
	string address = USER_PATH + username ;
	string temp;
	string fname;
	Post tempost;
	char c;

	frequests.clear();
	friend_name.clear();
	up_posts.clear();
	fav_posts.clear();
	
	file.open(address.c_str());
	getline(file , temp); //get pass
	password = temp ; 

	getline(file , temp); // get junk

	getline(file , temp); // userprofile pic
	prof_pic = temp ;

	getline(file , temp); // get junk
	// ta alan ta --- friends name khonde shode
	getline(file , temp);
	if (temp[0]!= '-')
	{
		for (int i=0 ; i < temp.size(); i++)
		{
			c = temp[i];
			if ( c != ' ')
				fname += c;
			if(c == ' ' || i == temp.size()-1)
			{
				friend_name.push_back(fname);
				fname.clear();
			}
		}	
	}
	if (temp != "---- uploaded post")
		getline(file , temp); // get junk
	// ta alan uploaded post daryaft shode
	getline(file , temp); // to get hash
	while( temp !="---- liked post")
	{
		getline(file , temp);
		tempost.set_title(temp);
		getline(file , temp);
		tempost.set_author(temp);
		getline(file , temp);
		tempost.set_img_path(temp);
		getline(file , temp);
		tempost.set_date(temp);
		getline(file , temp);
		if (temp[0] != '-')
			tempost.set_liked(temp);
		tempost.set_likes_line(temp);
		getline(file , temp);
		tempost.set_text(temp);
		getline(file , temp);
		up_posts.push_back(tempost);
	}
	//ta liked post daryaft shod
	getline(file , temp); // to get hash
	while( temp !="---- indexes")
	{
		getline(file , temp);
		tempost.set_title(temp);
		getline(file , temp);
		tempost.set_author(temp);
		getline(file , temp);
		tempost.set_img_path(temp);
		getline(file , temp);
		tempost.set_date(temp);
		getline(file , temp);
		if (temp[0] != '-')
			tempost.set_liked(temp);
		tempost.set_likes_line(temp);
		getline(file , temp);
		tempost.set_text(temp);
		getline(file , temp);
		fav_posts.push_back(tempost);
	}
	// ta alan indexes daryaft shod
	getline(file , temp); 
	news_index = atoi(temp.c_str());
	getline(file , temp); 
	report_index = atoi(temp.c_str());
	getline(file , temp); 
	file.close();
	load_reports();
	load_friends();
}

void Admin::save_data()
{
	fstream file ;
	string address = USER_PATH + username  ;
	file.open(address.c_str(),fstream::out);
	file << password <<endl;
	file << "---- profile picture"<<endl;
	file << prof_pic << endl;
	file << "---- friends name"<<endl;
	for(int i=0 ; i< friend_name.size();i++)
	{
		file << friend_name[i];
		if (i != friend_name.size()-1)
			file << ' ';
		else
			file << endl;
	}
	file << "---- uploaded post"<<endl;
	for (int j=0 ; j< up_posts.size(); j++)
	{
		file << up_posts[j] ;//<<endl;
	}
	file << "---- liked post" <<endl;
	for (int k=0 ; k<fav_posts.size(); k++)
	{
		file << fav_posts[k] ;//<<endl;
	}
	file << "---- indexes" <<endl;
	file << news_index <<endl;
	file << report_index << endl;
	file << "----";
	file.close();
}

void Admin::delete_user(string name)
{
	fstream file ;
	file.open("./Data/Users_list");
	string temp;
	vector<string>new_user_list;
	while(getline(file,temp))
	{
		if (temp != name)
		{
			new_user_list.push_back(temp);
		}

	}
	file.close();

	file.open("./Data/Users_list",fstream::trunc | fstream::out);
	for(int i=0 ;i<new_user_list.size(); i++)
		file << new_user_list[i] <<endl;

	file.close();
}

void Admin::load_reports()
{
	fstream file;
	string temp;
	reports.clear();
	file.open("./Data/Reports");
	for (int i=0 ; i< report_index ;i++)
		getline(file,temp);
	while(getline(file,temp))
	{
		reports.push_back(temp);
		report_index++;
	}
	save_data();
}

void Admin::load_friends()
{
	fstream file ;
	string temp;
	file.open("./Data/Users_list");
	friend_name.clear();
	while (getline(file,temp))
	{
		friend_name.push_back(temp);
	}
	file.close();
	save_data();
}