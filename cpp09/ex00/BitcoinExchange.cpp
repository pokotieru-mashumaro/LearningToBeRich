#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    try
    {
        (void) filename;
        setBitcoinPrice("data.csv");
        display(filename);
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
    if (!is_header(line, ','))
        throw std::runtime_error("Error: invalid format in data.csv.");

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
        } 
        else
            throw std::runtime_error("Error: invalid format in data.csv.");
    }
}

void BitcoinExchange::display(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    if (!is_header(line, '|'))
        throw std::runtime_error("Error: invalid format in input file.");

    while (std::getline(file, line))
    {
        if (count_char(line, '|') != 1)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string date;
        std::string value_str;
        
        if (std::getline(ss, date, '|') && std::getline(ss, value_str))
        {
            date = trim(date);
            value_str = trim(value_str);

            if (is_date(date) == false)
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            
            if (!is_double(value_str))
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            double value = atof(value_str.c_str());
            if (value < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else if (value > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            
            double rate;
            if (_bitcoinPrice.find(date) == _bitcoinPrice.end())
            {
                std::map<std::string, double>::iterator it = _bitcoinPrice.lower_bound(date);
                if (it == _bitcoinPrice.begin() && date < it->first)
                {
                    std::cout << "Error: no data available for this date." << std::endl;
                    continue;
                }
                else if (it == _bitcoinPrice.end())
                    --it;
                rate = it->second;
            }
            else
            {
                rate = _bitcoinPrice[date];
            }

            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        else
            std::cout << "Error: invalid format in input file." << std::endl;
    }
}

void BitcoinExchange::displayPrice()
{
    for (std::map<std::string, double>::iterator it = _bitcoinPrice.begin(); it != _bitcoinPrice.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
}
