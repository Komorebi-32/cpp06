/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:12:11 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/06 17:48:53 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

class Base {
public:

   virtual ~Base(void);
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // BASE_HPP