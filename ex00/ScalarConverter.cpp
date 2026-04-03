/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:26:37 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/03 16:23:40 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this != &copy)
	{
		// copy data members here
	}
	return (*this);
}

static long unsigned int	get_single_char_index(std::string input,
		char to_find)
{
	long unsigned int	find;

	find = input.find(to_find);
	if ((find == input.rfind(to_find)) && find != std::string::npos)
		return (find);
	else
		return (0);
}

static bool	input_is_an_int(const std::string &input, long unsigned int *start)
{
	if (*start == input.length())
		return (false);
	if (input.find_first_not_of("0123456789", *start) == std::string::npos)
		return (true);
	return (false);
}

// static bool	input_is_a_double(const std::string &input,
// 		long unsigned int *start, long unsigned int *point_index)
// {
// 	if (input.find_first_not_of("0123456789", *start) == *point_index)
// 		*start = *point_index + 1;
// 	else
// 		return (false);
// 	if (input.find_first_not_of("0123456789", *start) == std::string::npos)
// 		return (true);
// 	else
// 		return (false);
// }

// static bool	input_is_a_float(const std::string &input,
		// long unsigned int *start)
// {
// 	if (get_single_char_index(input, 'f') != input.size() - 1)
// 		return (std::cout << "f not good place\n", false);
// 	if (input.find_first_not_of("0123456789", *start) == input.size() - 1)
// 		return (true);
// 	else
// 		return (false);
// }

static e_type	input_is_a_double_or_float(const std::string &input,
		long unsigned int *start, long unsigned int *point_index)
{
	// check if only digits before the '.'
	if (input.find_first_not_of("0123456789", *start) == *point_index)
		*start = *point_index + 1;
	else
		return (INVALID);
	// check if double
	if (input.find_first_not_of("0123456789", *start) == std::string::npos)
		return (DOUBLE);
	else // check if float
	{
		if (get_single_char_index(input, 'f') != input.size() - 1)
			return (std::cout << "f not good place\n", INVALID);
		if (input.find_first_not_of("0123456789", *start) == input.size() - 1)
			return (FLOAT);
		else
			return (INVALID);
	}
}

static e_type	determine_type(const std::string &input)
{
	long unsigned int	point_index;
	long unsigned int	start;

	point_index = 0;
	start = 0;
	if (input.empty())
		return (INVALID);
	if (!input.compare("-inff") || !input.compare("inff")
		|| !input.compare("-inf") || !input.compare("+inf")
		|| !input.compare("nanf") || !input.compare("nan"))
		return (SPECIAL);
	if (input.size() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	if (input[start] == '+' || input[start] == '-')
		start++;
	if (input_is_an_int(input, &start))
		return (INT);
	point_index = get_single_char_index(input, '.');
	if (point_index == 0 || point_index == input.size() - 1)
		return (INVALID);
	return (input_is_a_double_or_float(input, &start, &point_index));
}

void ScalarConverter::convert(const std::string &input)
{
	e_type type;

	type = determine_type(input);

	switch (type)
	{
	case CHAR:
	{
		char c = input[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1); // to print one decimal
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		break ;
	}
	case INT:
	{
		std::stringstream ss(input);
		int i;
		if (!(ss >> i))
			std::cout << "Warning: int overflow. Considering input == (+/-)INT_MAX." << std::endl;
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);

		if (i >= 0 && i <= 127 && std::isprint(i))
		{
			char c = i;
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else if (i > 127 || i < 0)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1); // to print one decimal
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		break ;
	}

	case FLOAT:
	{
		float f;
		int i;
		double d;

		f = std::strtof(input.c_str(), NULL);
		if (f >= INT_MIN && f <= INT_MAX)
			i = static_cast<float>(f);
		d = static_cast<double>(f);

		if (f >= 0 && f <= 127 && std::isprint(f))
		{
			char c = f;
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else if (f > 127 || f < 0)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (f >= INT_MIN && f <= INT_MAX)
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1); // to print one decimal
		std::cout << "float: "  << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;

		// std::cout << "float: " << std::strtof(input.c_str(), NULL) << "f" << std::endl;

		break ;
	}
	case DOUBLE:
	{
		std::stringstream ss(input);
		double d;
		if (!(ss >> d))
			std::cout << "Warning: double overflow. Considering input == (+/-)DBL_MAX." << std::endl;
		float f = static_cast<float>(d);
		int i = static_cast<int>(d);

		if (d >= 0 && d <= 127 && std::isprint(i))
		{
			char c = d;
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else if (d > 127 || d < 0)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (d >= INT_MIN && d <= INT_MAX)
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1); // to print one decimal
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		break ;
	}
	case SPECIAL:
		std::cout << "special" << std::endl;
		break ;
	case INVALID:
		std::cout << "invalid input" << std::endl;
		break ;
	}
}