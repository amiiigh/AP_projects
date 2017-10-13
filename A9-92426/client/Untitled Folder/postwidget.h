#ifndef POSTWIDG_H_
#define POSTWIDG_H_

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "Post.h"
#include "User.h"

using namespace std;

class pwidget :public QWidget
{
	Q_OBJECT
public:
	pwidget(User *_current_user,QWidget *parent = 0);
	// ~pwidget();
	Post data;
	User *current_user;
	QLabel *postback;
	QLabel *title_label;
	QLabel *author_label;
	QLabel *date_label;
	QLabel *post_img;
	QPushButton *like_butt;
	QLabel *label_5;
	QLabel *label_6;
	QLabel *text_con;
	QLabel *likes;
	QLabel *label_7;
	public slots:
	void like_clicked();

};

#endif
