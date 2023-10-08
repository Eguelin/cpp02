/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:21:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/08 15:05:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:

		Fixed	_x;
		Fixed	_y;

	public:

		Point( void );
		Point( Point const &point );
		Point( int const x, int const y );
		Point( float const x, float const y );
		Point( int const x, float const y );
		Point( float const x, int const y );
		Point( int const x, Fixed const &y );
		Point( float const x, Fixed const &y );
		Point( Fixed const &x, int const y );
		Point( Fixed const &x, float const y );
		Point( Fixed const &x, Fixed const &y );
		~Point( void );

		Fixed	get_x( void ) const;
		void	set_x( int const x );
		void	set_x( float const x );
		void	set_x( Fixed const &x );

		Fixed	get_y( void ) const;
		void	set_y( int const y );
		void	set_y( float const y );
		void	set_y( Fixed const &y );

		Point	&operator=( Point const &point );

		Point	operator-( Point const &point ) const;
		Fixed	operator*( Point const &point ) const;
};

std::ostream	&operator<<( std::ostream &o, Point const &point );

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
