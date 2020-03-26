/*
** EPITECH PROJECT, 2020
** MONSTER
** File description:
** MONSTER
*/

#include "Entities.hpp"

Monster::Monster(std::pair <long int, long int> coord, std::pair <long int, long int> movementFactor, std::string id, std::string path)
: Entity(coord, id, path)
{
    m_timerShoot.startTimer();
    m_timerMove.startTimer();
    m_movementFactor = movementFactor;
}

Monster::~Monster()
{

}

void Monster::setDirectionLazer(COMMAND direction)
{
    m_directionLazer = direction;
}

std::string Monster::getId() const
{
    return m_id;
}

IObjectToDraw::Type Monster::getType() const
{
    return objects;
}

std::string Monster::getValue() const
{
    return "";
}


void Monster::move(void)
{
    if (m_timerMove.getElapsedSeconds() < 0.5) return;
    m_timerMove.restartTimer();
    m_coord.first += m_movementFactor.first;
    m_coord.second += m_movementFactor.second;
}

void Monster::action(std::vector <IObjectToDraw *> &objects)
{
    if (m_timerShoot.getElapsedSeconds() < 1) return;
    m_timerShoot.restartTimer();
    switch (m_directionLazer) {
        case RIGHT: objects.push_back(new Lazer(this->m_coord, std::make_pair(1, 0), Lazer::O_MONSTER)); break;
        case LEFT: objects.push_back(new Lazer(this->m_coord, std::make_pair(-1, 0), Lazer::O_MONSTER)); break;
        case DOWN: objects.push_back(new Lazer(this->m_coord, std::make_pair(0, 1), Lazer::O_MONSTER)); break;
        case UP: objects.push_back(new Lazer(this->m_coord, std::make_pair(0, -1), Lazer::O_MONSTER)); break;
        default: break;
    }
}

void Monster::impact(std::vector <IObjectToDraw *> &objects)
{
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i] == this)
            continue;
        if (static_cast <Entity *> (objects[i])->getCoords().first == m_coord.first + m_movementFactor.first &&
            static_cast <Entity *> (objects[i])->getCoords().second == m_coord.second + m_movementFactor.second &&
            objects[i]->getId().compare("border") == 0)
                    reverseMovementFactor();
    }
}

void Monster::reverseMovementFactor(void)
{
    if (m_movementFactor.first == 0) {
        m_movementFactor.second = m_movementFactor.second * (-1);
    } else
        m_movementFactor.first = m_movementFactor.first * (-1);
}
