#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &copy)
{
	if (this != &copy)
		std::stack<T>::operator=(copy);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}
