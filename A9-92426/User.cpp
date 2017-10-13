#include "User.h"

User::User()
{
	username = "";
	password = "";
	news_index =0 ;
	request_index =0 ;
	prof_pic = "./Data/Users/Userpic/no_pic.gif";
}

User::User(string _username, string _password)
{
	username = _username;
	password = _password;
}

void User::set_pass(string pass)
{
	password = pass ;
}

string User::generate_name(string old_path)
{
	int a,j;
	char c;
	string ext;
	string new_path;

	new_path += username ; 
	for (j = old_path.size() ; j> 0; j--)
	{
		if (old_path[j] == '.')
			break;
	}
	j = old_path.size() - j +1;
	ext = old_path.substr(old_path.size()-j ,j);
	for (int i =0 ; i< 8 ; i++)
	{
		a = rand() %10;
		c = a + 48;	
		new_path += c;
	}
	new_path += ext;
	return new_path;
}


void User::set_log()
{
	login = true;
}

string User::upload(string file_path)
{
	string temp;
	fstream src;
	fstream des;
	string address;
	address = IMG_PATH + generate_name(file_path);
	//int progress=0;

	src.open(file_path.c_str());
	des.open(address.c_str(),fstream::out);
	if (src.is_open())
	{
		while (getline (src,temp))
		{
			des << temp <<endl;
		}
		return address;
	}
	src.close();
	des.close();
	return "";
}

void User::load_data()
{
	// cout << "loading data by "<<username << endl;
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
	if (!file.is_open())
	{
		throw Ex("Unable to load files");
		return;
	}
	getline(file , temp); //get pass
	password = temp ; 

	getline(file , temp); // get junk

	getline(file , temp); // userprofile pic
	prof_pic = temp ;

	getline(file , temp); // get junk

	getline(file , temp); // requests
	if (temp[0]!= '-')
	{
		for (int j=0 ; j < temp.size(); j++)
		{
			c = temp[j];
			if ( c != ' ')
				fname += c;
			if(c == ' ' || j == temp.size()-1)
			{
				frequests.push_back(fname);
				fname.clear();
			}
		}	
	}
	if(temp !="---- friends name")
		getline(file,temp);
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
	request_index = atoi(temp.c_str());
	getline(file , temp); 
	file.close();
}

void User::save_data()
{
	// cout << "saving data by "<< username<<endl;
	fstream file ;
	string address = USER_PATH + username  ;
	file.open(address.c_str(),fstream::out);
	file << password <<endl;
	file << "---- profile picture"<<endl;
	file << prof_pic << endl;
	file << "---- requests"<<endl;
	for (int z=0 ; z< frequests.size();z++)
	{
		file << frequests[z];
		if (z != frequests.size()-1)
			file << ' ';
		else
			file << endl;
	}
	file << "---- friends name"<<endl;
	for(int i=0 ; i< friend_name.size();i++)
	{
		file << friend_name[i];
		if (i != friend_name.size()-1)
			file << ' ';
		else
			file << endl;
	}
	// if (friend_name.size()==0)
	// 	file << endl;
	file << "---- uploaded post"<<endl;
	for (int j=0 ; j< up_posts.size(); j++)
	{
		file << up_posts[j] ;//<<endl;
	}
	// if(up_posts.size()==0)
	// 	file<<endl;
	file << "---- liked post" <<endl;
	for (int k=0 ; k<fav_posts.size(); k++)
	{
		file << fav_posts[k] ;//<<endl;
	}
	// if(fav_posts.size()==0)
	// 	file<<endl;
	file << "---- indexes" <<endl;
	file << news_index <<endl;
	file << request_index << endl;
	file << "----";
	file.close();
}

void User::load_news()
{
	news.clear();
	fstream file ;
	string temp;
	Post tempost;
	file.open("./Data/News");
	for (int i=0 ; i< news_index ; i++) // get old data
		getline(file , temp);
	
	while(getline(file,temp))
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
		getline(file , temp);
		tempost.set_text(temp);
		if (friend_with(tempost.get_author()))
			news.push_back(tempost);
		news_index += 7;
	}
	file.close();
}

void User::set_user(string uname)
{
	username = uname;
}

void User::create_post(string title,string img_path,string text )
{
	fstream file ;
	file.open("./Data/News",ios::out | ios::in | ios::app);
	Post temp ;
	temp.set_author(username);
	temp.set_date_now();
	temp.set_img_path(img_path);
	temp.set_title(title);
	temp.set_liked("");
	temp.set_text(text);
	up_posts.push_back(temp);
	file << temp ;
	file.close();

}

void User::set_fav(vector<Post> newfav)
{
	fav_posts.clear();
	fav_posts = newfav;
}

void User::set_up(vector<Post> newups)
{
	up_posts = newups;
}

void User::delete_from_news(Post liked_post)
{
	for(int i=0 ; i< news.size();i++)
	{
		if (news[i] == liked_post)
		{
			news.erase(news.begin() + i);
		}
	}
}

bool User::friend_with(string fname)
{
	for (int i=0 ; i< friend_name.size(); i++)
	{
		if (fname == friend_name[i])
			return true;
	}
	return false;
}

void User::send_request(string fname)
{
	fstream file;
	file.open("./Data/Requests",ios::out | ios::in | ios::app);
	file << fname << endl << username << endl << "----"<<endl;
	file.close();
}

void User::report(string user)
{
	fstream file;
	file.open("./Data/Reports",ios::out | ios::in | ios::app);
	file << user << endl;
	file.close();
}

void User::load_requests()
{
	fstream file;
	string temp;
	file.open("./Data/Requests");
	for (int i=0 ; i<request_index; i++)
		getline(file,temp);
	temp.clear();
	while(getline(file,temp))
	{
		if (temp == username)
		{
			getline(file,temp);
			frequests.push_back(temp);
			getline(file,temp);
		}
		else
		{
			getline(file,temp);
			getline(file,temp);
		}
		request_index +=3;
	}
	file.close();
}

void User::delete_req(string fname)
{
	for (int i=0 ; i<frequests.size();i++)
	{
		if (frequests[i] == fname)
		{
			frequests.erase(frequests.begin() + i);
			break;
		}
	}
	save_data();
}

void User::add_to_friend(string fname)
{
	for (int i=0 ; i<friend_name.size();i++)
	{
		if (friend_name[i] == fname)
			return;
	}
	friend_name.push_back(fname);
}

void User::print_up()//for debug
{
	cout <<"--showing up post---"<<endl;
	for (int i=0 ; i< up_posts.size(); i++)
	{
		cout << up_posts[i] <<endl;
	}
	cout << "-------------------"<<endl;
}