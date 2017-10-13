#include "Instagholam.h"
#include <iostream>
#include <QApplication>
#include "UI.h"

// int main()
// {
// 	srand (time(NULL));
// 	Instagholam insta;
// 	// insta.register_user("marvin","1234");
// 	insta.login("alex","1234");
// // 	struct stat st = {0};
// // 	if (stat("./test/directory", &st) == -1) 
// // 	{
// // 		mkdir("./test/directory", 0700);
// // 	}	
// }

using namespace std;

int main(int argc,char *argv[])
{
	cerr << "in main"<< endl;
	QApplication app(argc,argv);
	UI window;
	window.show();
	return app.exec();
}