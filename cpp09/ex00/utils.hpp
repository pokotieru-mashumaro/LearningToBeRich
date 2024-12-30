#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

size_t count_char(const std::string &str, char c);
std::string trim(const std::string &str);
bool is_header(const std::string &str, char c);
bool is_double(const std::string &str);
bool is_date(const std::string &str);
