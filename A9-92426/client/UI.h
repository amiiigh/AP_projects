#ifndef UI_H_
#define UI_H_

#include <QtGui>
#include <iostream>
// #include "postwidget.h"
#include <iterator>
// #include "NewPostwidget.h"
// #include "Nonfriendwidget.h"
// #include "Reqwidget.h"
// #include "Reportwidget.h"
// #include "Editwidget.h"
#include "Exeption.h"
#include "Client.h"

using namespace std;

class UI :public QWidget
{
	Q_OBJECT
public:
	UI(QWidget *parent = 0);
	// ~UI();
	// void show_up_post(User *user);
	// void show_news();
	// void show_fav(User *user);
	// void set_combo_users();
	// void show_friend_up_post(string friend_name);
	// void show_requests();
	// void show_reports_and_news_admin();
	// void load_profpic(User *user);
	public slots:
	void signin_clicked();
	void signup_clicked();
	void logout_clicked();
	// void profile_clicked();
	// void fav_clicked();
	// void home_clicked();
	// void newp_clicked();
	// void seeprof_clicked();
	// void delbutt_clicked();
	// void edit_clicked();

private:
	QLabel *background;
	QLabel *login_back;
	QLabel *home_back;
	QLabel *profpic;
	QLabel *user_label;

	QWidget *login_widget;
	QWidget *find_user_widget;
	QWidget *techArea;
	QWidget *profArea;
	QWidget *favArea;

	QVBoxLayout *verticalLayout;
	
	QHBoxLayout *buttonLayout;
	QVBoxLayout *verLayout_3;
	QLineEdit *line_user;
	QLineEdit *line_pass;
	

	QPushButton *signin;
	QPushButton *signup;
	QPushButton *home;
	QPushButton *delbutt;
	QPushButton *logout;
	QPushButton *profile;
	QPushButton *favorites;
	QPushButton *edit;
	QPushButton *newp;
	QPushButton *seeprof;

	QScrollArea *scrollpost;	
	
	newpost *np ;
	// editwidget *ewg;
	// nonfriend *fview;
	// reqwidget *reqw;
	
	QComboBox *comboulist;

	Client user;
	
};
#endif


