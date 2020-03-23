/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sfml
*/

#include "Graphic_sfml.hpp"

namespace graphical {

    Graphic_sfml::Graphic_sfml()
        : m_name("sfml"), m_winSize(std::make_pair<uint, uint>(1000, 800))
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

        m_window.create(sf::VideoMode(1000, 800), "sfml window");
        m_window.setFramerateLimit(30);
        m_window.setKeyRepeatEnabled(false);

        return true;
    }

    bool Graphic_sfml::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset)) {
                std::cout << "already loaded" << std::endl;
                continue;
            }
            if (asset->getId().compare("level") == 0) {
                if ((m_winSize.first = asset->getCoords().first * m_mapScale.first) == 0 ||
                (m_winSize.second = asset->getCoords().second * m_mapScale.second) == 0)
                    throw std::logic_error("Invalid map size.");
                m_window.setSize(sf::Vector2u(m_winSize.first, m_winSize.second));
            } else if (CheckAssetPath(asset->getPath()) == true) {
                m_assetList.push_back(new AssetSFML(asset->getId(),asset->getType(),asset->getPath(),asset->getSpritePos()));
            }
        }
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
        AssetSFML *asset = nullptr;
        std::pair<uint, uint> objCoord = {0,0};

        for (auto &obj : objectList)
        {
            if ((asset = getObjectContent(obj)) == nullptr) {
                // std::cerr << "Asset not found" << std::endl;
                continue;
            }
            if ((m_spriteHolder = asset->getSprite()) == nullptr) {
                // std::cerr << "Sprite not found" << std::endl;
                continue;
            }
            if (obj->getId().find("SEL") != std::string::npos) {
                m_spriteHolder->setColor(sf::Color(100, 100, 255, 255));
            } else {
                m_spriteHolder->setColor(sf::Color(255, 255, 255, 255));
            }
            objCoord = obj->getCoords();
            m_spriteHolder->setPosition(objCoord.first * m_mapScale.first, objCoord.second * m_mapScale.second);
            m_window.draw(*m_spriteHolder);
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
