/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/24 19:02:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET_T "\033[0m"
# define RED_T "\033[0;31m"
# define GREEN_T "\033[0;32m"

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

	private:

		int					_raw_bits;
		static const int	_bits_fractional = 8;
};

std::ostream	&operator<<( std::ostream &o, const Fixed &fixed );

#endif
