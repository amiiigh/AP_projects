#ifndef NONFRIEND_H_
#define NONFRIEND_H_

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "User.h"
#include <QHBoxLayout>

using namespace std;

class nonfriend :public QWidget
{
	Q_OBJECT
public:
	nonfriend(string fname,User *_current_user,QWidget *parent = 0);

	public slots:
	void req_clicked();
	void rep_clicked();
	signals:
private:
	QWidget *horizontalLayoutWidget;
	QHBoxLayout *horizontalLayout_3;
	QPushButton *report_butt;
	QPushButton *req_butt;
	QLabel *userpic;
	QLabel *userid;
	User *ufriend;
	User *current_user;
};


#endif