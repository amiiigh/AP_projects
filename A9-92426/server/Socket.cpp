#include "Socket.h"

sock::sock(int client_fd)
{

}

sock::sock()
{

}

int sock::connect()
{

}

void sock::swrite(string data)
{

	stringstream ss;
	ss << data.size() << endl << data;
	write(fd, ss.str().c_str(), ss.str().size());
}

string sock::sread()
{
	string datasize;
	char c;
	for (int i =0 ; c !='\n' ; i++)
	{
		read(fd , &c , 1);
		datasize += c;
	}
	int dsize = atoi(datasize.c_str());

	char* buf = new char [dsize];
	//cout<<"PAYAN "<<buf
	read(fd, buf,dsize);
	string t(buf,dsize);
	delete[] buf;
	return  t;
}

void sock::close()
{

}

void sock::set_fd(int client_fd)
{
	fd = client_fd;
}