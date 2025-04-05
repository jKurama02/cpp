#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

template <typename T>

void swap(T &a, T &b)
{
	T tmpa = a;
	a = b;
	b = tmpa;
};

template<typename T>
T max(T a, T b)
{
	if(a > b)
		return a;
	else
		return b;
}

template<typename T>
T min(T a,T b)
{
	if(a > b)
		return b;
	else
		return a;
}
