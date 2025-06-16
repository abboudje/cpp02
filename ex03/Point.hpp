/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:44:18 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 07:17:37 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include "Fixed.hpp"
class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
		
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point &operator=(const Point &other);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};