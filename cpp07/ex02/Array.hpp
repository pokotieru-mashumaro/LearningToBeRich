#ifndef   Array_HPP
#define   Array_HPP

#include <iostream>

template <class T>
class Array
{
	public:
		Array();
		Array(unsigned int i);
		~Array();
		Array(Array<T> const&);
		Array<T>& operator=(Array<T> const&);
		T& operator[](unsigned int i);
		void display(std::ostream& stream) const;
		unsigned int size() const;

	protected:
		T *_arr;
		unsigned int _size;
};

template <class T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
}

template <class T>
Array<T>::~Array()
{
	delete[] _arr;
}

#endif

