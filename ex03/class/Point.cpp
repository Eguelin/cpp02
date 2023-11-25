/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/25 16:12:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Point::Point( void ): _x(Fixed()), _y(Fixed())
{
}

Point::Point( const Point &point )
{
	*this = point;
}

Point::Point( const int x, const int y ): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( const float x, const float y ): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( const int x, const float y ): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( const float x, const int y ): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( const int x, const Fixed &y ): _x(Fixed(x)), _y(y)
{
}

Point::Point( const float x, const Fixed &y ): _x(Fixed(x)), _y(y)
{
}

Point::Point( const Fixed &x, const int y ): _x(x), _y(Fixed(y))
{
}

Point::Point( const Fixed &x, const float y ): _x(x), _y(Fixed(y))
{
}

Point::Point( const Fixed &x, const Fixed &y ): _x(x), _y(y)
{
}

Point::~Point( void )
{
}

/* ************************************************************************** */
/*                             Getters & Setters x                            */
/* ************************************************************************** */

const Fixed	&Point::get_x( void ) const {return(this->_x);}

void	Point::set_x( const int x ) {this->_x = Fixed(x);}

void	Point::set_x( const float x ) {this->_x = Fixed(x);}

void	Point::set_x( const Fixed &x ) {this->_x = x;}

/* ************************************************************************** */
/*                             Getters & Setters y                            */
/* ************************************************************************** */

const Fixed	&Point::get_y( void ) const {return(this->_y);}

void	Point::set_y( const int y ) {this->_y = Fixed(y);}

void	Point::set_y( const float y ) {this->_y = Fixed(y);}

void	Point::set_y( const Fixed &y ) {this->_y = y;}

/* ************************************************************************** */
/*                            Operator overloading                            */
/* ************************************************************************** */

Point	&Point::operator=( const Point &point )
{
	this->_x = point.get_x();
	this->_y = point.get_y();

	return (*this);
}

Point	Point::operator-( const Point &point ) const
{
	Point	tmp;

	tmp.set_x(this->_x - point.get_x());
	tmp.set_y(this->_y - point.get_y());

	return (tmp);
}

Fixed	Point::operator*( const Point &point ) const
{
	return (this->_x * point.get_y()) - (this->_y * point.get_x());
}

/* ************************************************************************** */
/*                              Print overloading                             */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Point &point )
{
	o << "(" << point.get_x() << ", " << point.get_y() << ")";

	return (o);
}
