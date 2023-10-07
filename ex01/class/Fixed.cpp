/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/07 19:37:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &fixed )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;
}

Fixed::Fixed( int const i )
{
	std::cout << "Int constructor called" << std::endl;

	Fixed::_raw_bits = i << Fixed::_bits_fractional;
}

Fixed::Fixed( float const f )
{
	std::cout << "Float constructor called" << std::endl;

	Fixed::_raw_bits = roundf(f * (1 << Fixed::_bits_fractional));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
int	Fixed::getRawBits( void ) const
{
	return (Fixed::_raw_bits);
}

void	Fixed::setRawBits( int const raw )
{
	Fixed::_raw_bits = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float(Fixed::_raw_bits) / (1 << Fixed::_bits_fractional));
}

int	Fixed::toInt( void ) const
{
	return (Fixed::_raw_bits >> Fixed::_bits_fractional);
}

Fixed	&Fixed::operator=( Fixed const &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;

	Fixed::_raw_bits = fixed.getRawBits();

	return (*this);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &fixed )
{
	o << fixed.toFloat();

	return (o);
}
