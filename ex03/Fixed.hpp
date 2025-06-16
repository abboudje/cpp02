/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 01:39:22 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 07:39:23 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>


#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"

class Fixed
{
	private:
		int	_value;
		static const int _fractionalBits;
		
	public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int n);
	Fixed(const float n);
	float toFloat(void) const;
	int toInt(void) const;
	~Fixed();
	int 	getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed&	operator=(const Fixed& other);
	// Opérateurs de comparaison
	bool operator>(const Fixed &other) const;
    	bool operator<(const Fixed &other) const;
    	bool operator>=(const Fixed &other) const;
    	bool operator<=(const Fixed &other) const;
    	bool operator==(const Fixed &other) const;
    	bool operator!=(const Fixed &other) const;
		// Opérateurs arithmétiques
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		// Incrémentation / décrémentation
		Fixed &operator++();
		Fixed operator++(int);
    	Fixed &operator--();
    	Fixed operator--(int);
		// Méthodes statiques min/max
    	static Fixed &min(Fixed &a, Fixed &b);
    	static const Fixed &min(const Fixed &a, const Fixed &b);
    	static Fixed &max(Fixed &a, Fixed &b);
    	static const Fixed &max(const Fixed &a, const Fixed &b);
	};
std::ostream& operator<<(std::ostream& os, const Fixed& f);
