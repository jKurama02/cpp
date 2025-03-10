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
////////////

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;


		Fixed operator + (const Fixed& obj) const;
		Fixed operator - (const Fixed& obj) const;
		Fixed operator / (const Fixed& obj) const;
		Fixed operator * (const Fixed& obj) const;

		Fixed& operator--();
		Fixed& operator++();

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);

		static Fixed const& max(Fixed const& a, Fixed const& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);

		~Fixed();
};
