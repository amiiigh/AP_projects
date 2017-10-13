#include "Input.h"

Input::Input()
{
	available = false;
	init_book_database();
}

void Input::init_book_database()
{
	vector<Category> cat;
	fstream file;
	file.open("./Data/Books/Books");
	string temp;
	vector<Book> book_list;
	while (getline(file , temp))
	{
		book_list.push_back(Book(temp));
	}
	file.close();
	cat.push_back(Category("uncat"));
	cat[0].set_books(book_list);
	Mlib.set_category(cat);
}


bool Input::Book_available_in_main(string book_name)
{
	vector<Book> books;
	books = Mlib.get_books();
	for (int i =0 ; i< books.size(); i++) //search for book
	{	
		if (book_name == books[i].get_name())
			return true;
	}	
	return false;
}


void Input::prossess_command(string command)
{
	if ( command == "register")
	{
		string password;
		string user_name;
		vector<Category> cat;
		cat.push_back(Category("uncat"));
		cin >> user_name >> password ;
		if (user_available(user_name))
			cout<< "This username is already taken !"<<endl;
		else
		{
			current_user.set_library(cat);
			current_user.set_user(user_name);
			current_user.set_pass(password);
			current_user.save_data();
			available = true ;
		}
	}

	else if ( command == "login")
	{
		string pass,user;
		cin >> user >> pass ; 

		if (user_available(user))
		{	
			current_user.load_data(user);
			if (current_user.get_pass() == pass)
			{
				cout << "Welcome dear "<< user << endl;
				if (user == "admin")
					cout << " admin loged in !"<<endl;
				available = true;
			}
			else 
				cout << "Wrong password !" << endl;
		}
		else 
			cout << "There is no user with " << user << "user_name registered !" <<endl;

	}
	if (available && !current_user.get_admin())
	{

		if ( command == "add_book") //should update the log file 
		{
			string book_name;
			vector<Book> books;
			vector<Book> ubooks;
			vector<Category> cat;
			fstream log_file;
			log_file.open("./Data/Log",ios::out | ios::in |ios::app );

			getline (cin, book_name);
			book_name = book_name.substr(1,book_name.size());
			if (Book_available_in_main(book_name))
			{
				if (!current_user.have_this(book_name))
				{
					cout << "user doesn't have this book "<<endl;
					ubooks = current_user.get_lib().get_books(); //get uncat books
					books = Mlib.get_books();
					for (int i =0 ; i< books.size(); i++) //search for book
					{	
						if (book_name == books[i].get_name())
						{
							ubooks.push_back(books[i]);
							break;
						}
					}	
					cat = current_user.get_lib().get_cat();
					cat[0].set_books(ubooks);
					current_user.set_library(cat);

					cout << book_name << " is added successfuly to " << current_user.get_user() << " library"<<endl;

					log_file << current_user.get_user() << " add " << book_name << " to his/her library."<<endl;
					//cout << endl << current_user.get_lib() << endl;
				}
				else 
					cout << current_user.get_user() << " already has this book!"<<endl;

			}
			else
				cout << "There is no such book with this name !"<<endl;
			current_user.save_data();
			log_file.close();
		}

		else if ( command == "show_book")
		{
			string book_name;
			getline (cin, book_name);
			book_name = book_name.substr(1,book_name.size());
			vector<Book>books;

			books = Mlib.get_books();
			for (int i =0 ; i< books.size(); i++) //search for book
			{	
				if (book_name == books[i].get_name())
				{
					books[i].print_for_show();;
					break;
				}
			}	
			if (current_user.have_this(book_name))
			{
				cout << " "<<current_user.get_user() << " has this book in his/her library!"<<endl;
			}

		}

		else if ( command == "add_shelf") //should update the log file
		{	
			string shelf_name;
			cin >> shelf_name;
			vector<Category> cat;
			fstream log_file;
			log_file.open("./Data/Log",ios::out | ios::in |ios::app );

			if (!current_user.have_this_shelf(shelf_name))
			{
				cat = current_user.get_lib().get_cat();
				cat.push_back(Category(shelf_name));
				current_user.set_library(cat);
				cout << "New shelf is added successfully to " << current_user.get_user() << " library!"<<endl;
				log_file <<current_user.get_user() <<  " add " << shelf_name << " shelf to his/her library."<<endl;
			}
			else 
				cout << "the library already has this shelf!"<<endl;
			current_user.save_data();
			log_file.close();
		}

		else if ( command == "add_to_shelf")
		{
			bool flag =false;
			string shelf_name;
			string book_name;
			cin >> shelf_name;
			vector<Category> cat;
			vector<Book> books;
			fstream log_file;
			log_file.open("./Data/Log",ios::out | ios::in |ios::app );

			getline (cin, book_name);
			book_name = book_name.substr(1,book_name.size());

			int i;
			if(current_user.have_this(book_name))
			{
				if (current_user.have_this_shelf(shelf_name))
				{
					cat = current_user.get_lib().get_cat();
					for (i=0 ; i<cat.size();i++)
					{
						if (cat[i].get_name() == shelf_name)
						{
							// cout << "category found "<<endl;
							// cout << cat[i].get_name()<<endl;

							books = cat[i].get_books();
							break;
						}
					}
					//cout << "book name is : "<<book_name <<endl;
					for (int j=0 ; j< cat.size(); j++)
					{
						for (int k=0 ; k< cat[j].get_books().size() ;k++)
						{
							//cout << cat[j].get_books()[k];
							if ( book_name == cat[j].get_books()[k].get_name())
							{
								// cout << "book found "<<endl;
								// cout << cat[j].get_books()[k];
								for(int z =0; z <books.size(); z++)
								{
									if(books[z].get_name() == book_name)
									{
										cout << "already in shelf"<<endl;
										log_file.close();
										return;
									}
								}
								books.push_back(cat[j].get_books()[k]);
								flag =true;
								break;
							}
							
						}
						if (flag == true)
						{
							flag = false;
							break;
						}
					}
					cat[i].set_books(books);
					current_user.set_library(cat);
					current_user.save_data();
					cout << book_name << " successfully added to "<<shelf_name <<endl;
					log_file << current_user.get_user() << " add " << book_name << " to "<< shelf_name << " shelf."<<endl;
				}
				else
					cout << "There is no shelf with this name !"<<endl;
			}
			else 
				cout << "There is no book with this name !"<<endl;
			log_file.close();
		}

		else if ( command == "like") // should update the log file
		{
			string book_name;
			vector<Book> fav_book;
			vector<Category> cat;
			fstream log_file;
			log_file.open("./Data/Log",ios::out | ios::in |ios::app );

			getline (cin, book_name);
			book_name = book_name.substr(1,book_name.size());
			bool found = false;
			if (current_user.have_this(book_name))
			{
				cat = current_user.get_lib().get_cat();
				fav_book = current_user.get_fav();
				for (int j=0 ; j< cat.size(); j++)
				{
					for (int k=0 ; k< cat[j].get_books().size() ;k++)
					{
							//cout << cat[j].get_books()[k];
						if ( book_name == cat[j].get_books()[k].get_name())
						{
							for(int z=0 ; z<fav_book.size(); z++)
							{
								if(fav_book[z].get_name() == book_name)
								{
									cout << "already liked!"<<endl;
									log_file.close();
									return;
								}
							}
							fav_book.push_back(cat[j].get_books()[k]);
							found = true; 
							break;
						}

					}
					if (found == true)
					{
						found = false;
						break;
					}
				}
				current_user.set_fav_books(fav_book);
				current_user.save_data();
				cout << current_user.get_user() <<" liked "<< book_name << endl;
				log_file<<current_user.get_user() << " liked "<< book_name << '.'<<endl;
			}
			else 
				cout << "There is no such book with this name in "<<current_user.get_user()<< " library!"<<endl;
			log_file.close();
		}

		else if ( command == "show_books")
		{
			string shelf_name;
			cin >> shelf_name;
			vector<Category>cat;
			vector<Book>books;
			if (current_user.have_this_shelf(shelf_name))
			{
				cout << "# Books in "<< shelf_name << " : "<<endl<<endl;
				cat = current_user.get_lib().get_cat();
				for (int i=0 ; i<cat.size();i++)
				{
					if (cat[i].get_name() == shelf_name)
					{
						books = cat[i].get_books();
						break;
					}
				}	
				if (books.size()==0)
					cout << "This shelf is empty"<<endl;
				for (int j=0 ; j< books.size();j++)
				{
					books[j].print_for_show();
					if(j != books.size()-1)
						cout << "----"<<endl;
				}
			}
		}

		else if ( command == "show_all_books")
		{
			vector<Category>cat;
			cat = current_user.get_lib().get_cat();
			for (int i=0 ; i < cat.size();i++)
			{
				cout <<endl<< "# Books in "<< cat[i].get_name() << " : "<<endl<<endl;
				for (int j=0 ; j< cat[i].get_books().size(); j++)
				{
					cat[i].get_books()[j].print_for_show();
					if(j != cat[i].get_books().size()-1)
						cout << "----"<<endl;
				}
			}
		}

		else if ( command == "show_favorites")
		{
			for (int i=0 ; i< current_user.get_fav().size(); i++)
			{
				current_user.get_fav()[i].print_for_show();
				if(i != current_user.get_fav().size()-1)
					cout << "----"<<endl;
			}
		}

		else if ( command == "follow") //should update logfile
		{
			string username;
			cin >> username;
			vector<string>names;
			fstream log_file;
			log_file.open("./Data/Log",ios::out | ios::in |ios::app );

			if(user_available(username))
			{
				names = current_user.get_friends();
				for(int z=0 ; z<names.size(); z++)
				{
					if(names[z] == user_name)
					{
						cout << "already followed!"<<endl;
						log_file.close();
						return;
					}
				}
				names.push_back(username);
				current_user.set_friends_name(names);
				current_user.save_data();
				cout << current_user.get_user() <<" is now following "<<username <<endl;
				log_file <<current_user.get_user() <<" is now following "<<username <<endl;
			}
			else
				cout << "There is no user with this username!"<<endl;
			log_file.close();
		}

		else if ( command == "show_updates")
		{
			fstream log_file;
			string temp;
			log_file.open("./Data/Log");
			string friend_name;
			int count ;
			cout << "showing updates..."<<endl;
			count = current_user.get_index();
			for (int i=0; i< current_user.get_index(); i++)
			{
				getline (log_file,temp);
			}
			while (getline (log_file ,temp))
			{
				friend_name = log_of_user(temp);
				if(current_user.friend_with(friend_name))
				{
					cout << temp << endl ;
				}
				count++;
			}
			current_user.set_index(count);
			log_file.close();
			current_user.save_data();

		}

		else if ( command == "logout")
		{
			cout << "Logout ...!"<<endl;
			available = false;
		}

		else if (command == "update_database")
			cout << "only admin user can use this command!"<<endl;

	} // if available
	else if (available && current_user.get_admin())
	{
		if ( command == "update_database") //check if admin or not
		{
			string line;
			cout << "Updating database ....!"<<endl;
			fstream rfile ; //database.txt
			fstream ofile ; //./Data/Books/Books
			ofile.open("./Data/Books/Books",ios::out | ios::in |ios::app );
			rfile.open("database.txt");
			while (getline(rfile,line))
			{
				ofile << line << endl;
			}
			rfile.close();
			ofile.close();
		}
		else if ( command == "logout")
		{
			cout << "Logout ...!"<<endl;
			available = false;
		}
		else 
			cout << "admin can only update the database!"<<endl;
	}
}
