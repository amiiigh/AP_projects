#ifndef UI_H_
#define UI_H_

#include <QtGui>
#include <iostream>
#include "Instagholam.h"
#include "postwidget.h"
#include <iterator>
#include "NewPostwidget.h"
#include "Nonfriendwidget.h"
#include "Reqwidget.h"
#include "Reportwidget.h"
#include "Editwidget.h"
#include "Exeption.h"

using namespace std;

class UI :public QWidget
{
	Q_OBJECT
public:
	UI(QWidget *parent = 0);
	~UI();
	void show_up_post(User *user);
	void show_news();
	void show_fav(User *user);
	void set_combo_users();
	void show_friend_up_post(string friend_name);
	void show_requests();
	void show_reports_and_news_admin();
	void load_profpic(User *user);
	public slots:
	void signin_clicked();
	void signup_clicked();
	void logout_clicked();
	void profile_clicked();
	void fav_clicked();
	void home_clicked();
	void newp_clicked();
	void seeprof_clicked();
	void delbutt_clicked();
	void edit_clicked();

private:
	QLabel *background;
	QLabel *login_back;
	QLabel *home_back;
	QLabel *user_label;
	QWidget *login_widget;
	QVBoxLayout *verticalLayout;
	QLineEdit *line_user;
	QLineEdit *line_pass;
	QHBoxLayout *buttonLayout;
	QPushButton *signin;
	QPushButton *signup;
	QPushButton *home;
	QPushButton *delbutt;
	Instagholam insta;
	QScrollArea *scrollpost;	
	QPushButton *logout;
	QWidget *techArea;
	QWidget *profArea;
	QWidget *favArea;
	QPushButton *profile;
	QPushButton *favorites;
	QPushButton *edit;
	QLabel *profpic;
	QPushButton *newp;
	newpost *np ;
	editwidget *ewg;
	nonfriend *fview;
	reqwidget *reqw;
	QWidget *find_user_widget;
	QVBoxLayout *verLayout_3;
	QComboBox *comboulist;
	QPushButton *seeprof;
	
};
#endif


