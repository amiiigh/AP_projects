#include "Client.h"

Client::Client()
{
	client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	int iSetOption = 1;
	setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&iSetOption, sizeof(iSetOption));
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;     
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // The IP address of the server    
	serv_addr.sin_port = htons(9996);
	cout << "connect: " << connect(client_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) << endl;
	// tcpsocket.set_fd(client_fd);
}

vector<string> Client::get_users_list()
{

}

void Client::see_user(string uname)
{

}

void Client::register_user(string username,string password)
{
	int task = SIGNUP;
	stringstream ss;
	ss << task << endl << username << endl << password << endl;
	int tasksize = ss.str().size();
	string comptask= ss.str();
	ss.str("");
	ss << tasksize << endl << comptask ;
	write(client_fd, ss.str().c_str(), strlen(ss.str().c_str()));

	char c;
	string resultsize;
	int result ;
	for (int i =0 ; c !='\n' ; i++)
	{
		read(client_fd , &c , 1);
		resultsize += c;
	}
	int rsize = atoi(resultsize.c_str());

	char* buf = new char [rsize];
	read(client_fd, buf,rsize);

	string t(buf,rsize);
	string temp;
	stringstream rs;
	rs << t;
	rs >> result ;
	if (result == 1)
	{
		getline(rs,temp);
		getline(rs,temp);
		throw Ex(temp);
	}

	delete[] buf;	
}

void Client::login(string username,string password)
{
	int task = LOGIN;
	stringstream ss;
	ss << task << endl << username << endl << password << endl;
	int tasksize = ss.str().size();
	string comptask= ss.str();
	ss.str("");
	ss << tasksize << endl << comptask ;
	write(client_fd, ss.str().c_str(), strlen(ss.str().c_str()));
	cout << ss.str() << endl;
	char c;
	string resultsize;
	int result ;
	for (int i =0 ; c !='\n' ; i++)
	{
		read(client_fd , &c , 1);
		resultsize += c;
	}
	int rsize = atoi(resultsize.c_str());

	char* buf = new char [rsize];
	//cout<<"PAYAN "<<buf
	read(client_fd, buf,rsize);
	string t(buf,rsize);
	string temp;
	stringstream rs;
	rs << t;
	rs >> result ;
	if (result == 1)
	{
		getline(rs,temp);
		getline(rs,temp);
		throw Ex(temp);
	}
	write(client_fd, ss.str().c_str(), strlen(ss.str().c_str()));
	delete[] buf;
}
void Client::logout()
{
	int task = LOGOUT;
	stringstream ss;
	ss << task << endl ;
	int tasksize = ss.str().size();
	string comptask= ss.str();
	ss.str("");
	ss << tasksize << endl << comptask ;
	write(client_fd, ss.str().c_str(), strlen(ss.str().c_str()));
	
	// char c;
	// string resultsize;
	// int result ;
	// for (int i =0 ; c !='\n' ; i++)
	// {
	// 	read(client_fd , &c , 1);
	// 	resultsize += c;
	// }
	// int rsize = atoi(resultsize.c_str());

	// char* buf = new char [rsize];
	// //cout<<"PAYAN "<<buf
	// read(client_fd, buf,rsize);
	// string t(buf,rsize);
	// string temp;
	// stringstream rs;
	// rs << t;
	// rs >> result ;
	// if (result == 1)
	// {
	// 	getline(rs,temp);
	// 	getline(rs,temp);
	// 	throw Ex(temp);
	// }
	// write(client_fd, ss.str().c_str(), strlen(ss.str().c_str()));
	// delete[] buf;
}