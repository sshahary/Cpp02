/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:53:31 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/12 01:54:46 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

	private:
	int _value;
	static const int _fractionalBits = 8;

	public:
	// Default constructor
		Fixed();

	// Copy constructor
		Fixed(const Fixed& other);

	// Copy assignment operator
		Fixed& operator=(const Fixed& other);

	// Destructor
		~Fixed();

	// Member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif