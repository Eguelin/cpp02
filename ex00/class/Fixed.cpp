/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:48 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 13:50:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Fixed::Fixed( void ): _raw_bits(0)
{
	std::cout << GREEN_T << "Default constructor called" << DEFAULT_T << std::endl;
}

Fixed::Fixed( Fixed &fixed )
{
	std::cout << GREEN_T << "Copy constructor called" << DEFAULT_T << std::endl;

	*this = fixed;
}

Fixed::~Fixed( void )
{
	std::cout << RED_T << "Destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Getters & Setters                             */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const
{
	std::cout << BLUE_T << "getRawBits member function called" << DEFAULT_T << std::endl;

	return (this->_raw_bits);
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << BLUE_T << "setRawBits member function called" << DEFAULT_T << std::endl;

	this->_raw_bits = raw;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Fixed	&Fixed::operator=( const Fixed &fixed )
{
	std::cout << GREEN_T << "Copy assignment operator called" << DEFAULT_T << std::endl;

	this->_raw_bits = fixed.getRawBits();

	return (*this);
}
