/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:27:06 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/13 03:42:25 by sshahary         ###   ########.fr       */
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

	// Constructor that takes an integer
	Fixed(int const value);

	// Constructor that takes a float
	Fixed(float const value);

	// Copy constructor
	Fixed(const Fixed& other);

	// Copy assignment operator
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP
