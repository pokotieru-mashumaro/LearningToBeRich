#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

  private:
	Contact _contacts[8];
  	int _total_contacts;

  public:
	void addContact(void);
	void searchContact(void);
};

#endif