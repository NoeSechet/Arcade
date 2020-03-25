/*
** EPITECH PROJECT, 2020
** MONSTER
** File description:
** MONSTER
*/

#include "Entities.hpp"

Monster::Monster(std::pair <long int, long int> coord, std::string id, std::string path)
: Entity(coord, id, path)
{
    m_timerShoot.startTimer();
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
    (void)objects;
    // si le prochain il y a une collisione t si cette collision est un mur, si oui on toggle la direction

    // switch de movement factor;
}
