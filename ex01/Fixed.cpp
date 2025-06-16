/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 02:17:54 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 04:23:51 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;
Fixed::Fixed(): _value(0)
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << RED << "Copy assignment operator called" << RESET << std::endl;
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
    std::cout << MAGENTA << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << BOLD << "getRawBits member function called" <<  RESET << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	    std::cout << BOLD <<  "setRawBits member function called" << RESET << std::endl;
		this->_value = raw;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
    this->_value = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
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
