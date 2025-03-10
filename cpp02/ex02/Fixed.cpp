#include "Fixed.hpp"

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return os;
};

float Fixed::toFloat( void ) const
{
	// hai necessita'di ~castare~ il _value perche altrimenti no otterai mai un float come return
	return (static_cast<float>(this->_value) / (1 << this->_fractionalBits));
};

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalBits);
}

Fixed ::Fixed(const int nume) : _value(nume << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
};

Fixed ::Fixed(const float nume) : _value(roundf(nume * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
};

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
};

int Fixed::getRawBits(void) const
{
	return this->_value;
};

////////////////////////////

bool Fixed::operator >(const Fixed& other) const
{
	return(this->_value > other._value);
}

bool Fixed::operator <(const Fixed& other) const
{
	return(this->_value < other._value);
}

bool Fixed::operator >= (const Fixed& other) const
{
	return(this->_value >= other._value);
}

bool Fixed::operator <= (const Fixed& other) const
{
	return(this->_value <= other._value);
}

bool Fixed::operator == (const Fixed& other) const
{
	return(this->_value == other._value);
}

bool Fixed::operator != (const Fixed& other) const
{
	return(this->_value != other._value);
}

////////////////////////

Fixed Fixed::operator + (const Fixed& obj) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + obj.getRawBits());
	return(res);
}

Fixed Fixed::operator - (const Fixed& obj) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - obj.getRawBits());
	return(res);
}

Fixed Fixed::operator*(Fixed const& obj) const
{
	Fixed result;
	result.setRawBits((this->_value * obj.getRawBits()) >> this->_fractionalBits);
	return (result);
}

Fixed Fixed::operator/(Fixed const& obj) const
{
	Fixed result;
	result.setRawBits((this->_value << this->_fractionalBits) / obj.getRawBits());
	return (result);
}


Fixed& Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
		return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return(a < b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return (a > b ? a : b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	return (a < b ? a : b);
}
