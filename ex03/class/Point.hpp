/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/25 15:47:39 by eguelin          ###   ########lyon.fr   */
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

		const Fixed	&get_x( void ) const;
		void		set_x( const int x );
		void		set_x( const float x );
		void		set_x( const Fixed &x );

		const Fixed	&get_y( void ) const;
		void		set_y( const int y );
		void		set_y( const float y );
		void		set_y( const Fixed &y );

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
