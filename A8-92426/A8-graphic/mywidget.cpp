#include "mywidget.h"
#include <iostream>
#include "Functions.h"
#include "Category.h"
#include "Book.h"
#include <vector>
#include <cstdlib>

using namespace std;
mywidget::mywidget(QWidget *parent)
:QWidget(parent)
{

	init_book_database();
	string a;
	setFixedSize(700,700);

	QPixmap *background = new QPixmap("./Data/Images/main.jpg");
	QPixmap *secondpage =new QPixmap("./Data/Images/open_book.jpg");
	QPixmap *thirdpage = new QPixmap("./Data/Images/open_book2.jpg");

	backsecond = new QLabel("",this);
	backsecond->hide();
	backsecond->setPixmap(*secondpage);

	backthird = new QLabel("",this);
	backthird->hide();
	backthird->setPixmap(*thirdpage);

	backlabel = new QLabel("",this);
	backlabel->setPixmap(*background);
	login = new QPushButton("login",this);
	//QPushButton *
	login->setGeometry(275,600,75,30);
	connect(login,SIGNAL(clicked()),this,SLOT(loginclicked()));

	signup = new QPushButton("signup",this);
	signup->setGeometry(350,600,75,30);
	connect(signup,SIGNAL(clicked()),this,SLOT(regclicked()));

	userlabel = new QLabel("",this);
	userlabel->hide();

	user = new QLineEdit(this);
	user->setGeometry(275,475,150,30);
	pass = new QLineEdit(this);
	pass->setGeometry(275,545,150,30);
	pass->setEchoMode(QLineEdit::Password);
	setWindowTitle("BookEater");
	available =false;

	input = new	QLineEdit(this);
	input->setGeometry(195,440,125,30);
	input->hide();
	showall = new QPushButton("Show all",this);
	connect(showall,SIGNAL(clicked()),this,SLOT(showallclicked()));
	showall->hide();
	showall->setFlat(true);
	showall->setGeometry(70,350,125,30);

	logout= new QPushButton("Logout",this);
	connect(logout,SIGNAL(clicked()),this,SLOT(logoutclicked()));
	logout->hide();
	logout->setGeometry(300,600,125,30);
	logout->setFlat(true);

	updatedata= new QPushButton("Update data base",this);
	connect(updatedata,SIGNAL(clicked()),this,SLOT(updataclicked()));
	updatedata->hide();
	updatedata->setGeometry(70,230,125,30);
	updatedata->setFlat(true);
	showupdate= new QPushButton("Show updates",this);
	connect(showupdate,SIGNAL(clicked()),this,SLOT(showupdateclicked()));
	showupdate->hide();
	showupdate->setGeometry(320,350,125,30);
	showupdate->setFlat(true);
	showfav= new QPushButton("Show favorite",this);
	connect(showfav,SIGNAL(clicked()),this,SLOT(showfavclicked()));
	showfav->hide();
	showfav->setGeometry(195,350,125,30);
	showfav->setFlat(true);

	addbook= new QPushButton("Add book",this);
	connect(addbook,SIGNAL(clicked()),this,SLOT(addbookclicked()));
	addbook->hide();
	addbook->setGeometry(320,410,125,30);
	addbook->setFlat(true);

	showbook= new QPushButton("Show book",this);
	connect(showbook,SIGNAL(clicked()),this,SLOT(showbookclicked()));
	showbook->hide();
	showbook->setGeometry(320,380,125,30);
	showbook->setFlat(true);

	addshelf= new QPushButton("Add shelf",this);
	connect(addshelf,SIGNAL(clicked()),this,SLOT(addshelfclicked()));
	addshelf->hide();
	addshelf->setGeometry(195,410,125,30);
	addshelf->setFlat(true);

	like= new QPushButton("Like",this);
	connect(like,SIGNAL(clicked()),this,SLOT(likeclicked()));
	like->hide();
	like->setGeometry(195,380,125,30);
	like->setFlat(true);

	showbooks= new QPushButton("Show books",this);
	connect(showbooks,SIGNAL(clicked()),this,SLOT(showbooksclicked()));
	showbooks->hide();
	showbooks->setGeometry(70,410,125,30);
	showbooks->setFlat(true);

	follow= new QPushButton("Follow",this);
	connect(follow,SIGNAL(clicked()),this,SLOT(followclicked()));
	follow->hide();
	follow->setGeometry(70,380,125,30);
	follow->setFlat(true);

	back= new QPushButton("Back",this);
	connect(back,SIGNAL(clicked()),this,SLOT(backclicked()));
	back->hide();
	back->setGeometry(180,610,50,30);
	back->setFlat(true);

	textbrowser = new QTextBrowser(this);
	textbrowser->setGeometry(200,180,330,360);
	textbrowser->hide();
	textbrowser->viewport()->setAutoFillBackground(false);

	status = new QTextBrowser(this);
	status->setGeometry(0,670,375,30);
	status->viewport()->setAutoFillBackground(false);

	add_to = new QPushButton("Add_to",this);
	connect(add_to,SIGNAL(clicked()),this,SLOT(add_toclicked()));
	add_to->hide();
	add_to->setGeometry(195,480,125,30);
	add_to->setFlat(true);


	combok = new QComboBox(this);
	combok->hide();
	cocat = new QComboBox(this);
	cocat->hide();
}

mywidget::~mywidget()
{
	delete textbrowser;
	delete status;
	delete backsecond;
	delete backthird;
	delete backlabel;
	delete userlabel;
	delete 	user;
	delete login;
	delete pass;
	delete signup;

	delete showall;
	delete logout;
	delete updatedata;
	delete showupdate;
	delete showfav;

	delete addbook;
	delete showbook;
	delete addshelf;
	delete like;
	delete showbooks;
	delete follow;
	delete back;
	delete add_to;

	delete input;

	delete combok;
	delete cocat;
}

void mywidget::add_toclicked()
{
	bool flag =false;
	string shelf_name = cocat->currentText().toStdString();
	string book_name = combok->currentText().toStdString();
	//cin >> shelf_name;
	vector<Category> cat;
	vector<Book> books;
	fstream log_file;
	log_file.open("./Data/Log",ios::out | ios::in |ios::app );

	// getline (cin, book_name);
	// book_name = book_name.substr(1,book_name.size());

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
							// //cout << "category found "<<endl;
							// //cout << cat[i].get_name()<<endl;
					books = cat[i].get_books();
					break;
				}
			}
					////cout << "book name is : "<<book_name <<endl;
			for (int j=0 ; j< cat.size(); j++)
			{
				for (int k=0 ; k< cat[j].get_books().size() ;k++)
				{
							////cout << cat[j].get_books()[k];
					if ( book_name == cat[j].get_books()[k].get_name())
					{
								// //cout << "book found "<<endl;
								// //cout << cat[j].get_books()[k];
						for(int z =0; z <books.size(); z++)
						{
							if(books[z].get_name() == book_name)
							{
								status->setText(QString::fromStdString("already in shelf"));
								////cout << "already in shelf"<<endl;
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
			status->setText(QString::fromStdString(" successfully added to " + shelf_name ));
			////cout << book_name << " successfully added to "<<shelf_name <<endl;
			log_file << current_user.get_user() << " add " << book_name << " to "<< shelf_name << " shelf."<<endl;

			for (int n=0 ; n<current_user.get_lib().get_books().size() ; n++)
			{
				combok->addItem(QString::fromStdString(current_user.get_lib().get_books()[n].get_name()));
			}

			for (int m=0 ; m<current_user.get_lib().get_cat().size() ; m++)
			{
				cocat->addItem(QString::fromStdString(current_user.get_lib().get_cat()[m].get_name()));
			}
		}
		else
		{
			status->setText(QString::fromStdString("There is no shelf with this name !"));
			////cout << "There is no shelf with this name !"<<endl;
		}
	}
	else 
	{
		status->setText(QString::fromStdString("There is no book with this name !"));
		////cout << "There is no book with this name !"<<endl;
	}
	log_file.close();
}

void mywidget::updataclicked()
{
	string line;
	status->setText(QString::fromStdString("Updating database ....!"));
	////cout << "Updating database ....!"<<endl;
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

void mywidget::showbooksclicked()
{
	status->hide();
	textbrowser->show();
	backsecond->hide();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	backthird->show();
	back->show();
	cocat->hide();
	combok->hide();
	add_to->hide();

	string shelf_name =input->text().toStdString();
	vector<Category>cat;
	vector<Book>books;
	string temp;
	if (current_user.have_this_shelf(shelf_name))
	{
		temp = "# Books in " + shelf_name + " : \n";
		textbrowser->append(QString::fromStdString(temp));

		//cout << "# Books in "<< shelf_name << " : "<<endl<<endl;
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
		{
			textbrowser->append(QString::fromStdString("This shelf is empty"));
			//cout << "This shelf is empty"<<endl;
		}
		for (int j=0 ; j< books.size();j++)
		{
			// books[j].print_for_show();
			textbrowser->append(QString::fromStdString(books[j].get_all()));
			if(j != books.size()-1)
			{
				textbrowser->append(QString::fromStdString("----"));
				//cout << "----"<<endl;
			}
		}
	}

	input->setText("");
}

void mywidget::addshelfclicked()
{
	string shelf_name = input->text().toStdString();
	vector<Category> cat;
	fstream log_file;
	log_file.open("./Data/Log",ios::out | ios::in |ios::app );

	if (!current_user.have_this_shelf(shelf_name))
	{
		cat = current_user.get_lib().get_cat();
		cat.push_back(Category(shelf_name));
		current_user.set_library(cat);
		status->setText(QString::fromStdString("New shelf is added successfully to " + current_user.get_user()+" library!"));
		//cout << "New shelf is added successfully to " << current_user.get_user() << " library!"<<endl;
		log_file <<current_user.get_user() <<  " add " << shelf_name << " shelf to his/her library."<<endl;

		cocat->clear();
		for (int j=0 ; j<current_user.get_lib().get_cat().size() ; j++)
		{
			cocat->addItem(QString::fromStdString(current_user.get_lib().get_cat()[j].get_name()));
		}

	}
	else 
	{
		status->setText(QString::fromStdString("the library already has this shelf!"));
		//cout << "the library already has this shelf!"<<endl;
	}
	current_user.save_data();
	log_file.close();
	input->setText("");
}

void mywidget::showbookclicked()
{
	status->hide();
	textbrowser->show();
	backsecond->hide();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	backthird->show();
	back->show();
	cocat->hide();
	combok->hide();
	add_to->hide();

	QString bk;
	QString tm;
	string qtm;
	string book_name =input->text().toStdString();
	vector<Book>books;
	books = Mlib.get_books();
	for (int i =0 ; i< books.size(); i++) //search for book
	{	
		if (book_name == books[i].get_name())
		{
			bk = QString::fromStdString(books[i].get_all());
			textbrowser->append(bk);
			//books[i].print_for_show();
			break;
		}
	}	
	if (current_user.have_this(book_name))
	{
		qtm = " " + current_user.get_user() + " has this book in his/her library!\n";
		tm = QString::fromStdString(qtm);
		textbrowser->append(tm);
		//cout << " "<<current_user.get_user() << " has this book in his/her library!"<<endl;
	}
	input->setText("");
}

void mywidget::addbookclicked()
{
	string book_name =	input->text().toStdString();
	vector<Book> books;
	vector<Book> ubooks;
	vector<Category> cat;
	fstream log_file;
	log_file.open("./Data/Log",ios::out | ios::in |ios::app );
	if (Book_available_in_main(book_name))
	{
		if (!current_user.have_this(book_name))
		{
			//cout << "user doesn't have this book "<<endl;
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
			status->setText(QString::fromStdString(" is added successfuly to " + current_user.get_user() + " library"));
			//cout << book_name << " is added successfuly to " << current_user.get_user() << " library"<<endl;
			log_file << current_user.get_user() << " add " << book_name << " to his/her library."<<endl;

			combok->clear();
			for (int j=0 ; j<current_user.get_lib().get_books().size() ; j++)
			{
				combok->addItem(QString::fromStdString(current_user.get_lib().get_books()[j].get_name()));
			}
					////cout << endl << current_user.get_lib() << endl;
		}
		else 
		{
			//cout << current_user.get_user() << " already has this book!"<<endl;
			status->setText(QString::fromStdString(" already has this book!"));
		}
	}
	else
	{
		status->setText(QString::fromStdString("There is no such book with this name !"));
		//cout << "There is no such book with this name !"<<endl;
	}
	current_user.save_data();
	log_file.close();
	input->setText("");
}

void mywidget::showfavclicked()
{
	status->hide();
	textbrowser->show();
	backsecond->hide();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	backthird->show();
	back->show();
	cocat->hide();
	combok->hide();
	add_to->hide();

	QString bk;
	for (int i=0 ; i< current_user.get_fav().size(); i++)
	{
		//current_user.get_fav()[i].print_for_show();
		bk = QString::fromStdString(current_user.get_fav()[i].get_all());
		textbrowser->append(bk);

		if(i != current_user.get_fav().size()-1)
		{
			textbrowser->append(QString::fromStdString("----"));
			//cout << "----"<<endl;
		}
	}
}

void mywidget::showupdateclicked()
{
	status->hide();
	textbrowser->show();
	backsecond->hide();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	backthird->show();
	back->show();
	cocat->hide();
	combok->hide();
	add_to->hide();

	fstream log_file;
	string temp;
	log_file.open("./Data/Log");
	string friend_name;
	int count ;
	QString tx("showing updates...");
	// tx = "showing updates...";
	textbrowser->append(tx);
	//cout << "showing updates..."<<endl;
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
			//cout << temp << endl ;
			tx = QString::fromStdString(temp) ;
			textbrowser->append(tx);

		}
		count++;
	}
	current_user.set_index(count);
	log_file.close();
	current_user.save_data();
}

void mywidget::likeclicked()
{

	string book_name;
	vector<Book> fav_book;
	vector<Category> cat;
	fstream log_file;
	log_file.open("./Data/Log",ios::out | ios::in |ios::app );

	//getline (cin, book_name);
	book_name = input->text().toStdString();//book_name.substr(1,book_name.size());
	bool found = false;
	if (current_user.have_this(book_name))
	{
		cat = current_user.get_lib().get_cat();
		fav_book = current_user.get_fav();
		for (int j=0 ; j< cat.size(); j++)
		{
			for (int k=0 ; k< cat[j].get_books().size() ;k++)
			{
							////cout << cat[j].get_books()[k];
				if ( book_name == cat[j].get_books()[k].get_name())
				{
					for(int z=0 ; z<fav_book.size(); z++)
					{
						if(fav_book[z].get_name() == book_name)
						{
							//cout << "already liked!"<<endl;
							status->setText(QString::fromStdString("already liked!"));	
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
		status->setText(QString::fromStdString( current_user.get_user() + " liked " + book_name ));	
		//cout << current_user.get_user() <<" liked "<< book_name << endl;
		log_file<<current_user.get_user() << " liked "<< book_name << '.'<<endl;
	}
	else 
	{
		status->setText(QString::fromStdString("There is no such book with this name in " + current_user.get_user() + " library!"));	
		//cout << "There is no such book with this name in "<<current_user.get_user()<< " library!"<<endl;
	}
	log_file.close();
	input->setText("");
}

void mywidget::showallclicked()
{
	status->hide();
	textbrowser->show();
	backsecond->hide();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	backthird->show();
	back->show();
	cocat->hide();
	combok->hide();
	add_to->hide();

	vector<Category>cat;
	cat = current_user.get_lib().get_cat();
	QString ct("");
	QString bk("");
	string temp;
	for (int i=0 ; i < cat.size();i++)
	{
		temp = "\n# Books in " + cat[i].get_name() + " : \n";
		//cout <<endl<< "# Books in "<< cat[i].get_name() << " : "<<endl<<endl;
		ct = QString::fromStdString(temp);
		textbrowser->append(ct);
		for (int j=0 ; j< cat[i].get_books().size(); j++)
		{
			bk = QString::fromStdString(cat[i].get_books()[j].get_all());
			textbrowser->append(bk);
		//	cat[i].get_books()[j].print_for_show();
			if(j != cat[i].get_books().size()-1)
			{
				//cout << "----"<<endl;
				textbrowser->append(QString::fromStdString("----"));
			}
		}
	}
}

void mywidget::backclicked()
{
	status->show();
	textbrowser->hide();
	backthird->hide();
	backsecond->show();
	userlabel->show();
	showall->show();
	showfav->show();
	logout->show();
	showupdate->show();
	input->show();
	addbook->show();
	showbooks->show();
	showbook->show();
	addshelf->show();
	like->show();
	follow->show();
	back->hide();
	textbrowser->setText("");
	cocat->show();
	combok->show();
	add_to->show();
	status->setText("");
}

void mywidget::loginclicked()
{
	string username = user->text().toStdString();
	string password = pass->text().toStdString();

	textbrowser->setText("");
	if (user_available(username))
	{	
		current_user.load_data(username);
		if (current_user.get_pass() == password)
		{
			//combok = new QComboBox(this);
			if (username !="admin")
			{
				for (int i=0 ; i<current_user.get_lib().get_books().size() ; i++)
				{
					combok->addItem(QString::fromStdString(current_user.get_lib().get_books()[i].get_name()));
				}
				combok->setGeometry(95,480,100,30);
				combok->show();
			//cocat = new QComboBox(this);
				for (int j=0 ; j<current_user.get_lib().get_cat().size() ; j++)
				{
					cocat->addItem(QString::fromStdString(current_user.get_lib().get_cat()[j].get_name()));
				}
				cocat->setGeometry(320,480,100,30);
				cocat->show();
			}
			status->show();
			userlabel->show();
			userlabel->setText(user->text());
			userlabel->setGeometry(150,160,100,100);
			userlabel->show();
			//cout << "Welcome dear "<< username << endl;
			status->setText(QString::fromStdString("Welcome dear " + username ));	
			backlabel->hide();
			backsecond->show();
			user->hide();
			pass->hide();
			login->hide();
			signup->hide();
			logout->show();

			if (username == "admin")
			{
				//cout << " admin loged in !"<<endl;
				status->setText(QString::fromStdString(" admin loged in !" ));	
				updatedata->show();
			}
			else
			{
				showall->show();
				showfav->show();
				showupdate->show();
				input->show();
				addbook->show();
				showbooks->show();
				showbook->show();
				addshelf->show();
				like->show();
				follow->show();
				add_to->show();

			}

			available = true;
		}
		else 
		{
			//cout << "Wrong password !" << endl;
			status->setText(QString::fromStdString("Wrong password !" ));	
		}

	}
	else 
	{
		status->setText(QString::fromStdString("There is no user with " + username + "user_name registered !" ));	
		//cout << "There is no user with " << username << "user_name registered !" <<endl;
	}
}

void mywidget::regclicked()
{
	string username = user->text().toStdString();
	string password = pass->text().toStdString();
	if (user->text().toStdString() == "" || pass->text().toStdString() == "")
	{
		status->setText(QString::fromStdString("username or password field is empty!"));	
		return;
	}
	vector<Category> cat;
	cat.push_back(Category("uncat"));
	if (user_available(username))
	{
		status->setText(QString::fromStdString("This username is already taken !"));	
		//cout<< "This username is already taken !"<<endl;
	}
	else
	{
		current_user.set_library(cat);
		for (int i=0 ; i<current_user.get_lib().get_books().size() ; i++)
		{
			combok->addItem(QString::fromStdString(current_user.get_lib().get_books()[i].get_name()));
		}
		combok->setGeometry(95,480,100,30);
		combok->show();
		
		for (int j=0 ; j<current_user.get_lib().get_cat().size() ; j++)
		{
			cocat->addItem(QString::fromStdString(current_user.get_lib().get_cat()[j].get_name()));
		}
		cocat->setGeometry(320,480,100,30);
		cocat->show();
		status->setText(QString::fromStdString("Welcome dear " + username ));	
		status->show();
		showall->show();
		showfav->show();
		logout->show();
		showupdate->show();
		input->show();
		addbook->show();
		showbooks->show();
		showbook->show();
		addshelf->show();
		like->show();
		follow->show();
		add_to->show();

		userlabel->show();
		userlabel->setText(user->text());
		userlabel->setGeometry(150,160,100,100);
		userlabel->show();

		backlabel->hide();
		backsecond->show();
		user->hide();
		pass->hide();
		login->hide();
		signup->hide();
		
		current_user.set_user(username);
		current_user.set_pass(password);
		current_user.save_data();
		available = true ;
	}
}

void mywidget::logoutclicked()
{
	available =false;
	pass->setText("");
	user->setText("");
	backlabel->show();
	backsecond->hide();
	user->show();
	pass->show();
	login->show();
	signup->show();
	userlabel->hide();
	showall->hide();
	showfav->hide();
	logout->hide();
	showupdate->hide();
	input->hide();
	addbook->hide();
	showbooks->hide();
	showbook->hide();
	addshelf->hide();
	like->hide();
	follow->hide();
	updatedata->hide();
	cocat->hide();
	combok->hide();
	add_to->hide();
	status->setText("");
	current_user.clear();
	combok->clear();
	cocat->clear();
	textbrowser->setText("");
}

void mywidget::followclicked()
{
	string user_name = input->text().toStdString();
	vector<string>names;
	if (user_name == current_user.get_user())
	{
		return;
	}
	
	fstream log_file;
	log_file.open("./Data/Log",ios::out | ios::in |ios::app );
	input->setText("");
	if(user_available(user_name))
	{
		names = current_user.get_friends();
		for(int z=0 ; z<names.size(); z++)
		{
			if(names[z] == user_name)
			{
				//cout << "already followed!"<<endl;
				status->setText(QString::fromStdString("already followed!"));
				log_file.close();
				return;
			}
		}
		names.push_back(user_name);
		current_user.set_friends_name(names);
		current_user.save_data();
		//cout << current_user.get_user() <<" is now following "<<user_name <<endl;
		status->setText(QString::fromStdString(current_user.get_user() + " is now following " + user_name ));
		log_file <<current_user.get_user() <<" is now following "<<user_name <<endl;
	}
	else
	{
		//cout << "There is no user with this username!"<<endl;
		status->setText(QString::fromStdString("There is no user with this username!"));
	}
	log_file.close();
}

void mywidget::init_book_database()
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

bool mywidget::Book_available_in_main(string book_name)
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
