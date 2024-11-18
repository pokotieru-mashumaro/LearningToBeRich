#ifndef Server_HPP
#define Server_HPP

class Server
{
private:
	int _port;
	std::string _password;
	int _socket_fd;
	static bool _is_signal;
	std::vector<Client *> _clients;
	std::vector<Channel *> _channels;
	std::vector<struct pollfd> _fds;

public:
	Server(int port, std::string password)
	{
		_port = port;
		_password = password;
		_socket_fd = -1;
		(void) _channels;
	}

	std::vector<std::string> getChannelNames();


	void ServerInit();
	void SerSocket();
	void AcceptNewClient();
	void ReceiveNewData(int fd);

	void OpenChannel(Client *target);
	void JoinChannel(Client *target, Channel *channel);


	void SendMsg2Client(int cli_fd, const char *str);
	void SendUserTerminal(int cli_fd, char buff[1024]);
	Client *SearchCli(int cli_fd);

	void Auth(Client *target, std::string msg);
	void SetNames(Client *target, std::string msg);
	void Home(Client *target, std::string msg);
	void Send2Channel(Client *target, std::string msg);

	static void SignalHandler(int signum);

	void CloseFds();
	void ClearClients(int fd);
};
#endif
