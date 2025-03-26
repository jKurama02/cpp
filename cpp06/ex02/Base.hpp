#ifndef BASE_HPP
#define BASE_HPP
#include<string>
#include<iostream>
#include <cstdlib>
#include <ctime>
// #include"A.hpp"
// #include"B.hpp"
// #include"C.hpp"


class Base
{
	public:
		virtual ~Base(){};
		virtual std::string getTipe() const{
			return("default");
		};
};
class A : public Base {
	std::string getTipe() const  {return "A";};
};
class B : public Base {
	std::string getTipe()  const  {return "B";};
};
class C : public Base {
	std::string getTipe()  const  {return "C";};
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
