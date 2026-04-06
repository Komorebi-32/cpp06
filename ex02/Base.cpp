/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:11:18 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/06 17:42:27 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
    std::cout << "Base destructor called" << std::endl;
}

// Base *generate(void);
// void identify(Base* p);
// void identify(Base& p);

Base *generate(void)
{
    int i = std::rand() % 3;

    if (i == 0)
    {
        std::cout << "Generated A" << std::endl;
        return (new A());
    }
    else if (i == 1)
    {
        std::cout << "Generated B" << std::endl;
        return (new B());
    }
    else
    {
        std::cout << "Generated C" << std::endl;
        return (new C());
    }
}
