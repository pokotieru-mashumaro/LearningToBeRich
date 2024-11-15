#ifndef Client_HPP
#define Client_HPP

#define NEED_PASSWORD 1
#define NEED_NAMES 2
#define IN_HOME 3
#define IN_CHANNEL 4

class Client
{
private:
	int _fd;
	int _status;
	std::string _ipadd;
	std::string _nickname;
	std::string _username;

public:
	Client()
	{
		_status = NEED_PASSWORD;
	};
	int getFd(){return _fd;}
	int getStatus(){return _status;}

	void setFd(int fd){_fd = fd;}
	void setStatus(int status){_status = status;}
	void setIpAdd(std::string ipadd){_ipadd = ipadd;}
};

#endif