#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;
	public:

		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int num);
		Fixed(const float num);

		float toFloat( void ) const;
		// float Fixed::toFloat(void) const

		int toInt(void) const;
		// int Fixed::toInt(void) const

		Fixed &operator=(const Fixed &other);

		void setRawBits(int const raw);
		int getRawBits()const;

		friend std::ostream& operator<<(std::ostream& os, const Fixed& palle);

		~Fixed();
};
