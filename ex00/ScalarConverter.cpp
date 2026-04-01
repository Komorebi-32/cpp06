/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:26:37 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/01 15:16:28 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    if (this != &copy) {
        // copy data members here
    }
    return (*this);
}

static long unsigned int get_single_char_index(std::string input, char to_find)
{
    long unsigned int find = input.find(to_find);

    if ((find == input.rfind(to_find)) && find != std::string::npos)
        return (find);
    else
        return (0);
}

static bool input_is_an_int(const std::string &input, long unsigned int *start)
{
    if (*start == input.length())
        return (false);
    if (input.find_first_not_of("0123456789", *start) == std::string::npos)
        return (true);
    return (false);
}

static bool input_is_a_double(const std::string &input, long unsigned int *start, long unsigned int *point_index)
{
    if (input.find_first_not_of("0123456789", *start) == *point_index)
        *start = *point_index + 1;
    else
        return (false);
    if (input.find_first_not_of("0123456789", *start) == std::string::npos)
        return (true);
    else
        return (false);
}

static bool input_is_a_float(const std::string &input, long unsigned int *start)
{
    if (get_single_char_index(input, 'f') != input.size() - 1)
        return (std::cout << "f not good place\n", false);
    if (input.find_first_not_of("0123456789", *start) == input.size() - 1)
        return (true);
    else
        return (false);
}

static e_type determine_type(const std::string &input)
{
    long unsigned int point_index = 0;
    long unsigned int start = 0;


    if (input.empty())
        return (INVALID);
    if (!input.compare("-inff") || !input.compare("inff") || !input.compare("-inf")
        || !input.compare("+inf") || !input.compare("nanf") || !input.compare("nan"))
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
    
    if (input_is_a_double(input, &start, &point_index))
        return (DOUBLE);
    if (input_is_a_float(input, &start))
        return (FLOAT);
    return (INVALID);
}

void  ScalarConverter::convert(const std::string &input)
{
    e_type type;

    type = determine_type(input);
    switch (type)
    {
        case CHAR:
            std::cout << "char" << std::endl;
            break;
        case INT:
            std::cout << "int" << std::endl;
            break;
        case FLOAT:
            std::cout << "float" << std::endl;
            break;
        case DOUBLE:
            std::cout << "double" << std::endl;
            break;
        case SPECIAL:
            std::cout << "special" << std::endl;
            break;
        case INVALID:
            std::cout << "invalid" << std::endl;
            break;
    }
}