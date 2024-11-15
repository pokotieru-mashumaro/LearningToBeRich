#ifndef Server_HPP
#define Server_HPP

class Server
{
private:
	int _port;
	std::string _password;
	int _socket_fd;
	static bool _is_signal;
	std::vector<Client> _clients;
	std::vector<Channel> _channels;
	std::vector<struct pollfd> _fds;

public:
	Server(int port, std::string password)
	{
		_port = port;
		_password = password;
		_socket_fd = -1;
		(void) _channels;
	}

	void ServerInit();
	void SerSocket();
	void AcceptNewClient();
	void ReceiveNewData(int fd);
	void OpenChannel(Client &target);

	void SendMsg2Client(int cli_fd, const char *str);
	void SendUserTerminal(int cli_fd, char buff[1024]);
	Client &SearchCli(int cli_fd);

	static void SignalHandler(int signum);

	void CloseFds();
	void ClearClients(int fd);
};
#endif
