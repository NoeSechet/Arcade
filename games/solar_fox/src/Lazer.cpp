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