#include "../includes/All.hpp"

Client *Server::SearchCli(int cli_fd)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
	    // std::cout << "^^^^^^^^^^^^"<< std::endl;
        // std::cout << "cli fd: " << _clients[i]->getFd() << std::endl;
        std::cout << "cli01 address: " << _clients[i] << " fd: " << _clients[i]->getFd()  << std::endl;
		if (_clients[i]->getFd() == cli_fd)
			return _clients[i];
	}
	// ここにくるのはありえないのでthrowする。今はめんどい
	return _clients[0];
}

void Server::SendMsg2Client(int cli_fd, const char *str)
{
	char buf[1000];
    
	strcpy(buf, str);
	ssize_t bytes = send(cli_fd, buf, (int)strlen(buf), 0);
	if (bytes == -1)
		std::cout << RED << "やばいよやばいよ" << WHI << std::endl;
}

void Server::Auth(Client *target, std::string msg)
{
    if (_password == msg)
    {
        target->setStatus(NEED_NAMES);
        SendMsg2Client(target->getFd(), AUTH_SUCCESS);
    }
    else
        SendMsg2Client(target->getFd(), AUTH_FAIL);
}

void Server::SetNames(Client *target, std::string msg)
{
    if (target->getNickName() == "")
        target->setNickName(msg);
    else if (target->getUserName() == "")
    {
        target->setUserName(msg);
        if (msg != "")
        {
            target->setStatus(IN_HOME);
            SendMsg2Client(target->getFd(), HELLO_HOME);
        }
    }
    if (target->getNickName() == "")
        SendMsg2Client(target->getFd(), INPUT_NICKNAME);
    else if (target->getUserName() == "")
        SendMsg2Client(target->getFd(), INPUT_USERNAME);
}

void Server::OpenChannel(Client *target)
{
	Channel *channel = new Channel(target);
	_channels.push_back(channel);
	target->setChannel(channel);
}

void Server::JoinChannel(Client *target, Channel channel)
{
    (void) target;
    (void) channel;

	// channel.setClient(target);
}

void Server::Home(Client *target, std::string msg)
{
    if (msg == "OPEN")
    {
        OpenChannel(target);
        target->setStatus(IN_CHANNEL);

        SendMsg2Client(target->getFd(), "\n\nChannelを開きます。\nChannel名: ");
    }
    else if (msg == "JOIN")
    {
        //どのチャンネルに入りたいか選択する。
        // Channel channel; // = ~~~
        // JoinChannel(target, channel);

        target->setStatus(IN_CHANNEL);
        SendMsg2Client(target->getFd(), "Channelの名前を入力: ");
    }
    else {
        SendMsg2Client(target->getFd(), "> ");
    }
}

void Server::Send2Channel(Client *target, std::string msg)
{
    // Channel *channel = target->getChannel();
    (void) msg;
    // std::cout << "channel orner name: " << target->getUserName() << std::endl;
    if (target->getChannel()->getName() == "")
        target->getChannel()->setName(msg);
    else
    {
        std::cout << "channel name: " << target->getChannel()->getName() << std::endl;
    }

    if (target->getChannel()->getName() == "")
        SendMsg2Client(target->getFd(), "Channelの名前を入力: ");
    else
    {
        SendMsg2Client(target->getFd(), "> ");
    }
}