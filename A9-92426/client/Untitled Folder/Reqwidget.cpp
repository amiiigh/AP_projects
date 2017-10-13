#include "Reqwidget.h"

reqwidget::reqwidget(User *_current_user,QWidget *parent)
:QWidget(parent) , current_user(_current_user)
{
	this->setFixedSize(450,81);
	req_container = new QLabel(this);
	req_container->setGeometry(QRect(0, 10, 447, 65));
	req_container->setPixmap(QPixmap(QString::fromUtf8("./Graphic/request_container.png")));

	horizontalLayoutWidget = new QWidget(this);
	horizontalLayoutWidget->setGeometry(QRect(260, 27, 178, 41));
	horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	Reject = new QPushButton("Reject",horizontalLayoutWidget);
	connect(Reject,SIGNAL(clicked()),this,SLOT(Reject_clicked()));
	connect(Reject,SIGNAL(clicked()),this,SLOT(close()));
	horizontalLayout->addWidget(Reject);

	Accept = new QPushButton("Accept",horizontalLayoutWidget);
	connect(Accept,SIGNAL(clicked()),this,SLOT(Accept_clicked()));
	connect(Accept,SIGNAL(clicked()),this,SLOT(close()));
	horizontalLayout->addWidget(Accept);

	information = new QLabel(this);
	information->setGeometry(QRect(10, 35, 151, 17));
	information->setText("Friend request from");
	requester = new QLabel(this);
	requester->setGeometry(QRect(160, 35, 66, 17));

}

void reqwidget::Reject_clicked()
{
	current_user->delete_req(requester->text().toStdString());
}

void reqwidget::Accept_clicked()
{
	current_user->add_to_friend(requester->text().toStdString());
	User *ftemp = new User;
	ftemp->set_user(requester->text().toStdString());
	ftemp->load_data();
	ftemp->add_to_friend(current_user->get_username());
	ftemp->save_data();
	current_user->delete_req(requester->text().toStdString());
	delete ftemp;
	current_user->save_data();
	// cout << "request of "<< requester->text().toStdString() << "Accepted!"<<endl;
}