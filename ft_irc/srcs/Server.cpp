#include "../includes/All.hpp"

void Server::ClearClients(int fd){
	for(size_t i = 0; i < _fds.size(); i++)
	{ 
		if (_fds[i].fd == fd)
			{_fds.erase(_fds.begin() + i); break;}
	}
	for(size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i].GetFd() == fd)
			{_clients.erase(_clients.begin() + i); break;}
	}
}

bool Server::_is_signal = false;
void Server::SignalHandler(int signum)
{
	(void)signum;
	std::cout << std::endl << "Signal Received!" << std::endl;
	Server::_is_signal = true;
}

void	Server::CloseFds()
{
	for(size_t i = 0; i < _clients.size(); i++){
		std::cout << RED << "Client <" << _clients[i].GetFd() << "> Disconnected" << WHI << std::endl;
		close(_clients[i].GetFd());
	}
	if (_socket_fd != -1){
		std::cout << RED << "Server <" << _socket_fd << "> Disconnected" << WHI << std::endl;
		close(_socket_fd);
	}
}

void Server::ReceiveNewData(int fd)
{
	char buff[1024];
	memset(buff, 0, sizeof(buff));

	ssize_t bytes = recv(fd, buff, sizeof(buff) - 1 , 0);

	if(bytes <= 0)
	{
		std::cout << RED << "Client <" << fd << "> Disconnected" << WHI << std::endl;
		ClearClients(fd);
		close(fd);
	}
	else
	{
		buff[bytes] = '\0';
		std::cout << YEL << "Client <" << fd << "> Data: " << WHI << buff;
		//here you can add your code to process the received data: parse, check, authenticate, handle the command, etc...
	}
}

void Server::AcceptNewClient()
{
	Client cli;
	struct sockaddr_in cliadd;
	struct pollfd NewPoll;
	socklen_t len = sizeof(cliadd);

	int incofd = accept(_socket_fd, (sockaddr *)&(cliadd), &len); 
	if (incofd == -1)
		{std::cout << "accept() failed" << std::endl; return;}

	if (fcntl(incofd, F_SETFL, O_NONBLOCK) == -1)
		{std::cout << "fcntl() failed" << std::endl; return;}

	NewPoll.fd = incofd;
	NewPoll.events = POLLIN;
	NewPoll.revents = 0;

	cli.SetFd(incofd);
	cli.setIpAdd(inet_ntoa((cliadd.sin_addr)));
	_clients.push_back(cli);
	_fds.push_back(NewPoll);

	//TODO: sendコマンドを使ってClientにメッセージを送りつける
	const char *message = "hello, world\n";
	ssize_t bytes = send(incofd, message, (int)strlen(message), 0);
	(void) bytes;
	std::cout << GRE << "Client <" << incofd << "> Connected" << WHI << std::endl;
}

void Server::SerSocket()
{
	int en = 1;
	struct sockaddr_in add;
	struct pollfd NewPoll;
	add.sin_family = AF_INET;
	add.sin_addr.s_addr = INADDR_ANY;
	add.sin_port = htons(this->_port);

	_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(_socket_fd == -1)
		throw(std::runtime_error("faild to create socket"));
	if(setsockopt(_socket_fd, SOL_SOCKET, SO_REUSEADDR, &en, sizeof(en)) == -1)
		throw(std::runtime_error("faild to set option (SO_REUSEADDR) on socket"));
	if (fcntl(_socket_fd, F_SETFL, O_NONBLOCK) == -1)
		throw(std::runtime_error("faild to set option (O_NONBLOCK) on socket"));
	if (bind(_socket_fd, (struct sockaddr *)&add, sizeof(add)) == -1)
		throw(std::runtime_error("faild to bind socket"));
	if (listen(_socket_fd, SOMAXCONN) == -1)
		throw(std::runtime_error("listen() faild"));

	NewPoll.fd = _socket_fd;
	NewPoll.events = POLLIN;
	NewPoll.revents = 0;
	_fds.push_back(NewPoll);
}

void Server::ServerInit()
{
	this->_port = 4444;
	SerSocket();

	std::cout << GRE << "Server <" << _socket_fd << "> Connected" << WHI << std::endl;
	std::cout << "Waiting to accept a connection...\n";

	while (Server::_is_signal == false)
	{
		if((poll(&_fds[0], _fds.size(), -1) == -1) && Server::_is_signal == false)
			throw(std::runtime_error("poll() faild"));
		std::cout << "let's start!!" << std::endl;
		for (size_t i = 0; i < _fds.size(); i++)
		{
			std::cout << "revents: " << _fds[i].revents << std::endl;
			if (_fds[i].revents & POLLIN)
			{
				if (_fds[i].fd == _socket_fd)
					AcceptNewClient();
				else
					ReceiveNewData(_fds[i].fd);
			}
		}
	}
	CloseFds();
}
