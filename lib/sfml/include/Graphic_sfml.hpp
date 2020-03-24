/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sfml
*/

#ifndef GRAPHIC_SFML_HPP_
#define GRAPHIC_SFML_HPP_

#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

#include "IGraphicalInterface.hpp"
#include "AssetSFML.hpp"

namespace graphical {

    class Graphic_sfml : public IGraphicalInterface {
        private:
            std::string m_name;
            std::pair<uint, uint> m_winSize;
            std::vector<AssetSFML *> m_assetList;
            std::pair<uint, uint> m_mapScale = {10,20};

            COMMAND m_command;
            sf::RenderWindow m_window;
            sf::Event m_event;

            std::shared_ptr<sf::Sprite> m_spriteHolder = nullptr;

        public:
            Graphic_sfml();
            ~Graphic_sfml();

            bool init();
            bool initAssets(std::vector<IObjectToDraw *> assets);
            bool destroyAssets();
            bool destroy();
            COMMAND getInput();
            bool draw(std::vector<IObjectToDraw *> objects);

            std::string GetName() const { return m_name; }

        private:
            AssetSFML *getObjectContent(IObjectToDraw *object) const;
            bool isAlreadyLoaded(IObjectToDraw *object) const;
            bool CheckAssetPath(std::string path);

    };

}

#endif /* !GRAPHIC_SFML_HPP_ */
