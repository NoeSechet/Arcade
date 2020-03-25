/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sfml
*/

#include "Graphic_sfml.hpp"

namespace graphical {

    Graphic_sfml::Graphic_sfml()
        : m_name("sfml"), m_winSize(std::make_pair<uint, uint>(0, 0))
    {
        init();
    }

    Graphic_sfml::~Graphic_sfml()
    {
        std::cout << "Terminated sfml lib" << std::endl;
    }

    bool Graphic_sfml::init()
    {
        std::cout << "Initialized sfml lib" << std::endl;

        return true;
    }

    bool Graphic_sfml::InitWindow(uint width, uint height)
    {
        if (width == 0 || height == 0) {
            std::cout << "Level module undetected, resizing window..." << std::endl;
            width = 1000;
            height = 800;
        }
        m_window.create(sf::VideoMode(width, height), "sfml window");
        m_window.setFramerateLimit(30);
        m_window.setKeyRepeatEnabled(false);

        return true;
    }

    bool Graphic_sfml::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset))
                continue;

            if (asset->getId().compare("level") == 0)
            {
                m_winSize.first = asset->getCoords().first * m_mapScale.first;
                m_winSize.second = asset->getCoords().second * m_mapScale.second;
            }
            else if (CheckAssetPath(asset->getPath()) == true) {
                m_assetList.push_back(new AssetSFML(asset->getId(),asset->getType(),asset->getPath(),asset->getSpritePos()));
            }
        }
        InitWindow(m_winSize.first, m_winSize.second);
        return true;
    }

    bool Graphic_sfml::destroyAssets()
    {
        return true;
    }

    bool Graphic_sfml::destroy()
    {
        return true;
    }

    COMMAND Graphic_sfml::getInput()
    {
        while (m_window.pollEvent(m_event)) {
            if (m_event.type == sf::Event::Closed)
               return EXIT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) return UP;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) return DOWN;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) return LEFT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) return RIGHT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) return ACTION;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) return PREV_GRAPH;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) return NEXT_GRAPH;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) return PREV_GAME;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) return NEXT_GAME;
        return NO_INPUT;
    }

    bool Graphic_sfml::draw(std::vector<IObjectToDraw *> objectList)
    {
        m_window.clear();
        AssetSFML *assetPtr = nullptr;
        std::shared_ptr<sf::Sprite> spritePtr = nullptr;
        std::pair<uint, uint> objCoord = {0,0};

        for (auto &obj : objectList)
        {
            if ((assetPtr = getObjectContent(obj)) == nullptr)
                continue;
            if ((spritePtr = assetPtr->getSprite()) == nullptr)
                continue;

            if (obj->getId().find("SEL") != std::string::npos)
                spritePtr->setColor(sf::Color(100, 100, 255, 255));
            else
                spritePtr->setColor(sf::Color(255, 255, 255, 255));

            objCoord = obj->getCoords();
            spritePtr->setPosition(
                objCoord.first * m_mapScale.first - std::get<2>(assetPtr->getSpritePos()) / 4,  // 4 because the m_mapscale values are not the same
                objCoord.second * m_mapScale.second - std::get<3>(assetPtr->getSpritePos()) / 2 // 2 because the m_mapscale values are not the same
            );
            m_window.draw(*spritePtr);
        }

        m_window.display();
        return true;
    }

    bool Graphic_sfml::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &asset : m_assetList) {
            if (object->getId().find(asset->getId()) == 0) {
                return true;
            }
        }
        return false;
    }

    AssetSFML *Graphic_sfml::getObjectContent(IObjectToDraw *object) const
    {
        // std::cout << object->getId() << std::endl;
        for (auto asset : m_assetList) {
            if (object->getId().find(asset->getId()) == 0) {
                return asset;
            }
        }
        return nullptr;
    }

    bool Graphic_sfml::CheckAssetPath(std::string path)
    {
        struct stat buffer;

        if (stat (path.append("texture.png").c_str(), &buffer) == 0) {
            return true;
        }
        return false;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_sfml();
        }
    }

}
