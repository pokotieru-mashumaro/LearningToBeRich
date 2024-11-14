#ifndef Client_HPP
#define Client_HPP

class Client
{
private:
	int _fd;
	std::string _ipadd;
public:
	Client(){};
	int GetFd(){return _fd;}

	void SetFd(int fd){_fd = fd;}
	void setIpAdd(std::string ipadd){_ipadd = ipadd;}
};

#endif