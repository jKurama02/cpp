#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>


template<typename T>
class Array
{
	private:
		T* palle;
		unsigned int dim;

		public:
		Array();
		Array(unsigned int i);
		Array(const Array& other);
		Array& operator=(const Array &other);
		T& operator[](unsigned int i);

		T getItem(int g);

		unsigned int size();
		~Array();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);
#include "Array.tpp"
