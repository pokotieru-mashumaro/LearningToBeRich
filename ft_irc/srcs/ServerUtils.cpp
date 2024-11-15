#include "../includes/All.hpp"

Client &Server::SearchCli(int cli_fd)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i].getFd() == cli_fd)
			return _clients[i];
	}
	// ここにくるのはありえないのでthrowする。今はめんどい
	return _clients[0];
}

void Server::SendMsg2Client(int cli_fd, const char *str)
{
	char buf[200];

	strcpy(buf, str);
	ssize_t bytes = send(cli_fd, buf, (int)strlen(buf), 0);
	if (bytes == -1)
		std::cout << RED << "やばいよやばいよ" << WHI << std::endl;
}

void Server::Auth(Client &target, std::string msg)
{
    if (_password == msg)
    {
        target.setStatus(NEED_NAMES);
        SendMsg2Client(target.getFd(), AUTH_SUCCESS);
    }
    else
        SendMsg2Client(target.getFd(), AUTH_FAIL);
}

void Server::SetNames(Client &target, std::string msg)
{
    if (target.getNickName() == "")
        target.setNickName(msg);
    else if (target.getUserName() == "")
    {
        target.setUserName(msg);
        if (msg != "")
        {
            target.setStatus(IN_HOME);
            SendMsg2Client(target.getFd(), FINISH_INPUT_USERNAME);
            SendMsg2Client(target.getFd(), HELLO_HOME);
        }
    }
    if (target.getNickName() == "")
        SendMsg2Client(target.getFd(), INPUT_NICKNAME);
    else if (target.getUserName() == "")
        SendMsg2Client(target.getFd(), INPUT_USERNAME);
}