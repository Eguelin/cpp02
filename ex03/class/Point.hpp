/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/05 15:29:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:

		Point( void );
		Point( const Point &point );
		Point( const float x, const float y );
		~Point( void );

		const Fixed	&getX( void ) const;
		const Fixed	&getY( void ) const;

		Point	&operator=( const Point &point );

		Point	operator-( const Point &point ) const;
		Fixed	operator*( const Point &point ) const;

	private:

		const Fixed	_x;
		const Fixed	_y;
};

std::ostream	&operator<<( std::ostream &o, const Point &point );

bool	bsp( const Point &a, const Point &b, const Point &c, const Point &point );

#endif
