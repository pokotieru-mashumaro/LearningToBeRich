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
    typedef void (Harl::*func_pointer)(void);

    func_pointer funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level_num = 0;

	while (level_num < 4) {
		if (!levels[level_num].compare(level))
			break ;
		level_num++;
	}
    if (level_num < 4)
	    (this->*funcs[level_num])();
    else
        std::cout << "そんなlevelは知らん。" << std::endl << std::endl;
}