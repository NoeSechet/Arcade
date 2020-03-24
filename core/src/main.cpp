/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** MAIN
*/

#include <iostream>

#include "Core.hpp"

int print_usage()
{
    std::cout << "Usage: ./arcade ./[path to graphical shared library module]" << std::endl;
    return 84;
}

int main(int ac, const char *av[])
{
    if (ac != 2)
        return print_usage();
    try {
        Core core(av[1]);
        core.loop();
    } catch(std::logic_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}