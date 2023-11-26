/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/26 17:03:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:

		Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed( const int i );
		Fixed( const float f );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

		Fixed	&operator=( const Fixed &fixed );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &fixed_1, Fixed &fixed_2 );
		static const Fixed	&min( const Fixed &fixed_1, const Fixed &fixed_2 );
		static Fixed		&max( Fixed &fixed_1, Fixed &fixed_2 );
		static const Fixed	&max( const Fixed &fixed_1, const Fixed &fixed_2 );

		int		operator>( const Fixed &fixed ) const;
		int		operator<( const Fixed &fixed ) const;
		int		operator>=( const Fixed &fixed ) const;
		int		operator<=( const Fixed &fixed ) const;
		int		operator==( const Fixed &fixed ) const;
		int		operator!=( const Fixed &fixed ) const;

		Fixed	operator+( const Fixed &fixed ) const;
		Fixed	operator-( const Fixed &fixed ) const;
		Fixed	operator*( const Fixed &fixed ) const;
		Fixed	operator/( const Fixed &fixed ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int	);

	private:

		int					_raw_bits;
		const static int	_bits_fractional = 8;
};

std::ostream	&operator<<( std::ostream &o, const Fixed &fixed );

#endif
