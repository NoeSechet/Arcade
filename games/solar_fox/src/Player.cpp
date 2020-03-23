/*
** EPITECH PROJECT, 2020
** PLAYER
** File description:
** PLAYER
*/

#include "Entities.hpp"

Player::Player(std::pair <long int, long int> coord, std::string id, std::string path)
: Entity(coord, id, path)
{
    m_timer.startTimer();
}

Player::~Player()
{}

std::string Player::getId() const
{
    return m_id;
}

IObjectToDraw::Type Player::getType() const
{
    return objects;
}

std::string Player::getValue() const
{
    return "";
}

void Player::setPlayerDirection(COMMAND d_direction)
{
    m_direction = d_direction;

    switch (d_direction) {
    case UP: m_id = "player_up"; break;
    case DOWN: m_id = "player_down"; break;
    case LEFT: m_id = "player_left"; break;
    case RIGHT: m_id = "player_right"; break;
    default: break;
    }
}


void Player::move(void)
{
    if (m_timer.getElapsedSeconds() < 0.2) return;
    m_timer.restartTimer();
    switch (m_direction) {
    case RIGHT: m_coord.first += 1; break;
    case LEFT: m_coord.first -= 1; break;
    case DOWN: m_coord.second += 1; break;
    case UP: m_coord.second -= 1; break;
    default: break;
    }
}

void Player::action(std::vector <IObjectToDraw *> &objects)
{
    (void)objects;
}

void Player::impact(std::vector <IObjectToDraw *> &objects)
{
    (void)objects;
}