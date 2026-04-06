/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:34:06 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/06 16:50:11 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer(void)
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& copy)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = copy;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
    std::cout << "Serializer assignment operator called" << std::endl;
    if (this != &copy) {
        // copy data members here
    }
    return (*this);
}

//  static uintptr_t serialize(Data* ptr);
//     static Data* deserialize(uintptr_t raw);

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
