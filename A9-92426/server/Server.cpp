#include "Server.h"

void ConnectionHandler::run()
{
	stringstream ss;
	char c ;
	int task;
	string tasksize ;
	int j =0 ;
	int tsize;
	while (true)
	{
		c = '-';
		tasksize = "";
		task =0 ;
		tsize =0 ;
		for (int i =0 ; c !='\n' ; i++)
		{
			read(client_fd , &c , 1);
			tasksize += c;
		}
		tsize = atoi(tasksize.c_str());
		char* buf = new char [tsize];
		int n = read(client_fd, buf,tsize);

		string t(buf,tsize);
		ss.str("");
		ss << t ;
		ss >> task;
		switch (task)
		{
			case LOGIN:
			{
				string username;
				string password;
				getline(ss,username);
				getline(ss,username);
				getline(ss,password);
				try
				{
					cout << "login!"<<endl;
					cout << "username is : "<<username << endl << "password is : " <<password << endl;
					insta->login(username,password);	
					write(client_fd,"1\n0",3);
				}
				catch(Ex ex)
				{
					cout << ex.get_message()<<endl;
					stringstream es;
					int essize ;
					es<<1<<endl<<ex.get_message()<<endl;
					essize = es.str().size();
					string temp = es.str();
					es.str("");
					es << essize << endl<< temp ;
					write(client_fd, es.str().c_str(), strlen(es.str().c_str()));
					es.str("");
				}
				break;
			}	
			case SIGNUP:
			{
				string username;
				string password;
				getline(ss,username);
				getline(ss,username);
				getline(ss,password);
				try
				{
					cout << "signup"<<endl;
					
					cout << "username is : "<<username << endl << "password is : " <<password << endl;
					insta->register_user(username,password);	
					write(client_fd,"1\n0",3);
				}
				catch(Ex ex)
				{
					cout << ex.get_message()<<endl;
					stringstream es;
					int essize ;
					es<<1<<endl<<ex.get_message()<<endl;
					essize = es.str().size();
					string temp = es.str();
					es.str("");
					es << essize << endl<< temp ;
					write(client_fd, es.str().c_str(), strlen(es.str().c_str()));
					es.str("");
				}

				break;
			}
			case LOGOUT:
			{
				string temp ;
				getline(ss,temp);
				insta->logout();
				break;
			}
		}
		delete[] buf;		
	}
	close(client_fd);
}



int main() 
{
	// Create the server socket. fd is the server socket descriptor
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	// Enable to connect to the server even if the address is already in use
	int iSetOption = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char*)&iSetOption, sizeof(iSetOption));
	
	// Anybody can connect to the server on port 9996
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;     
	serv_addr.sin_port = htons(9996);     

	// Bind the socket to the specified address and port
	bind(fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

	// Listen on the server socket
	if (listen(fd, MAX_CONNECTIONS) == -1)
		printf("Listening Error!\n"); 

	cout << "Server started!\n";

	vector<ConnectionHandler> connections;	// The connection handler objects are kept here
	Thread threads[MAX_CONNECTIONS];		// The connection handler threads

	for (int i = 0; i < MAX_CONNECTIONS; i++)
	{
		// Accept incoming connection from a new client:
		struct sockaddr_in client_addr;
		socklen_t client_addr_size = sizeof(client_addr);
		int client_fd = accept(fd, (struct sockaddr *) &client_addr, &client_addr_size);
		cout << "New client accepted with id " << client_fd << endl;

		// Store the connection handler and start the thread:
		connections.push_back(ConnectionHandler(client_fd));
		threads[i].start(connections[i]);
	}
	close(fd);
}