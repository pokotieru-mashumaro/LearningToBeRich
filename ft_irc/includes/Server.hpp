#ifndef Server_HPP
#define Server_HPP

class Server
{
    private:
        static bool _is_signal;

    public:
        Server();
        Server(const Server &copy);
        ~Server();
        Server& operator=(const Server &copy);

        static void signal_handler(int signum); 
        void make_socket();
};

#endif