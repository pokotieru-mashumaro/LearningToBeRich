#ifndef Channel_HPP
#define Channel_HPP

class Channel
{
private:
	int _operator_fd;
    std::vector<int> _cli_fds;

public:
	Channel()
	{
        _operator_fd = 111;
        (void) _cli_fds;
    };
};

#endif