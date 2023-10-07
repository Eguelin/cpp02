/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/07 19:39:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	private:

		int					_raw_bits;
		static int const	_bits_fractional = 8;

	public:

		Fixed( void );
		Fixed( Fixed const &fixed );
		Fixed( int const i );
		Fixed( float const f );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &fixed_1, Fixed &fixed_2 );
		static Fixed const	&min( Fixed const &fixed_1, Fixed const &fixed_2 );
		static Fixed		&max( Fixed &fixed_1, Fixed &fixed_2 );
		static Fixed const	&max( Fixed const &fixed_1, Fixed const &fixed_2 );

		Fixed	&operator=( Fixed const &fixed );

		int		operator>( Fixed const &fixed ) const;
		int		operator<( Fixed const &fixed ) const;
		int		operator>=( Fixed const &fixed ) const;
		int		operator<=( Fixed const &fixed ) const;
		int		operator==( Fixed const &fixed ) const;
		int		operator!=( Fixed const &fixed ) const;

		Fixed	operator+( Fixed const &fixed ) const;
		Fixed	operator-( Fixed const &fixed ) const;
		Fixed	operator*( Fixed const &fixed ) const;
		Fixed	operator/( Fixed const &fixed ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void);
		Fixed	operator--( int	);
};

std::ostream	&operator<<( std::ostream &o, Fixed const &fixed );

#endif
