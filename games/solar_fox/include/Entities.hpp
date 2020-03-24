/*
** EPITECH PROJECT, 2020
** ENTITIES
** File description:
** ENTITIES
*/

#ifndef ENTITIES
#define ENTITIES

#include "Entity.hpp"
#include "../Timer.hpp"


class Border : public Entity {
    public:
        Border(std::pair <long int, long int> coord, std::string id = "border", std::string path = "")
            : Entity(coord, id, path) {};
        ~Border() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};

class Monster : public Entity {
    public:
        Monster(std::pair <long int, long int> coord, std::string id = "monster", std::string path = "")
            : Entity(coord, id, path) {};
        ~Monster() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};

class Player : public Entity {
    private:
        COMMAND m_direction;
        Timer m_timer;
    public:
        Player(std::pair <long int, long int> coord, std::string id = "player_up", std::string path = "");
        ~Player();
        std::string getId() const; // pas de maj pour les id.
        Type getType() const;
        std::string getValue() const;
        void setPlayerDirection(COMMAND d_direction);
        void move(void);
        void action(std::vector <IObjectToDraw *> &objects);
        void impact(std::vector <IObjectToDraw *> &objects);
};

class Target : public Entity {
    public:
        Target(std::pair <long int, long int> coord, std::string id = "target", std::string path = "")
            : Entity(coord, id, path) {};
        ~Target() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};

class Lazer : public Entity {
    public:
        Lazer(std::pair <long int, long int> coord, std::string id = "lazer", std::string path = "")
            : Entity(coord, id, path) {};
        ~Lazer() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};
#endif /* !ENTITIES */
