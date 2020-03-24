/*
** EPITECH PROJECT, 2020
** ENTITY
** File description:
** ENTITY
*/

#ifndef ENTITY
#define ENTITY

#include "../GlobalHeaders.hpp"
#include <vector>

class Entity : public IObjectToDraw {
    protected:
        std::pair <long int, long int> m_coord = {0, 0};
        std::string m_id = "";
        std::string m_path = "";
        bool m_toClear = false;
    public:
        Entity(std::pair <long int, long int> coord, std::string id, std::string path) { m_coord = coord; m_id = id; m_path = path; };
        ~Entity();
        virtual std::string getId() const { return "Entity"; };
        bool getToClear(void) const { return m_toClear; };
        void setId(std::string id) { m_id = id; };
        std::string getPath() const { return m_path; }; // "append le bon nom du fichier"
        virtual Type getType() const { return objects; };
        virtual std::string getValue() const { return "";};
        std::pair <long int, long int> getCoords() const { return m_coord; };
        void setCoords(std::pair<long int, long int> coord) { m_coord = coord; };
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return std::make_tuple(0, 0, 0, 0); };

        virtual void move(void) {};
        virtual void action(std::vector <IObjectToDraw *> &objects) {};
        virtual void impact(std::vector <IObjectToDraw *> &objects) {};
};

// créer une fonction bool quidis si il reste des elements morts

#endif /* !ENTITY */