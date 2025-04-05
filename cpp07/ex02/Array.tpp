
#include <iostream>
#include"Array.hpp"

template<typename T>
Array<T>::Array() : palle(NULL) , dim(0){};

template<typename T>
Array<T>::Array(unsigned int i) : dim(i)
{
	palle = new T[i];
}
template<typename T>
Array<T>::~Array()
{
	if(palle)
	{
		delete[] palle;
	}
	palle = NULL;
}

template<typename T>
T Array<T>::getItem(int g)
{
	return(this->palle[g]);
}

template<typename T>
Array<T>::Array(const Array& other)
{

		palle = new T[other.dim];
		for(unsigned 	int i = 0; i < other.dim; i++)
		{
			this->palle[i] = other.palle[i];
		}
		this->dim = other.dim;
}


template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other)
	{
		if(this->palle)
			delete[] this->palle;
		this->dim = other.dim;
		this->palle = new T[other.dim];
		for (unsigned int i = 0; i < other.dim; i++)
		{
			this->palle[i] = other.palle[i]; // Correzione: usa other.palle[i]
		}
	}
	return *this;
}


template<typename T>
unsigned int Array<T>::size()
{
	return dim;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= dim) {
		throw std::out_of_range("Index out of range");
	} else {
		return palle[i];
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& os,const Array<T>& arr) {
	unsigned int f = arr.size();
	for (unsigned int i = 0; i < f; ++i)
	{
		os << arr[i];
		if (i < arr.size() - 1) {
			os << ", ";
		}
	}
	return os;
}


