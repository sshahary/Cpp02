/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:36:29 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/13 03:36:32 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
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

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/decrement operators
    Fixed& operator++();       // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed& operator--();       // Pre-decrement
    Fixed operator--(int);     // Post-decrement

    // Static min/max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int _value;
    static const int _fractionalBits = 8;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_HPP

