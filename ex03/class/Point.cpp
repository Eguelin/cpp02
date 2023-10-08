/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:26 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/08 15:00:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(Fixed()), _y(Fixed())
{
}

Point::Point( Point const &point )
{
	Point::_x = point.get_x();
	Point::_y = point.get_y();
}

Point::Point( int const x, int const y )
{
	Point::_x = Fixed(x);
	Point::_y = Fixed(y);
}

Point::Point( float const x, float const y )
{
	Point::_x = Fixed(x);
	Point::_y = Fixed(y);
}

Point::Point( int const x, float const y )
{
	Point::_x = Fixed(x);
	Point::_y = Fixed(y);
}

Point::Point( float const x, int const y )
{
	Point::_x = Fixed(x);
	Point::_y = Fixed(y);
}

Point::Point( int const x, Fixed const &y )
{
	Point::_x = Fixed(x);
	Point::_y = y;
}

Point::Point( float const x, Fixed const &y )
{
	Point::_x = Fixed(x);
	Point::_y = y;
}

Point::Point( Fixed const &x, int const y )
{
	Point::_x = x;
	Point::_y = Fixed(y);
}

Point::Point( Fixed const &x, float const y )
{
	Point::_x = x;
	Point::_y = Fixed(y);
}

Point::Point( Fixed const &x, Fixed const &y )
{
	Point::_x = x;
	Point::_y = y;
}

Point::~Point( void )
{
}

Fixed	Point::get_x( void ) const
{
	return(Point::_x);
}

void	Point::set_x( int const x )
{
	Point::_x = Fixed(x);
}

void	Point::set_x( float const x )
{
	Point::_x = Fixed(x);
}

void	Point::set_x( Fixed const &x )
{
	Point::_x = x;
}

Fixed	Point::get_y( void ) const
{
	return(Point::_y);
}

void	Point::set_y( int const y )
{
	Point::_y = Fixed(y);
}

void	Point::set_y( float const y )
{
	Point::_y = Fixed(y);
}

void	Point::set_y( Fixed const &y )
{
	Point::_y = y;
}

Point	&Point::operator=( Point const &point )
{
	Point::_x = point.get_x();
	Point::_y = point.get_y();

	return (*this);
}

Point	Point::operator-( Point const &point ) const
{
	Point	tmp;

	tmp.set_x(Point::_x - point.get_x());
	tmp.set_y(Point::_y - point.get_y());

	return (tmp);
}

Fixed	Point::operator*( Point const &point ) const
{
	return (Point::_x * point.get_y()) - (Point::_y * point.get_x());
}

std::ostream	&operator<<( std::ostream &o, Point const &point )
{
	o << "(" << point.get_x() << ", " << point.get_y() << ")";

	return (o);
}
