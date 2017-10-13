#include <iostream>
#include <fstream>
#include "Bookeater.h"
#include "Library.h"
#include <QApplication>
#include "mywidget.h"
#include <sstream>

using namespace std;

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	mywidget window;
	window.show();

	return app.exec();
}