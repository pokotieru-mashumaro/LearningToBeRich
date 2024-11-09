#ifndef MutantStack_HPP
# define MutantStack_HPP

# include <iostream>
# include <list>
# include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &copy);
	~MutantStack();
	MutantStack &operator=(const MutantStack &copy);

	//イテレータの実装
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif
