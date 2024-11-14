#ifndef Server_HPP
#define Server_HPP

class Server //-> class for server
{
private:
	int _port;
	int _socket_fd;
	static bool _is_signal;
	std::vector<Client> _clients;
	std::vector<struct pollfd> _fds;

public:
	Server(){_socket_fd = -1;}

	void ServerInit();
	void SerSocket();
	void AcceptNewClient();
	void ReceiveNewData(int fd);

	static void SignalHandler(int signum);
	
	void CloseFds();
	void ClearClients(int fd);
};
#endif