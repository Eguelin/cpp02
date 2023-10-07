/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/07 19:37:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (Fixed::_raw_bits);
}

void	Fixed::setRawBits( int const raw )
{
	Fixed::_raw_bits = raw;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_raw_bits = fixed.getRawBits();

	return (*this);
}
