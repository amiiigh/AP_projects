#include "Reportwidget.h"

repwidget::repwidget(Admin *_admin,QWidget *parent )
:QWidget(parent) , admin(_admin)
{
	this->setFixedSize(450,81);
	rep_con = new QLabel(this);
	rep_con->setGeometry(QRect(0, 10, 447, 65));
	rep_con->setPixmap(QPixmap("./Graphic/request_container.png"));
	horizontalLayoutWidget = new QWidget(this);
	horizontalLayoutWidget->setGeometry(QRect(260, 30, 178, 41));

	horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	ignore = new QPushButton("Ignore",horizontalLayoutWidget);
	connect(ignore,SIGNAL(clicked()),this,SLOT(ignore_clicked()));
	connect(ignore,SIGNAL(clicked()),this,SLOT(close()));

	horizontalLayout->addWidget(ignore);

	kick = new QPushButton("kick",horizontalLayoutWidget);

	connect(kick,SIGNAL(clicked()),this,SLOT(kick_clicked()));
	connect(kick,SIGNAL(clicked()),this,SLOT(close()));

	horizontalLayout->addWidget(kick);

	information = new QLabel(this);
	information->setGeometry(QRect(90, 35, 151, 17));
	information->setText("is reported by users");

	reported = new QLabel(this);
	reported->setGeometry(QRect(10, 35, 66, 17));

}

void repwidget::kick_clicked()
{
	admin->delete_user(reported->text().toStdString());
	admin->load_data();
}

void repwidget::ignore_clicked()
{
	// cout << "ignored!"<<endl;
	admin->load_data();
}