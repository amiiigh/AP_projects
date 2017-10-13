#ifndef SERVER_H_
#define SERVER_H_

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
#include "Instagholam.h"
#include "Socket.h"

using namespace Poco;
using namespace std;

#define MAX_CONNECTIONS 10	// Maximum number of times the client can connect to the server

#define LOGIN 1
#define SIGNUP 2
#define LOGOUT 3

class ConnectionHandler : public Runnable 
{
public:
	ConnectionHandler(int cfd) 
	: client_fd(cfd) // Socket descriptor associated to the connecting client
	{insta = new Instagholam;}
	virtual void run();
private:
	int client_fd;
	Instagholam* insta;
	// sock tcpsocket;
};


#endif