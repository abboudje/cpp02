/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:44:14 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 07:10:02 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}
Point::Point(const float x, const float y): _x(x), _y(y){}
Point::Point(const Point &other) : _x(other._x), _y(other._y){}
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point(){}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}