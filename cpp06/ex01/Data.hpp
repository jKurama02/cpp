#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	private:
		int i;
	public:
		Data();
		Data(int value);
		Data(const Data& other);
		Data& operator=(const Data& other);
};

#endif
