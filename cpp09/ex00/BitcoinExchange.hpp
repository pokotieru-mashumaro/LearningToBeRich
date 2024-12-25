#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

#include "utils.hpp"

class BitcoinExchange {
private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);

    void setBitcoinPrice(std::string filename);

    std::map<std::string, double> _bitcoinPrice;

public:
    BitcoinExchange(std::string filename);
    ~BitcoinExchange();

    void displayPrice();

};
