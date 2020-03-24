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

#define M_FACTOR_UP std::make_pair(0, -1)
#define M_FACTOR_DOWN std::make_pair(0, 1)
#define M_FACTOR_LEFT std::make_pair(-1, 0)
#define M_FACTOR_RIGHT std::make_pair(0, 1)

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
        COMMAND m_command;
        COMMAND m_direction;
        Timer m_timer;
    public:
        Player(std::pair <long int, long int> coord, std::string id = "player_up", std::string path = "");
        ~Player();
        void setCommand(COMMAND command);
        std::string getId() const; // pas de maj pour les id.
        Type getType() const;
        std::string getValue() const;
        void setPlayerDirection(void);
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
    typedef enum OWNER {
        O_MONSTER,
        O_PLAYER
    } OWNER;
    private:
        std::pair <long int, long int> m_movementFactor;
        OWNER m_owner;
    public:
        Lazer(std::pair <long int, long int> coord, std::pair <long int, long int> movementFactor = {0, 0}, OWNER owner = O_MONSTER, std::string id = "lazer", std::string path = "");
        ~Lazer();
        std::string getId() const;
        Type getType() const;
        std::string getValue() const;
};

#endif /* !ENTITIES */
