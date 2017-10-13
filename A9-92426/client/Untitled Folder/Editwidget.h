#ifndef EDIT_H_
#define EDIT_H_


#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "Post.h"
#include "User.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpacerItem>
#include <QFileDialog>
#include <QMessageBox>
#include <Exeption.h>

using namespace std;

class editwidget :public QWidget
{
	Q_OBJECT
public:
	editwidget(User *_user,QWidget *parent = 0);

	public slots:
	void save_clicked();
	void discard_clicked();
	void browse_clicked();
	signals:
	void go_home();
private:
	User *user;
	QLabel *image;
	QWidget *horizontalLayoutWidget;
	QHBoxLayout *horizontalLayout;
	QPushButton *discard;
	QPushButton *save;
	QLabel *label;
	QWidget *verticalLayoutWidget;
	QVBoxLayout *verticalLayout;
	QLineEdit *pass;
	QLineEdit *newpass;
	QLineEdit *confirmpass;
	QPushButton *browse;
	string img_path;
	QFileDialog *filepicker;
};


#endif
