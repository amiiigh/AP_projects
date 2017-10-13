#include "Editwidget.h"

editwidget::editwidget(User *_user,QWidget *parent )
:QWidget(parent) , user(_user)
{
	this->setFixedSize(447, 339);


	label = new QLabel(this);
	label->setGeometry(QRect(0, 0, 447, 339));
	label->setPixmap(QPixmap("./Graphic/post_container.png"));

	image = new QLabel(this);
	image->setGeometry(QRect(20, 20, 160, 152));
	image->setFrameShape(QFrame::StyledPanel);
	image->setPixmap(QString::fromStdString(user->get_profpic()));

	horizontalLayoutWidget = new QWidget(this);
	horizontalLayoutWidget->setGeometry(QRect(20, 260, 401, 70));

	horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

	discard = new QPushButton("discard",horizontalLayoutWidget);
	connect(discard,SIGNAL(clicked()),this,SLOT(discard_clicked()));
	connect(discard,SIGNAL(clicked()),this,SIGNAL(go_home()));
	horizontalLayout->addWidget(discard);

	save = new QPushButton("save",horizontalLayoutWidget);
	connect(save,SIGNAL(clicked()),this,SLOT(save_clicked()));
	connect(save,SIGNAL(clicked()),this,SIGNAL(go_home()));
	horizontalLayout->addWidget(save);


	verticalLayoutWidget = new QWidget(this);
	verticalLayoutWidget->setGeometry(QRect(220, 50, 160, 95));

	verticalLayout = new QVBoxLayout(verticalLayoutWidget);

	pass = new QLineEdit(verticalLayoutWidget);
	pass->setEchoMode(QLineEdit::Password);
	verticalLayout->addWidget(pass);

	newpass = new QLineEdit(verticalLayoutWidget);
	newpass->setEchoMode(QLineEdit::Password);
	verticalLayout->addWidget(newpass);

	confirmpass = new QLineEdit(verticalLayoutWidget);
	confirmpass->setEchoMode(QLineEdit::Password);
	verticalLayout->addWidget(confirmpass);

	pass->setPlaceholderText("password");
	newpass->setPlaceholderText("new password");
	confirmpass->setPlaceholderText("confirm new password");

	browse = new QPushButton("browse",this);
	browse->setGeometry(QRect(20, 190, 98, 27));
	connect(browse,SIGNAL(clicked()),this,SLOT(browse_clicked()));

	img_path = user->get_profpic();
	filepicker = new  QFileDialog(this);
	filepicker->hide();
}

void editwidget::save_clicked()
{
	if (pass->text().toStdString() == user->get_password())
	{
		if (newpass->text() == confirmpass->text())
			user->set_pass(newpass->text().toStdString());	
		else
		{
			QMessageBox::critical(this,"error occured!","new password and confirm password does not match!");
			return;
		}
	}	
	if (img_path != user->get_profpic())
		user->set_profpic(user->upload(img_path));
	user->save_data();

}

void editwidget::discard_clicked()
{
	//do nothing 
}

void editwidget::browse_clicked()
{
	QString fileName = filepicker->getOpenFileName(this, tr("Open File"),"/home",tr("Images (*.png *.xpm *.jpg)"));
	img_path = fileName.toStdString();
	image->setPixmap(QPixmap(fileName));
}

