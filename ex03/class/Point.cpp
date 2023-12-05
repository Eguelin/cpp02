/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/05 15:08:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Point::Point( void ): _x(Fixed()), _y(Fixed())
{
}

Point::Point( const Point &point ): _x(point._x), _y(point._y)
{
}

Point::Point( const float x, const float y ): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point( void )
{
}

/* ************************************************************************** */
/*                                  Getters                                   */
/* ************************************************************************** */

const Fixed	&Point::getX( void ) const {return(this->_x);}

const Fixed	&Point::getY( void ) const {return(this->_y);}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Point	&Point::operator=( const Point &point )
{
	(void)point;

	return (*this);
}

Point	Point::operator-( const Point &point ) const
{
	Point	tmp((this->_x - point._x).toFloat(), \
				(this->_y - point._y).toFloat());

	return (tmp);
}

Fixed	Point::operator*( const Point &point ) const
{
	return ((this->_x * point._y) - (this->_y * point._x));
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Point &point )
{
	o << "(" << point.getX() << ", " << point.getY() << ")";

	return (o);
}
