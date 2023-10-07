/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/07 19:39:10 by eguelin          ###   ########lyon.fr   */
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

		Fixed	&operator=( Fixed const &fixed );
};

std::ostream	&operator<<( std::ostream &o, Fixed const &fixed );

#endif
