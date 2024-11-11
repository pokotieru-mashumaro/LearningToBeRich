#include "../includes/All.hpp"

Client::Client()
{}

Client::Client(const Client &copy) {
	*this = copy;
}

Client::~Client()
{}

Client &Client::operator=(const Client &copy) {
    if (this == &copy)
        return *this;
    return *this;
}

