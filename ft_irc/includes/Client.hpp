#ifndef Client_HPP
#define Client_HPP

class Client
{
    public:
        Client();
        Client(const Client &copy);
        ~Client();
        Client& operator=(const Client &copy);

};

#endif