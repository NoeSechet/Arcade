/*
** EPITECH PROJECT, 2020
** SOLAR_FOX
** File description:
** SOLAR_FOX
*/

#include "../include/SolarFox.hpp"
#include <fstream>
#include <iostream>
#include "../include/Entities.hpp"

// include une clock
// afficher le score
namespace games {

    SolarFox::SolarFox()
    {}

    SolarFox::~SolarFox()
    {}

    void SolarFox::loadClassFromChar(char c, long int x, long int y)
    {
        std::pair <long int, long int> coord = {x, y};

        switch (c) {
            case 'M': m_objectToDraw.push_back(new Monster(coord)); break;
            case '^': m_player = new Player(coord); m_objectToDraw.push_back(m_player);  break;
            case '*': m_objectToDraw.push_back(new Target(coord)); break;
            case '#': m_objectToDraw.push_back(new Border(coord)); break;
            default: break;
        }
    }

    bool SolarFox::start()
    {
        size_t x = 0;
        size_t y = 0;
        std::string input = "";
        std::ifstream file("./games/solar_fox/assets/level");

        if (!file)
            throw std::logic_error("Could not open the level file : SolarFox level");

        for (; getline(file, input); y += 1) {
            x = 0;
            for (; x < input.size(); x += 1)
                loadClassFromChar(input[x], x, y);
        }
        file.close();
        return true;
    }

    bool SolarFox::end()
    {
        m_objectToDraw.clear();
        return true;
    }

    std::vector <IObjectToDraw *> SolarFox::getAssets() const
    {
        std::vector <IObjectToDraw *> assets;
        std::pair <long int, long int> default_coord = {0,0};

        assets.push_back(new Player(default_coord, "player_up", "./games/solar_fox/assets/player_up/"));
        assets.push_back(new Player(default_coord, "player_down", "./games/solar_fox/assets/player_down/"));
        assets.push_back(new Player(default_coord, "player_right", "./games/solar_fox/assets/player_right/"));
        assets.push_back(new Player(default_coord, "player_left", "./games/solar_fox/assets/player_left/"));
        assets.push_back(new Border(default_coord, "border", "./games/solar_fox/assets/border/"));
        assets.push_back(new Monster(default_coord, "monster", "./games/solar_fox/assets/monster/"));
        assets.push_back(new Target(default_coord, "target", "./games/solar_fox/assets/target/"));
        assets.push_back(new Lazer(default_coord, default_coord, Lazer::O_PLAYER, "lazer", "./games/solar_fox/assets/lazer/"));
        return assets;
    }

    int SolarFox::applyInput (COMMAND userInput)
    {
        m_player->setCommand(userInput);
        switch (userInput) {
            case UP: m_player->setPlayerDirection(); break;
            case DOWN: m_player->setPlayerDirection(); break;
            case LEFT: m_player->setPlayerDirection(); break;
            case RIGHT: m_player->setPlayerDirection(); break;
            case ACTION: break;
            case MAIN_MENU: break;
            case EXIT: break;
            default: break;
        }
        return 0;
    }

    std::vector <IObjectToDraw *> SolarFox::compute()
    {                                                   
        for (size_t i = 0; i < m_objectToDraw.size(); i++) {
           static_cast <Entity *> (m_objectToDraw[i])->move();
           static_cast <Entity *> (m_objectToDraw[i])->action(m_objectToDraw);
           static_cast <Entity *> (m_objectToDraw[i])->impact(m_objectToDraw);
        }
        clearMemory();
        return m_objectToDraw;
    }

    void SolarFox::clearMemory(void)
    {
        for (size_t i = 0; i < m_objectToDraw.size(); i++) {
            if (static_cast <Entity *> (m_objectToDraw[i])->getToClear() == true) {
                if (static_cast <Entity *> (m_objectToDraw[i])->getId().compare("player"))
                    m_player = nullptr;
                // delete static_cast <Entity *> (m_objectToDraw[i]);
                m_objectToDraw.erase(m_objectToDraw.begin() + i);
                return clearMemory();
            }
        }
        if (m_player == nullptr) exit(0);
    }

    extern "C" {
        IGameInterface *entryPoint()
        {
            return new SolarFox;
        }
    }
}


// faire recursivité, des que tu sup un element, tu return ta fonction