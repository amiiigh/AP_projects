#ifndef REPWIDGET_H_
#define REPWIDGET_H_

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "User.h"
#include "Admin.h"
#include <QHBoxLayout>

using namespace std;

class repwidget :public QWidget
{
	Q_OBJECT
public:
	repwidget(Admin *_admin,QWidget *parent = 0);
	QLabel *reported;
	public slots:
	void kick_clicked();
	void ignore_clicked();
	// void Accept_clicked();
	// void Reject_clicked();

	

	
private:
	QLabel *rep_con;
	QWidget *horizontalLayoutWidget;
	QHBoxLayout *horizontalLayout;
	QPushButton *ignore;
	QPushButton *kick;
	QLabel *information;
	Admin *admin;
};


#endif