#ifndef REQWIDGET_H_
#define REQWIDGET_H_

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "User.h"
#include <QHBoxLayout>

using namespace std;

class reqwidget :public QWidget
{
	Q_OBJECT
public:
	reqwidget(User *_current_user,QWidget *parent = 0);
	QLabel *requester;
	public slots:
	void Accept_clicked();
	void Reject_clicked();

	

	
private:
	QLabel *req_container;
	QWidget *horizontalLayoutWidget;
	QHBoxLayout *horizontalLayout;
	QPushButton *Reject;
	QPushButton *Accept;
	QLabel *information;
	User *current_user;
};


#endif