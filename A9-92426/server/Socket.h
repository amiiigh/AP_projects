#ifndef SOCKET_H_
#define SOCKET_H_


#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <Poco/Thread.h>

using namespace std;
using namespace Poco;

class sock
{
public:
	sock(int client_fd);
	sock();
	int connect();
	void swrite(string data);
	string sread();
	void close();
	void set_fd(int client_fd);
private:
	int fd;
};

#endif