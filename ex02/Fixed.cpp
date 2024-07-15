/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:36:46 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/15 23:38:43 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor that takes an integer
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

// Constructor that takes a float
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		_value = other._value;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Member functions
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(toFloat() / other.toFloat());
}

// Increment/decrement operators
Fixed& Fixed::operator++() // Pre-increment
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--() { // Pre-decrement
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{ // Post-decrement
	Fixed temp(*this);
	_value--;
	return temp;
}

// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
