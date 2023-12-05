/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:05:40 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/05 15:10:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( const Point &a, const Point &b, const Point &c, const Point &point )
{
	Fixed	VP1 = ((b - a) * (point - a));
	Fixed	VP2 = ((c - b) * (point - b));
	Fixed	VP3 = ((a - c) * (point - c));

	if ((VP1 > 0 && VP2 > 0 && VP3 > 0) || (VP1 < 0 && VP2 < 0 && VP3 < 0))
		return (true);
	return (false);
}
