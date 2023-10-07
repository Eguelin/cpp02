/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/07 19:40:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _raw_bits(0)
{
}

Fixed::Fixed( Fixed const &fixed )
{
	*this = fixed;
}

Fixed::Fixed( int const i )
{
	Fixed::_raw_bits = i << Fixed::_bits_fractional;
}

Fixed::Fixed( float const f )
{
	Fixed::_raw_bits = roundf(f * (1 << Fixed::_bits_fractional));
}

Fixed::~Fixed( void )
{
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

Fixed	&Fixed::min( Fixed &fixed_1, Fixed &fixed_2 )
{
	return (fixed_1 < fixed_2 ? fixed_1 : fixed_2);
}

Fixed const	&Fixed::min( Fixed const &fixed_1, Fixed const &fixed_2 )
{
	return (fixed_1 < fixed_2 ? fixed_1 : fixed_2);
}

Fixed	&Fixed::max( Fixed &fixed_1, Fixed &fixed_2 )
{
	return (fixed_1 > fixed_2 ? fixed_1 : fixed_2);
}

Fixed const	&Fixed::max( Fixed const &fixed_1, Fixed const &fixed_2 )
{
	return (fixed_1 > fixed_2 ? fixed_1 : fixed_2);
}

Fixed	&Fixed::operator=( Fixed const &fixed)
{
	Fixed::_raw_bits = fixed.getRawBits();

	return (*this);
}

int	Fixed::operator>( Fixed const &fixed ) const
{
	return (Fixed::toFloat() > fixed.toFloat());
}

int	Fixed::operator<( Fixed const &fixed ) const
{
	return (Fixed::toFloat() < fixed.toFloat());
}

int	Fixed::operator>=( Fixed const &fixed ) const
{
	return (Fixed::toFloat() >= fixed.toFloat());
}

int	Fixed::operator<=( Fixed const &fixed ) const
{
	return (Fixed::toFloat() <= fixed.toFloat());
}

int	Fixed::operator==( Fixed const &fixed ) const
{
	return (Fixed::_raw_bits == fixed.getRawBits());
}

int	Fixed::operator!=( Fixed const &fixed ) const
{
	return (Fixed::_raw_bits != fixed.getRawBits());
}

Fixed	Fixed::operator+( Fixed const &fixed ) const
{
	return (Fixed::toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-( Fixed const &fixed ) const
{
	return (Fixed::toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*( Fixed const &fixed ) const
{
	return (Fixed::toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/( Fixed const &fixed ) const
{
	return (Fixed::toFloat() / fixed.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	Fixed::_raw_bits++;

	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	Fixed::_raw_bits++;

	return (tmp);
}

Fixed	&Fixed::operator--( void)
{
	Fixed::_raw_bits--;

	return (*this);
}

Fixed	Fixed::operator--( int	)
{
	Fixed	tmp(*this);

	Fixed::_raw_bits--;

	return (tmp);
}

std::ostream	&operator<<( std::ostream &o, Fixed const &fixed )
{
	o << fixed.toFloat();

	return (o);
}

