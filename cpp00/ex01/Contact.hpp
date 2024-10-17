#ifndef CONTACT_H
# define CONTACT_H

# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  public:
	Contact(void);
	~Contact(void);

  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	void setItems(void);
	void output_me_all(void);
	void output_me_restricted(int index);
};

#endif