#include "utils.hpp"

size_t count_char(const std::string &str, char c)
{
    size_t count = 0;
    for (size_t i = 0; i < str.size(); i++)
        if (str[i] == c)
            count++;
    return count;
}

std::string trim(const std::string &str)
{
    std::string::size_type first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    std::string::size_type last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

bool is_header(const std::string &str, char c)
{
    if (c == '|' && str != "date | value")
        return false;
    else if (c == ',' && str != "date,exchange_rate")
        return false;
    return true;
}

bool is_date(const std::string &str)
{
    if (str.size() != 10)
        return false;
    if (count_char(str, '-') != 2)
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (str[i] != '-')
                return false;
        }
        else if ((i != 4 && i != 7) && (str[i] < '0' || str[i] > '9'))
            return false;
    }

    int year = std::atoi(str.substr(0, 4).c_str());
    int month = std::atoi(str.substr(5, 2).c_str());
    int day = std::atoi(str.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 閏年の判定
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        days_in_month[2] = 29;

    if (day < 1 || day > days_in_month[month])
        return false;

    return true;
}

bool is_double(const std::string &str)
{
    if (count_char(str, '.') > 1)
        return false;
    int zero_count = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != '0')
            break;
        zero_count++;
    }
    if (zero_count > 1)
        return false;
    if (str.size() > 1 && str[0] == '0' && str[1] != '.')
        return false;
    for (size_t i = 0; i < str.size(); i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            return false;
    return true;
}
