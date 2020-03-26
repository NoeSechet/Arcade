/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centiped
*/

#include "Centiped.hpp"

namespace games {

    Centiped::Centiped()
    {

    }

    Centiped::~Centiped()
    {

    }

    bool Centiped::start()
    {
        return true;
    }

    bool Centiped::end()
    {
        return true;
    }

    std::vector <IObjectToDraw *> Centiped::getAssets() const
    {
        return m_objectToDraw;
    }

    COMMAND Centiped::applyInput (COMMAND userInput)
    {
        (void)userInput;
        return NO_INPUT;
    }

    std::vector <IObjectToDraw *> Centiped::compute()
    {
        return m_objectToDraw;
    }

    extern "C" {
        IGameInterface *entryPoint()
        {
            return new Centiped;
        }
    }
}