/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/05 19:08:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Fixed::Fixed( void ): _raw_bits(0)
{
}

Fixed::Fixed( const Fixed &fixed )
{
	*this = fixed;
}

Fixed::Fixed( const int i )
{
	this->_raw_bits = i << this->_bits_fractional;
}

Fixed::Fixed( const float f )
{
	this->_raw_bits = roundf(f * (1 << this->_bits_fractional));
}

Fixed::~Fixed( void )
{
}

/* ************************************************************************** */
/*                              Getters & Setters                             */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const {return (this->_raw_bits);}

void	Fixed::setRawBits( const int raw ) {this->_raw_bits = raw;}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Fixed	&Fixed::operator=( const Fixed &fixed )
{
	this->_raw_bits = fixed.getRawBits();

	return (*this);
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

float	Fixed::toFloat( void ) const
{
	return (float(this->_raw_bits) / (1 << this->_bits_fractional));
}

int	Fixed::toInt( void ) const
{
	return (this->_raw_bits >> this->_bits_fractional);
}

/* ************************************************************************** */
/*                           Static member functions                          */
/* ************************************************************************** */

Fixed	&Fixed::min( Fixed &fixed_1, Fixed &fixed_2 )
{
	return (fixed_1 < fixed_2 ? fixed_1 : fixed_2);
}

const Fixed	&Fixed::min( const Fixed &fixed_1, const Fixed &fixed_2 )
{
	return (fixed_1 < fixed_2 ? fixed_1 : fixed_2);
}

Fixed	&Fixed::max( Fixed &fixed_1, Fixed &fixed_2 )
{
	return (fixed_1 > fixed_2 ? fixed_1 : fixed_2);
}

const Fixed	&Fixed::max( const Fixed &fixed_1, const Fixed &fixed_2 )
{
	return (fixed_1 > fixed_2 ? fixed_1 : fixed_2);
}

/* ************************************************************************** */
/*                           Comparison overloading                           */
/* ************************************************************************** */

int	Fixed::operator>( const Fixed &fixed ) const
{
	return (this->_raw_bits > fixed._raw_bits);
}

int	Fixed::operator<( const Fixed &fixed ) const
{
	return (this->_raw_bits < fixed._raw_bits);
}

int	Fixed::operator>=( const Fixed &fixed ) const
{
	return (this->_raw_bits >= fixed._raw_bits);
}

int	Fixed::operator<=( const Fixed &fixed ) const
{
	return (this->_raw_bits <= fixed._raw_bits);
}

int	Fixed::operator==( const Fixed &fixed ) const
{
	return (this->_raw_bits == fixed._raw_bits);
}

int	Fixed::operator!=( const Fixed &fixed ) const
{
	return (this->_raw_bits != fixed._raw_bits);
}

/* ************************************************************************** */
/*                           Arithmetic overloading                           */
/* ************************************************************************** */

Fixed	Fixed::operator+( const Fixed &fixed ) const
{
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-( const Fixed &fixed ) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*( const Fixed &fixed ) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/( const Fixed &fixed ) const
{
	return (this->toFloat() / fixed.toFloat());
}

/* ************************************************************************** */
/*                           Increment overloading                            */
/* ************************************************************************** */

Fixed	&Fixed::operator++( void )
{
	this->_raw_bits++;

	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_raw_bits++;

	return (tmp);
}

Fixed	&Fixed::operator--( void )
{
	this->_raw_bits--;

	return (*this);
}

Fixed	Fixed::operator--( int	)
{
	Fixed	tmp(*this);

	this->_raw_bits--;

	return (tmp);
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Fixed &fixed )
{
	o << fixed.toFloat();

	return (o);
}
