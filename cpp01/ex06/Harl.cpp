#include "Harl.hpp"
#include <map>

Harl::Harl() {
    return ;
}

Harl::~Harl() {
    return ;
}

void Harl::debug(void) 
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void) 
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void) 
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void) 
{
	std::cout <<  "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) 
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level_num = 0;

	while (level_num < 4 && levels[level_num].compare(level))
		level_num++;
	switch (level_num) {
	case	0:
		this->debug();
	case	1:
		this->info();
	case	2:
		this->warning();
	case	3:
		this->error();
		break ;
	default:
		std::cout << "そんなlevelは知らん。" << std::endl;
	}
}

