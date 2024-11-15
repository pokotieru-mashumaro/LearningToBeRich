#ifndef Channel_HPP
#define Channel_HPP

class Channel
{
private:
	int _operator_fd;
    std::vector<int> _cli_fds;

public:
	Channel(int operator_fd)
	{
        _operator_fd = operator_fd;
        _cli_fds.push_back(operator_fd);
    };

    void kick();
    void invite();
    void topic();
    void mode(int mode);
};

#endif