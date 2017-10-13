#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QString>
#include <QSpinBox>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <iostream>
#include "Bookeater.h"
#include "Library.h"
#include <fstream>
#include <QTextBrowser>
#include <QTextEdit>
#include <QComboBox>

class mywidget :public QWidget
{
	Q_OBJECT
public:
	mywidget(QWidget *parent = 0);
	~mywidget();
	void init_book_database();
	bool Book_available_in_main(string book_name);
public slots:
	void regclicked();
	void loginclicked();
	void logoutclicked();
	void followclicked();
	void backclicked();
	void likeclicked();
	void showallclicked();
	void showupdateclicked();
	void showfavclicked();
	void addbookclicked();
	void showbookclicked();
	void addshelfclicked();
	void showbooksclicked();
	void updataclicked();
	void add_toclicked();
private:
	QTextBrowser *textbrowser;
	QTextBrowser *status;
	QLabel *backsecond;
	QLabel *backthird;
	QLabel *backlabel;
	QLabel *userlabel;
	QLineEdit *user;
	QPushButton *login;
	QLineEdit *pass;
	QPushButton *signup;

	QPushButton *showall;
	QPushButton *logout;
	QPushButton *updatedata;
	QPushButton *showupdate;
	QPushButton *showfav;

	QPushButton *addbook;
	QPushButton *showbook;
	QPushButton *addshelf;
	QPushButton *like;
	QPushButton *showbooks;
	QPushButton *follow;
	QPushButton *back;
	QPushButton *add_to;

	QLineEdit *input;

	QComboBox *combok;
	QComboBox *cocat;



	bool available;
	Library Mlib;
	Bookeater current_user;

	// std::string command;
	// std::string username;
	// std::string password;
};