/*
** EPITECH PROJECT, 2020
** LAZER
** File description:
** LAZER
*/

#include "Entities.hpp"

Lazer::Lazer(std::pair <long int, long int> coord, std::pair <long int, long int> movementFactor, OWNER owner,  std::string id, std::string path)
: Entity(coord, id, path)
{
    m_timer.startTimer();
    m_movementFactor = movementFactor;
    m_owner = owner;
    m_coord.first += movementFactor.first;
    m_coord.second += movementFactor.second;
}

Lazer::~Lazer()
{}

std::string Lazer::getId() const
{
    return m_id;
}

IObjectToDraw::Type Lazer::getType() const
{
    return objects;
}

std::string Lazer::getValue() const
{
    return "";
};

void Lazer::move(void)
{
    if (m_timer.getElapsedSeconds() < 0.05) return;
    m_timer.restartTimer();
    m_coord.first += m_movementFactor.first;
    m_coord.second += m_movementFactor.second;
}

void Lazer::impact(std::vector <IObjectToDraw *> &objects)
{
    // for (size_t i = 0; i < objects.size(); i++) {
    //     if (objects[i] == this)
    //         continue;
    //     if (static_cast <Entity *> (objects[i])->getCoords().first == m_coord.first &&
    //         static_cast <Entity *> (objects[i])->getCoords().second == m_coord.second)
    //             m_toClear = true;
    // }
}