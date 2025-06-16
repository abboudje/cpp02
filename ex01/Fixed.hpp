/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 01:39:22 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 04:13:19 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

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
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
};
std::ostream& operator<<(std::ostream& os, const Fixed& f);
