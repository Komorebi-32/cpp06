/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:41:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/04/06 17:52:29 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main (void)
{
    std::srand(std::time(0)); //seeding a nice plant

    Base *simple_basique = generate();
    identify(simple_basique);
    return (0);
}