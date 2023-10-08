/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:55:31 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/08 15:24:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point	a(-1, 2);
	Point	b(-1, -2);
	Point	c(1 , 0);
	Point	point(0 , 0.9f);

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "Point = " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is in triangle ABC." << std::endl;
	else
		std::cout << "The point is not in triangle ABC." << std::endl;
	return 0;
}
