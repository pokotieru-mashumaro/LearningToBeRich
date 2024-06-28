#ifndef CONTACT_H
# define CONTACT_H

# include <iomanip>
# include <iostream>
# include <string>

using namespace	std;

class Contact
{
  public:
	Contact(void);
	~Contact(void);

  private:
	string firstName;
	string lastName;
	string nickName;
	string phoneNumber;
	string darkestSecret;

  public:
	void setItems(void);
	void output_me_all(void);
	void output_me_restricted(int index);
};

#endif