/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:11:18 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/19 17:06:04 by bkaras-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
    std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0)); //seeding a nice plant
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
    std::cout << "identify (Base* p) - type of the object pointed to by p: ";
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
    std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    std::cout << "identify (Base& p) - type of the object pointed to by p: ";
    try {
        A& a_ref = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void) a_ref;
        return ;
    }
    catch (std::exception &e){
        try {
            B& b_ref = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
            (void) b_ref;
            return ;
        }
        catch (std::exception &e){
            std::cout << "C" << std::endl;
        }
    }

}
