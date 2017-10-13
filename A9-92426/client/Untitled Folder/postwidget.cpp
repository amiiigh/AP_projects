#include "postwidget.h"



pwidget::pwidget(User* _current_user , QWidget *parent)
:QWidget(parent) ,current_user(_current_user)
{
	this->setFixedSize(451,341);
	postback = new QLabel(this);
	postback->setGeometry(QRect(0, 0, 451, 341));
	postback->setPixmap(QPixmap("./Graphic/post_container.png"));

	title_label = new QLabel(this);
	title_label->setGeometry(QRect(180, 10, 150, 17));

	author_label = new QLabel(this);
	author_label->setGeometry(QRect(100, 315, 51, 17));

	likes = new QLabel(this);
	likes->setGeometry(QRect(100, 290, 150, 17));

	label_7 = new QLabel(this);
	label_7->setGeometry(QRect(20, 290, 150, 17));
	label_7->setText("Liked by :");


	date_label = new QLabel(this);
	date_label->setGeometry(QRect(190, 315, 150, 17));

	post_img = new QLabel(this);
	post_img->setGeometry(QRect(20, 30, 401, 211));
	post_img->setFrameShape(QFrame::StyledPanel);


	like_butt = new QPushButton(this);
	like_butt->setGeometry(QRect(330, 300, 98, 27));
	like_butt->setText("like");
	connect(like_butt,SIGNAL(clicked()),this,SLOT(like_clicked()));

	text_con = new QLabel(this);
	text_con->setGeometry(QRect(20, 249, 401, 31));
	text_con->setFrameShape(QFrame::StyledPanel);

	label_5 = new QLabel(this);
	label_5->setGeometry(QRect(20, 315, 71, 20));
	label_6 = new QLabel(this);
	label_6->setGeometry(QRect(160, 315, 21, 17));
	label_5->setText("posted by ");
	label_6->setText("at");
}

void pwidget::like_clicked()
{
	vector<Post>newfav;
	vector<Post> temp;
	vector<string> stemp;
	newfav = current_user->get_fav();
	newfav.push_back(data);
	current_user->set_fav(newfav);
	current_user->save_data();
	like_butt->setEnabled(false);
	current_user->delete_from_news(data);

	User postowner;
	postowner.set_user(data.get_author());
	postowner.load_data();
	temp = postowner.get_up_post();
	for (int i=0 ; i< temp.size(); i++)	
	{
		if (data == temp[i])
		{
			stemp = temp[i].get_liked();
			stemp.push_back(current_user->get_username());
			temp[i].set_liked_vec(stemp);
			postowner.set_up(temp);
			postowner.save_data();
			break;
		}
	}
	current_user->save_data();
}

// pwidget::~pwidget()
// {
// 	delete postback;
// 	delete title_label;
// 	delete author_label;
// 	delete date_label;
// 	delete post_img;
// 	delete like_butt;
// 	delete label_5;
// 	delete label_6;
// 	delete text_con;
// }