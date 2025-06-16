/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 02:17:54 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 07:35:04 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;
Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
		this->_value = raw;
}

Fixed::Fixed(const int n)
{
    this->_value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    this->_value = roundf(f * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float) this->_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const 
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const 
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_value != other._value;
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    if (other._value == 0)
	{
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{  
    this->_value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value += 1;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}