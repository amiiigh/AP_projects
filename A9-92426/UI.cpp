#include "UI.h"

UI::UI(QWidget *parent)
:QWidget(parent)
{
	this->setFixedSize(1000,700);

	background = new QLabel(this);
	background->setGeometry(QRect(0, 0, 1000, 700));
	background->setPixmap(QPixmap("./Graphic/home_screen.jpg"));

	login_back = new QLabel(this);
	login_back->setGeometry(QRect(40, 390, 241, 201));
	login_back->setPixmap(QPixmap("./Graphic/login_container.jpg"));

	home_back = new QLabel(this);
	home_back->setGeometry(QRect(0, 0, 1000, 700));
	home_back->setPixmap(QPixmap("./Graphic/main_temp.jpg"));
	home_back->hide();

	login_widget = new QWidget(this);
	login_widget->setGeometry(QRect(70, 420, 180, 97));


	verticalLayout = new QVBoxLayout(login_widget);

	line_user = new QLineEdit(this);
	verticalLayout->addWidget(line_user);

	line_pass = new QLineEdit(login_widget);
	verticalLayout->addWidget(line_pass);

	buttonLayout = new QHBoxLayout();
	signin = new QPushButton(login_widget);
	connect(signin,SIGNAL(clicked()),this,SLOT(signin_clicked()));
	buttonLayout->addWidget(signin);

	signup = new QPushButton(login_widget);
	connect(signup,SIGNAL(clicked()),this,SLOT(signup_clicked()));
	buttonLayout->addWidget(signup);
	verticalLayout->addLayout(buttonLayout);

	logout = new QPushButton(this);
	logout->setGeometry(QRect(780,600, 181,31));
	logout->setText("logout");
	logout->hide();
	connect(logout,SIGNAL(clicked()),this,SLOT(logout_clicked()));

	profile = new QPushButton(this);
	profile->setGeometry(QRect(780,500, 181,31));
	profile->setText("profile");
	profile->hide();
	connect(profile,SIGNAL(clicked()),this,SLOT(profile_clicked()));


	home = new QPushButton(this);
	home->setGeometry(QRect(780,440, 181,31));
	home->setText("home");
	home->hide();
	connect(home,SIGNAL(clicked()),this,SLOT(home_clicked()));
	delbutt = new QPushButton("delete",this);
	delbutt->setGeometry(QRect(780,300, 181,31));
	delbutt->hide();
	connect(delbutt,SIGNAL(clicked()),this,SLOT(delbutt_clicked()));
	
	connect(delbutt,SIGNAL(clicked()),home,SIGNAL(clicked()));


	favorites = new QPushButton(this);
	favorites->setGeometry(QRect(780,470, 181,31));
	favorites->setText("favorites");
	favorites->hide();
	connect(favorites,SIGNAL(clicked()),this,SLOT(fav_clicked()));

	edit = new QPushButton("edit",this);
	edit->setGeometry(QRect(780,310, 181,31));
	edit->hide();
	connect(edit,SIGNAL(clicked()),this,SLOT(edit_clicked()));

	profpic = new QLabel(this);
	profpic->setGeometry(QRect(790, 40, 160, 152));
	profpic->hide();
	profpic->setFrameShape(QFrame::WinPanel);
	profpic->setFrameShadow(QFrame::Plain);

	user_label = new QLabel(this);
	user_label->setGeometry(790,200,160,30);
	user_label->hide();
	user_label->setAlignment(Qt::AlignCenter);

	line_user->setPlaceholderText("username");
	line_pass->setPlaceholderText("password");
	line_pass->setEchoMode(QLineEdit::Password);

	signin->setText("sign in");
	signup->setText("sign up");

	scrollpost = new QScrollArea(this);
	scrollpost->setBackgroundRole(QPalette::Base);
	scrollpost->setFrameShadow(QFrame::Plain);
	scrollpost->setFrameShape(QFrame::NoFrame);
	scrollpost->setWidgetResizable(true);
	scrollpost->setGeometry(200,0,485,641);
	scrollpost->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
	scrollpost->hide();

	newp = new QPushButton(this);
	newp->setGeometry(QRect(780,410, 181,31));
	newp->setText("New Post...");
	newp->hide();
	connect(newp,SIGNAL(clicked()),this,SLOT(newp_clicked()));

	np =NULL;
	fview = NULL;
	reqw =NULL;
	ewg = NULL;
	
	find_user_widget = new QWidget(this);
	find_user_widget->setGeometry(QRect(771,335, 191,80));
	verLayout_3 = new QVBoxLayout(find_user_widget);
	comboulist = new QComboBox(find_user_widget);
	comboulist->setFixedSize(181,31);
	connect(logout,SIGNAL(clicked()),comboulist,SLOT(clear()));
	verLayout_3->addWidget(comboulist);
	seeprof = new QPushButton("see profile...",find_user_widget);
	seeprof->setFixedSize(181,31);
	connect(seeprof,SIGNAL(clicked()),this,SLOT(seeprof_clicked()));
	verLayout_3->addWidget(seeprof);
	find_user_widget->hide();
}


void UI::set_combo_users()
{
	for (int i =0 ; i< insta.users_list.size(); i++)
	{
		comboulist->addItem(QString::fromStdString(insta.users_list[i]));
	}
}

void UI::seeprof_clicked()
{
	if (ewg!=NULL)
		ewg->hide();
	User *user;
	if (insta.admin_log)
		user = insta.admin;
	else 
		user = insta.current_user;

	if (fview != NULL)
		fview->hide();

	if (comboulist->currentText().toStdString() == user->get_username())
		return;	

	if (user->friend_with(comboulist->currentText().toStdString()))
	{	

		if (np != NULL)
			np->hide();
		scrollpost->show();
		profArea = new QWidget(); // remember to delete
		profArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
		profArea->setLayout(new QVBoxLayout(profArea));
		scrollpost->setWidget(profArea);
		show_friend_up_post(comboulist->currentText().toStdString());
	}
	else
	{
		scrollpost->hide();
		fview = new nonfriend(comboulist->currentText().toStdString(),user,this);
		fview->setGeometry(350,150,222,240);
		fview->show();
		// do if he is not a friend
	}
	newp->setEnabled(true);
}

void UI::signin_clicked()
{	
	user_label->show();
	try
	{
		if (line_user->text().toStdString() == "" || line_pass->text().toStdString() == "")
			throw Ex("fill the empty fields");
		insta.login(line_user->text().toStdString(),line_pass->text().toStdString());	
	}
	catch(Ex ex)
	{
		QMessageBox::critical(this,"error occured!",QString::fromStdString(ex.get_message()));
		line_pass->clear();
		return;
	}
	if (insta.admin_log)
	{
		load_profpic(insta.admin);
		user_label->setText(QString::fromStdString(insta.admin->get_username()));
	}
	else
	{
		load_profpic(insta.current_user);
		user_label->setText(QString::fromStdString(insta.current_user->get_username()));
	}
	background->hide();
	login_widget->hide();
	login_back->hide();
	home_back->show();
	scrollpost->show();
	logout->show();
	profile->show();
	profpic->show();
	favorites->show();
	home->show();
	newp->show();
	find_user_widget->show();

	techArea = new QWidget();
	techArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	techArea->setLayout(new QVBoxLayout(techArea));
	scrollpost->setWidget(techArea);
	if (line_user->text().toStdString() != "ghodrat")
	{
		show_requests();
		show_news();
	}
	else
	{
		delbutt->show();
		show_reports_and_news_admin();
	}
	insta.load_users_list(); 
	set_combo_users();
	line_user->clear();
	line_pass->clear();
}

void UI::signup_clicked()
{
	user_label->show();
	try
	{
		if (line_user->text().toStdString() == "" || line_pass->text().toStdString() == "")
			throw Ex("fill the empty fields");
		insta.register_user(line_user->text().toStdString(),line_pass->text().toStdString());
	}
	catch(Ex ex)
	{
		QMessageBox::critical(this,"error occured!",QString::fromStdString(ex.get_message()));
		return;
	}
	user_label->setText(QString::fromStdString(insta.current_user->get_username()));
	profpic->setPixmap(QPixmap(QString::fromStdString(insta.current_user->get_profpic())));
	background->hide();
	login_widget->hide();
	login_back->hide();
	home_back->show();
	scrollpost->show();
	logout->show();
	profile->show();
	profpic->show();
	favorites->show();
	home->show();
	newp->show();
	find_user_widget->show();
	techArea = new QWidget();
	techArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	techArea->setLayout(new QVBoxLayout(techArea));
	scrollpost->setWidget(techArea);
	insta.load_users_list();
	set_combo_users();
	line_user->clear();
	line_pass->clear();
}

void UI::logout_clicked()
{
	if (ewg!=NULL)
		ewg->hide();
	insta.logout();
	background->show();
	login_widget->show();
	login_back->show();
	home_back->hide();
	scrollpost->hide();
	logout->hide();
	profile->hide();
	profpic->hide();
	favorites->hide();
	home->hide();
	newp->hide();
	if(np !=NULL)
		np->hide();
	find_user_widget->hide();
	if (fview !=NULL)
		fview->hide();
	delbutt->hide();
	if(insta.current_user != NULL)
		insta.current_user = NULL;
	edit->hide();
	user_label->hide();
}

void UI::fav_clicked()
{
	if (ewg!=NULL)
		ewg->hide();
	if (fview != NULL)
		fview->hide();
	if (np != NULL)
		np->hide();
	scrollpost->show();
	favArea = new QWidget(); // remember to delete
	favArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	favArea->setLayout(new QVBoxLayout(favArea));
	scrollpost->setWidget(favArea);
	if(insta.admin_log)
		show_fav(insta.admin);
	else
		show_fav(insta.current_user);
	edit->hide();
	newp->setEnabled(true);
}

void UI::show_friend_up_post(string friend_name)
{
	vector<Post> up;
	User *myfriend = new User;
	myfriend->set_user(friend_name);
	myfriend->load_data();
	up = myfriend->get_up_post();
	for(int i=up.size()-1 ; i >= 0;i--)
	{
		pwidget* pwg = new pwidget(myfriend,profArea); // function these bullshit
		pwg->title_label->setText(QString::fromStdString(up[i].get_title()));
		pwg->author_label->setText(QString::fromStdString(up[i].get_author()));
		pwg->date_label->setText(QString::fromStdString(up[i].get_date()));
		pwg->post_img->setPixmap(QString::fromStdString(up[i].get_img()));
		pwg->text_con->setText(QString::fromStdString(up[i].get_text()));
		pwg->like_butt->hide();
		pwg->data = up[i];
		pwg->likes->setText(QString::fromStdString(up[i].get_likes_line()));
		if(profArea->layout())
		{
			profArea->layout()->addWidget(pwg);
		}   
	}
}

void UI::show_up_post(User *user)
{
	vector<Post> up;
	up = user->get_up_post();
	for(int i=up.size()-1 ; i >= 0;i--)
	{
		pwidget* pwg = new pwidget(user,profArea); // function these bullshit
		pwg->title_label->setText(QString::fromStdString(up[i].get_title()));
		pwg->author_label->setText(QString::fromStdString(up[i].get_author()));
		pwg->date_label->setText(QString::fromStdString(up[i].get_date()));
		pwg->post_img->setPixmap(QString::fromStdString(up[i].get_img()));
		pwg->text_con->setText(QString::fromStdString(up[i].get_text()));
		pwg->like_butt->hide();
		pwg->data = up[i];
		pwg->likes->setText(QString::fromStdString(up[i].get_likes_line()));
		if(profArea->layout())
		{
			profArea->layout()->addWidget(pwg);
		}   
	}

}


void UI::show_fav(User *user)
{
	scrollpost->show();
	vector<Post> fav;
	fav = user->get_fav();
	for(int i=fav.size()-1 ; i >= 0;i--)
	{
		pwidget* pwg = new pwidget(user,favArea);
		pwg->title_label->setText(QString::fromStdString(fav[i].get_title()));
		pwg->author_label->setText(QString::fromStdString(fav[i].get_author()));
		pwg->date_label->setText(QString::fromStdString(fav[i].get_date()));
		pwg->post_img->setPixmap(QString::fromStdString(fav[i].get_img()));
		pwg->text_con->setText(QString::fromStdString(fav[i].get_text()));
		pwg->like_butt->setEnabled(false);
		pwg->data = fav[i];
		pwg->likes->setText(QString::fromStdString(fav[i].get_likes_line()));
		if(favArea->layout())
		{
			favArea->layout()->addWidget(pwg);
		}   
	}	
}

void UI::show_requests()
{
	vector<string> reqs;
	reqs = insta.current_user->get_reqs();
	for (int i = 0 ; i < reqs.size(); i++)
	{
		reqwidget *rqw =new reqwidget(insta.current_user,techArea);
		rqw->requester->setText(QString::fromStdString(reqs[i]));
		if(techArea->layout())
		{
			techArea->layout()->addWidget(rqw);
		}
	}
}

void UI::show_news()
{
	scrollpost->show();
	vector<Post> newfeed;
	newfeed = insta.current_user->get_news();
	for(int i=newfeed.size()-1; i>= 0;i--)
	{
		pwidget* pwg = new pwidget(insta.current_user,techArea);
		pwg->title_label->setText(QString::fromStdString(newfeed[i].get_title()));
		pwg->author_label->setText(QString::fromStdString(newfeed[i].get_author()));
		pwg->date_label->setText(QString::fromStdString(newfeed[i].get_date()));
		pwg->post_img->setPixmap(QString::fromStdString(newfeed[i].get_img()));
		pwg->text_con->setText(QString::fromStdString(newfeed[i].get_text()));
		pwg->data = newfeed[i];
		pwg->likes->setText(QString::fromStdString(newfeed[i].get_likes_line()));
		if(techArea->layout())
		{
			techArea->layout()->addWidget(pwg);
		}   
	}	
}

void UI::profile_clicked()
{
	if (fview != NULL)
		fview->hide();
	if (np != NULL)
		np->hide();
	if (ewg!=NULL)
		ewg->hide();
	scrollpost->show();
	profArea = new QWidget(); // remember to delete
	profArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	profArea->setLayout(new QVBoxLayout(profArea));
	scrollpost->setWidget(profArea);
	if (insta.admin_log)
		show_up_post(insta.admin);
	else
		show_up_post(insta.current_user);
	edit->show();
	newp->setEnabled(true);
}

void UI::home_clicked()
{
	if (ewg!=NULL)
		ewg->hide();
	if (fview != NULL)
		fview->hide();
	if (np != NULL)
		np->hide();
	if (comboulist->count() == 0)
		set_combo_users();
	if (insta.admin_log)
		load_profpic(insta.admin);
	else
		load_profpic(insta.current_user);
	scrollpost->show();
	techArea = new QWidget();
	techArea->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	techArea->setLayout(new QVBoxLayout(techArea));
	scrollpost->setWidget(techArea);
	if(insta.admin_log)
		show_reports_and_news_admin();
	else
	{
		show_requests();
		show_news();	
	}
	edit->hide();
	edit->setEnabled(true);
	newp->setEnabled(true);
}

void UI::newp_clicked()
{
	if (fview != NULL)
		fview->hide();
	scrollpost->hide();
	if (insta.admin_log)
		np = new newpost(insta.admin,this);
	else
		np = new newpost(insta.current_user,this);
	np->setGeometry(210,30,448,487);
	np->show();
	connect(np,SIGNAL(disclick()),this,SLOT(home_clicked()));
	edit->hide();
	newp->setEnabled(false);
	if (ewg!=NULL)
		ewg->hide();
}

void UI::show_reports_and_news_admin()
{
	scrollpost->show();
	vector<Post> newfeed;
	newfeed = insta.admin->get_news();
	vector<string> reports;
	reports = insta.admin->get_reports();
	for (int j=0 ; j< reports.size() ; j++)
	{
		repwidget* rep = new repwidget(insta.admin,techArea);
		rep->reported->setText(QString::fromStdString(reports[j]));
		if(techArea->layout())
			techArea->layout()->addWidget(rep);
	}
	for(int i=newfeed.size()-1; i>= 0;i--)
	{
		pwidget* pwg = new pwidget(insta.admin,techArea);
		pwg->title_label->setText(QString::fromStdString(newfeed[i].get_title()));
		pwg->author_label->setText(QString::fromStdString(newfeed[i].get_author()));
		pwg->date_label->setText(QString::fromStdString(newfeed[i].get_date()));
		pwg->post_img->setPixmap(QString::fromStdString(newfeed[i].get_img()));
		pwg->text_con->setText(QString::fromStdString(newfeed[i].get_text()));
		pwg->data = newfeed[i];
		pwg->likes->setText(QString::fromStdString(newfeed[i].get_likes_line()));
		if(techArea->layout())
		{
			techArea->layout()->addWidget(pwg);
		}   
	}	
}

void UI::delbutt_clicked()
{
	insta.admin->delete_user(comboulist->currentText().toStdString());
}

void UI::edit_clicked()
{
	scrollpost->hide();
	if (insta.admin_log)
		ewg = new editwidget(insta.admin,this);
	else
		ewg = new editwidget(insta.current_user,this);
	ewg->setGeometry(210,30,448,487);
	ewg->show();
	connect(ewg,SIGNAL(go_home()),this,SLOT(home_clicked()));
	edit->setEnabled(false);
	newp->setEnabled(true);
	if (fview != NULL)
		fview->hide();

}

void UI::load_profpic(User *user)
{
	profpic->setPixmap(QPixmap(QString::fromStdString(user->get_profpic())));
}
UI::~UI()
{
	delete background;
	delete login_back;
	delete home_back;
	delete signin;
	delete signup;
	delete line_user;
	delete line_pass;
	delete scrollpost;	
	delete logout;
	delete buttonLayout;
	delete verticalLayout;
	delete login_widget;
}

