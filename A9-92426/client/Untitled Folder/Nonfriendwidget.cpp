#include "Nonfriendwidget.h"

nonfriend::nonfriend(string fname,User *_current_user,QWidget *parent)
:QWidget(parent) , current_user(_current_user)
{
	ufriend = new User;
	ufriend->set_user(fname);
	ufriend->load_data();

	userid = new QLabel(this);
	userid->setText(QString::fromStdString(ufriend->get_username()));
	userid->setGeometry(100,170,100,30);

	this->setFixedSize(222,240);
	horizontalLayoutWidget = new QWidget(this);
	horizontalLayoutWidget->setGeometry(QRect(0, 210, 221, 29));

	horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

	report_butt = new QPushButton("report",horizontalLayoutWidget);
	connect(report_butt,SIGNAL(clicked()),this,SLOT(rep_clicked()));
	horizontalLayout_3->addWidget(report_butt);

	req_butt = new QPushButton("send request",horizontalLayoutWidget);
	connect(req_butt,SIGNAL(clicked()),this,SLOT(req_clicked()));

	horizontalLayout_3->addWidget(req_butt);

	userpic = new QLabel(this);
	userpic->setGeometry(QRect(30, 10, 160, 152));
	userpic->setFrameShape(QFrame::StyledPanel);
	userpic->setPixmap(QPixmap(QString::fromStdString(ufriend->get_profpic())));
}

void nonfriend::req_clicked()
{
	current_user->send_request(ufriend->get_username());
	req_butt->setEnabled(false);
	// cout << "request sent from "<< current_user->get_username()<< " to " << ufriend->get_username()<<endl;
}

void nonfriend::rep_clicked()
{
	current_user->report(ufriend->get_username());
	report_butt->setEnabled(false);
	// cout << "reported to admin!"<< endl;
}