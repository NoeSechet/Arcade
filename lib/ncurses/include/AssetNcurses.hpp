/*
** EPITECH PROJECT, 2020
** ASSETNCURSES
** File description:
** ASSETNCURSES
*/

#ifndef ASSETNCURSES
#define ASSETNCURSES

#include "../../../GlobalHeaders.hpp"
#include "tuple"

class AssetNcurses : public IObjectToDraw  {
    private:
        std::string m_id;
        Type m_type = objects;
        std::string m_value = "";
        std::tuple<uint, uint, uint, uint> m_spriPos = { 0,0,0,0 };


    public:
        AssetNcurses(std::string id, Type type, std::string value, std::tuple<uint, uint, uint, uint> sprRec)
            : m_id(id), m_type(type), m_value(value), m_spriPos(sprRec) {}

        ~AssetNcurses() {};

        // -- Interface Functions
        std::string getId() const { return m_id; };
        std::string getPath() const { return std::string(""); };
        Type getType() const {return m_type; };
        std::string getValue() const {return m_value; };
        std::pair<long int, long int> getCoords() const { return std::pair <long int, long int>(); };
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return m_spriPos; };
        // --
};

#endif /* !ASSETNCURSES */