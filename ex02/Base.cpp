/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:11:18 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/19 16:24:36 by bkaras-g         ###   ########.fr       */
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
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
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

void identify(Base* p)
{
    std::cout << "type of the object pointed to by p: ";
    A* a_ptr = dynamic_cast<A *>(p);
    if (a_ptr)
    {
        std::cout << "A" << std::endl;
        return ;
    }
    B* b_ptr = dynamic_cast<B *>(p);
    if (b_ptr)
    {
        std::cout << "B" << std::endl;
        return ;
    }
    C* c_ptr = dynamic_cast<C *>(p);
    if (c_ptr)
    {
        std::cout << "C" << std::endl;
        return ;
    }
}
