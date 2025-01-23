/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:55:31 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 18:28:28 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed		a;
	const Fixed	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << Fixed (5).getRawBits() << " " << Fixed (2).getRawBits() << " " << (Fixed (5) / Fixed(2)) << std::endl;
	std::cout << Fixed (4194304).getRawBits() << " " << Fixed (1.9f).getRawBits() << " " << (Fixed (4194304) * Fixed(1.9f)) << std::endl;

	return (0);
}
