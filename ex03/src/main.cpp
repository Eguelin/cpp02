/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:55:31 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 13:50:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define DEFAULT_T "\033[0m"
#define GREEN_T "\033[32m"
#define RED_T "\033[31m"

int main( void )
{
	Point	a(-1, Fixed(2));
	Point	b(-1, -2);
	Point	c(1 , 0);
	Point	point(0 , 0.9f);

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "Point = " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << GREEN_T << "The point is in triangle ABC." << DEFAULT_T << std::endl;
	else
		std::cout << RED_T << "The point is not in triangle ABC." << DEFAULT_T << std::endl;
	return (0);
}
