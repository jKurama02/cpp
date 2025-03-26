#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
//you need this | library to implemente uintptr_t variable
# include <stdint.h>
#include <iostream>
# include <cctype>


class Data;

class Serializer
{
	private:
		Serializer();
		Serializer& operator =(const Serializer& other);
		Serializer(const Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



#endif
