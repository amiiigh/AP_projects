#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Exeption.h"

#define LOGIN 1
#define SIGNUP 2
#define LOGOUT 3

using namespace std;

class Client
{
public:
	Client();
	vector<string>get_users_list();
	void see_user(string uname);
	void register_user(string username,string password);
	void login(string username,string password);	
	void logout();
private:
	int client_fd;
	// socket tcpsocket;
};


#endif