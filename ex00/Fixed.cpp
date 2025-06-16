/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 02:17:54 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 02:35:15 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
		this->_value = other.getRawBits();
	}
	return (*this);
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
