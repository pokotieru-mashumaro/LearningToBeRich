#ifndef Client_HPP
#define Client_HPP

#define NEED_PASSWORD 1
#define NEED_NAMES 2
#define IN_HOME 3
#define IN_CHANNEL 4
#define SET_CHANNELNAME 5

class Channel;

class Client
{
private:
	int _fd;
	int _status;
	std::string _ipadd;
	std::string _nickname;
	std::string _username;
	Channel *_nowchannel;

public:
	Client(int fd)
	{
		_status = NEED_PASSWORD;
		_nickname = "";
		_username = "";
		_fd = fd;
		_nowchannel = NULL;
	};
	int getFd() const {return _fd;}
	int getStatus() const {return _status;}
	std::string getNickName() const {return _nickname;}
	std::string getUserName() const {return _username;}
	Channel *getChannel() const {return _nowchannel;}

	void setFd(int fd){_fd = fd;}
	void setStatus(int status){_status = status;}
	void setIpAdd(std::string ipadd){_ipadd = ipadd;}
	void setNickName(std::string nickname){_nickname = nickname;}
	void setUserName(std::string username){_username = username;}
	void setChannel(Channel *channel){_nowchannel = channel;}

	void OpenChannel();
};

#endif