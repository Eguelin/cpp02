/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:55:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	public:

		Point( void );
		Point( const Point &point );
		Point( const int x, const int y );
		Point( const float x, const float y );
		Point( const int x, const float y );
		Point( const float x, const int y );
		Point( const int x, const Fixed &y );
		Point( const float x, const Fixed &y );
		Point( const Fixed &x, const int y );
		Point( const Fixed &x, const float y );
		Point( const Fixed &x, const Fixed &y );
		~Point( void );

		const Fixed	&getX( void ) const;
		void		setX( const int x );
		void		setX( const float x );
		void		setX( const Fixed &x );

		const Fixed	&getY( void ) const;
		void		setY( const int y );
		void		setY( const float y );
		void		setY( const Fixed &y );

		Point	&operator=( const Point &point );

		Point	operator-( const Point &point ) const;
		Fixed	operator*( const Point &point ) const;

	private:

		Fixed	_x;
		Fixed	_y;
};

std::ostream	&operator<<( std::ostream &o, const Point &point );

bool	bsp( const Point a, const Point b, const Point c, const Point point );

#endif
