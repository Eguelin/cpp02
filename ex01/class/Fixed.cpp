/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 16:00:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Fixed::Fixed( void ): _raw_bits(0)
{
	std::cout << GREEN_T << "Default constructor called" << RESET_T << std::endl;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << GREEN_T << "Copy constructor called" << RESET_T << std::endl;

	*this = fixed;
}

Fixed::Fixed( const int i )
{
	std::cout << GREEN_T << "Int constructor called" << RESET_T << std::endl;

	this->_raw_bits = i << this->_bits_fractional;
}

Fixed::Fixed( const float f )
{
	std::cout << GREEN_T << "Float constructor called" << RESET_T << std::endl;

	this->_raw_bits = roundf(f * (1 << this->_bits_fractional));
}

Fixed::~Fixed( void )
{
	std::cout << RED_T << "Destructor called" << RESET_T << std::endl;
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
	std::cout << GREEN_T << "Copy assignment operator called" << RESET_T << std::endl;

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
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Fixed &fixed )
{
	o << fixed.toFloat();

	return (o);
}
