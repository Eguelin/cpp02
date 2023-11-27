/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:56:50 by eguelin          ###   ########lyon.fr   */
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

const Fixed	&Point::getX( void ) const {return(this->_x);}

void	Point::setX( const int x ) {this->_x = Fixed(x);}

void	Point::setX( const float x ) {this->_x = Fixed(x);}

void	Point::setX( const Fixed &x ) {this->_x = x;}

/* ************************************************************************** */
/*                             Getters & Setters y                            */
/* ************************************************************************** */

const Fixed	&Point::getY( void ) const {return(this->_y);}

void	Point::setY( const int y ) {this->_y = Fixed(y);}

void	Point::setY( const float y ) {this->_y = Fixed(y);}

void	Point::setY( const Fixed &y ) {this->_y = y;}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Point	&Point::operator=( const Point &point )
{
	this->_x = point.getX();
	this->_y = point.getY();

	return (*this);
}

Point	Point::operator-( const Point &point ) const
{
	Point	tmp;

	tmp.setX(this->_x - point.getX());
	tmp.setY(this->_y - point.getY());

	return (tmp);
}

Fixed	Point::operator*( const Point &point ) const
{
	return (this->_x * point.getY()) - (this->_y * point.getX());
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Point &point )
{
	o << "(" << point.getX() << ", " << point.getY() << ")";

	return (o);
}
