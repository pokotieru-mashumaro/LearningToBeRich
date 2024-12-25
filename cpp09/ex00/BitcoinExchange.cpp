#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    try
    {
        (void) filename;
        setBitcoinPrice("data.csv");
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        this->_bitcoinPrice = copy._bitcoinPrice;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::setBitcoinPrice(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (count_char(line, ',') != 1)
            throw std::runtime_error("Error: invalid format in data.csv.");

        std::stringstream ss(line);
        std::string date;
        std::string rate;


        if (std::getline(ss, date, ',') && std::getline(ss, rate))
        {
            if (is_date(date) == false)
                throw std::runtime_error("Error: bad input => " + date);
            double value = atof(rate.c_str());
            // std::cout << "rate: " << rate << ", value: " << value << std::endl;
            if (!is_double(rate))
                throw std::runtime_error("Error: not a positive number.");
            _bitcoinPrice[date] = value;
        } else
            throw std::runtime_error("Error: invalid format in data file.");
    }
}

void BitcoinExchange::displayPrice()
{
    for (std::map<std::string, double>::iterator it = _bitcoinPrice.begin(); it != _bitcoinPrice.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
}
