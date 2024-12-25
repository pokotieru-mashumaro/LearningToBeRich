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

    static std::string trim(const std::string &str) {
        size_t first = str.find_first_not_of(" \t");
        if (first == std::string::npos)
            return "";
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, last - first + 1);
    }

public:
    BitcoinExchange(std::string filename);
    ~BitcoinExchange();

    void display(std::string filename);
    void displayPrice();

};
