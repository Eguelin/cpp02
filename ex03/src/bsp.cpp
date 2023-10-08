/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:05:40 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/08 15:20:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	VP1 = ((b - a) * (point - a));
	Fixed	VP2 = ((c - b) * (point - b));
	Fixed	VP3 = ((a - c) * (point - c));

	if ((VP1 > 0 && VP2 > 0 && VP3 > 0) || (VP1 < 0 && VP2 < 0 && VP3 < 0))
		return (true);
	return (false);
}
