/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:57:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 13:50:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"
# define BLUE_T "\033[34m"

class Fixed
{
	public:

		Fixed( void );
		Fixed( Fixed &fixed );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

		Fixed	&operator=( const Fixed &fixed );

	private:

		int					_raw_bits;
		const static int	_bits_fractional = 8;
};

#endif
