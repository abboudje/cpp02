/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:44:07 by abboudje          #+#    #+#             */
/*   Updated: 2025/06/16 07:41:45 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed const& f)
{
    int raw = f.getRawBits();
    if (raw < 0)
        raw = -raw;
    Fixed result;
    result.setRawBits(raw);
    return result;
}

static Fixed area(Point const a, Point const b, Point const c)
{
    float value = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
                 + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
                 + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;
    Fixed result(value);
    return abs(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    return (A1.getRawBits() > 0 && A2.getRawBits() > 0 && A3.getRawBits() > 0
         && A.getRawBits() == (A1 + A2 + A3).getRawBits());
}