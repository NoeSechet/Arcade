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

void Player::setCommand(COMMAND command)
{
    m_command = command;
}

void Player::setPlayerDirection()
{
    switch (m_command) {
        case UP: m_id = "player_up"; m_direction = UP; break;
        case DOWN: m_id = "player_down"; m_direction = DOWN; break;
        case LEFT: m_id = "player_left"; m_direction = LEFT; break;
        case RIGHT: m_id = "player_right"; m_direction = RIGHT; break;
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
    if (m_command != ACTION) return;
    switch (m_direction) {
        case RIGHT: objects.push_back(new Lazer(this->m_coord, std::make_pair(1, 0), Lazer::O_PLAYER)); break;
        case LEFT: objects.push_back(new Lazer(this->m_coord, std::make_pair(-1, 0), Lazer::O_PLAYER)); break;
        case DOWN: objects.push_back(new Lazer(this->m_coord, std::make_pair(0, 1), Lazer::O_PLAYER)); break;
        case UP: objects.push_back(new Lazer(this->m_coord, std::make_pair(0, -1), Lazer::O_PLAYER)); break;
        default: break;
    }
}

void Player::impact(std::vector <IObjectToDraw *> &objects)
{
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i] == this)
            continue;
        if (static_cast <Entity *> (objects[i])->getCoords().first == m_coord.first &&
            static_cast <Entity *> (objects[i])->getCoords().second == m_coord.second)
                m_toClear = true;
    }
}