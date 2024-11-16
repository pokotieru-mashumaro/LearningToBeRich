#ifndef Channel_HPP
#define Channel_HPP

#include "Client.hpp"

class Channel
{
private:
	std::vector<Client *>  _operators;
    std::vector<Client *> _clients;

public:
	Channel(Client *owner)
	{
        _operators.push_back(owner);
        _clients.push_back(owner);
    };

    // Client getOperator(){return _operator;};

    void setClient(Client *cli){_clients.push_back(cli);};

    void kick();
    void invite();
    void topic();
    void mode(int mode);
};

#endif