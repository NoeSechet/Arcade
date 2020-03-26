/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AssetSFML
*/

#ifndef ASSETSFML_HPP_
#define ASSETSFML_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "../../../GlobalHeaders.hpp"

class AssetSFML : public IObjectToDraw {
    private:
        std::string m_id;
        Type m_type = objects;
        std::string m_value = "";
        std::shared_ptr<sf::Sprite> m_spr = nullptr;
        std::shared_ptr<sf::Texture> m_tex = nullptr;
        sf::Vector2u m_texSize = { 0, 0 };
        std::pair<long int, long int> m_coord = { 0,0 };
        std::tuple<uint, uint, uint, uint> m_spriPos = { 0,0,0,0 };
        std::tuple<uint, uint, uint, uint> m_color = {0,0,0,0};

    public:
        AssetSFML(const std::string &id, Type type, const std::string &path, std::tuple<uint, uint, uint, uint> sprRec)
            : m_id(id), m_type(type), m_tex(std::make_shared<sf::Texture>()), m_spriPos(sprRec)
        {
            if (!m_tex->loadFromFile(path + "texture.png"))
                throw std::logic_error("Texture not found. Maybe the given path is invalid");
            m_spr = std::make_shared<sf::Sprite>(
                        *m_tex,
                        sf::IntRect(std::get<0>(sprRec),
                                    std::get<1>(sprRec),
                                    std::get<2>(sprRec),
                                    std::get<3>(sprRec))
                    );
            m_texSize = m_tex->getSize();
        };
        ~AssetSFML() {};

        // -- Interface Functions
        std::string getId() const { return m_id; };
        std::string getPath() const { return std::string(""); };
        Type getType() const {return m_type; };
        std::string getValue() const { return m_value; };
        std::pair<long int, long int> getCoords() const { return m_coord; };
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return m_spriPos; }
        std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }
        // --

        std::shared_ptr<sf::Sprite> getSprite() { return m_spr; }

};

#endif /* !ASSETSFML_HPP_ */
