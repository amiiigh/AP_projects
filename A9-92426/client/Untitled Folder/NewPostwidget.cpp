#include "NewPostwidget.h"

newpost::newpost(User *_current_user,QWidget *parent)
:QWidget(parent) , current_user(_current_user)
{
	this->setFixedSize(448,487);
	postback = new QLabel(this);
	postback->setObjectName("postback");
	postback->setGeometry(QRect(0, 0, 451, 341));
	postback->setPixmap(QPixmap(QString::fromUtf8("./Graphic/post_container.png")));

	horizontalLayoutWidget = new QWidget(this);
	horizontalLayoutWidget->setGeometry(QRect(0, 440, 441, 41));

	horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
	horizontalLayout->setContentsMargins(0, 0, 0, 0);


	discard = new QPushButton(horizontalLayoutWidget);
	discard->setText("discard");
	horizontalLayout->addWidget(discard);
	connect(discard,SIGNAL(clicked()),this,SLOT(discard_clicked()));

	horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout->addItem(horizontalSpacer);

	image = new QLabel(this);
	image->setGeometry(QRect(40, 70, 371, 171));
	image->setFrameShape(QFrame::StyledPanel);

	title_line = new QLineEdit(this);
	title_line->setGeometry(QRect(170, 20, 113, 27));
	title_line->setAlignment(Qt::AlignCenter);
	title_line->setPlaceholderText("title");
	browse = new QPushButton(this);
	browse->setObjectName(QString::fromUtf8("browse"));
	browse->setGeometry(QRect(0, 350, 85, 27));
	browse->setText("Browse...");
	connect(browse,SIGNAL(clicked()),this,SLOT(browse_clicked()));

	create = new QPushButton(horizontalLayoutWidget);
	create->setObjectName(QString::fromUtf8("create"));
	create->setText("create");
	connect(create,SIGNAL(clicked()),this,SLOT(create_clicked()));

	horizontalLayout->addWidget(create);
	text_con = new QLineEdit(this);
	text_con->setGeometry(QRect(40, 270, 371, 27));
	text_con->setPlaceholderText("your text goes here");

	filepicker = new  QFileDialog(this);
	filepicker->hide();
	img_path ="";
}

void newpost::create_clicked()
{
	if (title_line->text().toStdString()=="" || text_con->text().toStdString() == "")
	{
		QMessageBox::critical(this,"error occured!","fill the empty field!");
		return;
	}
	if (img_path == "")
	{
		QMessageBox::critical(this,"error occured!","choose photo first!");
		return;
	}
	current_user->create_post(title_line->text().toStdString(),current_user->upload(img_path),text_con->text().toStdString());
	current_user->save_data();
	emit disclick();


}

void newpost::discard_clicked()
{
	// delete this;
	emit disclick();
}

void newpost::browse_clicked()
{
	QString fileName = filepicker->getOpenFileName(this, tr("Open File"),"/home",tr("Images (*.png *.xpm *.jpg)"));
	img_path = fileName.toStdString();
	image->setPixmap(QPixmap(fileName));
}

