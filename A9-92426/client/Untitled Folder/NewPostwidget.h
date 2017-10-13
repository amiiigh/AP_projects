#ifndef NEWPOST_H_
#define NEWPOST_H_


#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "Post.h"
#include "User.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpacerItem>
#include <QFileDialog>
#include <QMessageBox>
#include "Exeption.h"

using namespace std;

class newpost :public QWidget
{
	Q_OBJECT
public:
	newpost(User *_current_user,QWidget *parent = 0);

	// ~pwidget();
	public slots:
	void create_clicked();
	void discard_clicked();
	void browse_clicked();

	signals:
	void disclick();
private:
	Post data;
	User *current_user;
	QLabel *postback;
	QHBoxLayout *horizontalLayout;
	QSpacerItem *horizontalSpacer;
	QWidget *horizontalLayoutWidget;
	QPushButton *create;
	QPushButton *browse;
	QLineEdit *title_line;
	QLabel *image;
	QLineEdit *text_con;
	QPushButton *discard;
	QFileDialog *filepicker;
	string img_path;
};


#endif