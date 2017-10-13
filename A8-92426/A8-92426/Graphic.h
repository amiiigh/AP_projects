#include <QApplication>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFont>
#include <QWidget>

class MyWidget :public QWidget
{
public:
	MyWidget(QWidget *parent =0);
	
};

MyWidget::MyWidget(QWidget *parent)
: QWidget(parent)
{
	setFixedSize(3000,3000);

	QPushButton *quit = new QPushButton(tr("Quit"), this);
	quit->setGeometry(62,40,75,30);
	quit->setFont(QFont("Times" ,18,QFont::Bold));

	// QLCDNumber *lcd = new QLCDNumber(4);
	// lcd->setSegmentStyle(QLCDNumber::Filled);

	// QSlider *slider = new QSlider(Qt::Horizontal);
	// slider->setRange(0,99);
	// slider->setValue(0);

//	connect(slider, SIGNAL(ValueChanged(int)),lcd,SLOT(display(int)));
	connect(quit,SIGNAL(clicked()), qApp , SLOT(quit()));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(quit);
	// layout->addWidget(lcd);
	// layout->addWidget(slider);
	setLayout(layout);
}

// int main(int argc, char  **argv)
// {
// 	QApplication app (argc,argv);
// 	MyWidget widget;
// 	widget.show();
// 	// QWidget window;
// 	// window.resize(200,120);

// 	// QPushButton quit("Quit",&window);

// 	// quit.setFont(QFont("Times",18,QFont::Bold));
// 	// quit.setGeometry(10,40,100,40);
// 	// QObject::connect(&quit , SIGNAL(clicked()), &app , SLOT(quit()));
// 	// quit.show();
// 	// window.show();
// 	return app.exec();
// }