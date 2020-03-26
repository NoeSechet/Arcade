/*
** EPITECH PROJECT, 2020
** GRAPHIC_NCURSES
** File description:
** GRAPHIC_NCURSES
*/

#include "../include/Graphic_ncurses.hpp"

#include <ncurses.h>
#include <iostream>
#include <fstream>

namespace graphical {

    Graphic_ncurses::Graphic_ncurses()
        : m_name("ncurses")
    {
        init();
    }

    Graphic_ncurses::~Graphic_ncurses()
    {}

    bool Graphic_ncurses::init()
    {
        if (initscr() == nullptr) return false;
        curs_set(0);
        noecho();
        nodelay(stdscr, true);
        keypad(stdscr, true);
        if (has_colors())
            start_color();
        return true;
    }

    bool Graphic_ncurses::InitWindow(uint width, uint height)
    {
        if (width == 0 || height == 0) {
            std::cout << "Level module undetected, resizing window..." << std::endl;
            width = 1000;
            height = 800;
        }

        m_win = newwin(width, height, 0, 0);

        return true;
    }

    bool Graphic_ncurses::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset))
                continue;

            if (asset->getId().compare("level") == 0)
            {
                m_winSize.first = asset->getCoords().first;
                m_winSize.second = asset->getCoords().second;
            }
            else if (!asset->getPath().empty()) {
                std::tuple<uint,uint,uint,uint> assetSize = {0,0,0,0};
                std::string value = getFileContent(asset->getPath() + "terminal.txt",
                    std::get<2>(assetSize), std::get<3>(assetSize)
                );
                // std::cout << std::get<2>(assetSize) << " " << std::get<3>(assetSize) << std::endl;
                m_assetList.push_back(new AssetNcurses(asset->getId(), asset->getType(),
                    value, assetSize));
            }
        }
        InitWindow(m_winSize.first, m_winSize.second);
        return true;
    }

    bool Graphic_ncurses::destroyAssets()
    {
        // for (size_t i = 0; i < m_assetList.size(); i++) {
        //     if (m_assetList[i])
        //         delete m_assetList[i];
        // }
        m_assetList.clear();
        return true;
    }

    bool Graphic_ncurses::destroy()
    {
        endwin();
        return true;
    }

    COMMAND Graphic_ncurses::getInput()
    {
        switch (getch()) {
            case KEY_UP: return UP;
            case KEY_RIGHT: return RIGHT;
            case KEY_DOWN: return DOWN;
            case KEY_LEFT: return LEFT;
            case ' ': return ACTION;
            case 'q': return PREV_GRAPH;
            case 'e': return NEXT_GRAPH;
            case 'a': return PREV_GAME;
            case 'd': return NEXT_GAME;
            default: return NO_INPUT;
        }
    }

    bool Graphic_ncurses::draw(std::vector<IObjectToDraw *> objects)
    {
        erase();
        for (auto &obj : objects) {
            PrintAsset(*getObjectAsset(obj),
                obj->getCoords().first / 32, // Based on sfml
                obj->getCoords().second / 32,
                (obj->getId().find("SEL") != std::string::npos)
            );
        }
        refresh();

        return true;
    }

    void Graphic_ncurses::PrintAsset(AssetNcurses &asset, uint x_coord, uint y_coord, bool selected)
    {
        std::string val = asset.getValue();
        size_t x_size = std::get<2>(asset.getSpritePos());
        size_t y_size = std::get<3>(asset.getSpritePos());
        size_t i = 0;
        std::vector<std::string> list;

        if (selected) {
            TurnOnHighlight();
        }

        for (size_t e = 0; e < y_size; e += 1)
        {
            list.push_back(val.substr(0, x_size));
            val = val.substr(x_size, val.size());
        }
        for (size_t k = 0; k < y_size; k += 1)
        {
            mvprintw(y_coord - (y_size/2) + k, x_coord - (x_size/2), list[k].c_str());
            i += 1;
        }
        TurnOffHighlight();
    }

    void Graphic_ncurses::TurnOnHighlight()
    {
        if (has_colors()) {
            init_pair(1, COLOR_YELLOW, COLOR_BLACK);
            attron(COLOR_PAIR(1));
        } else {
            attron(A_STANDOUT);
        }
    }

    void Graphic_ncurses::TurnOffHighlight()
    {
        if (has_colors()) {
            attroff(COLOR_PAIR(1));
        } else {
            attroff(A_STANDOUT);
        }
    }

    std::string Graphic_ncurses::getFileContent(std::string path, uint &x_size, uint &y_size)
    {
        std::string input = "";
        std::ifstream File(path);
        std::string content = "";

        // std::cout << path << std::endl;

        if (!File)
            throw std::logic_error("NCurses library : Could not get the file content");

        while (getline(File, input)) {
            input.size() > x_size ? x_size = input.size() : 0;
            content.append(input);
            y_size += 1;
        }
        File.close();
        return content;
    }

    bool Graphic_ncurses::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &a : m_assetList) {
            if (object->getId().find(a->getId()) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    AssetNcurses *Graphic_ncurses::getObjectAsset(IObjectToDraw *obj)
    {
        for (auto &a : m_assetList) {
            if (obj->getId().find(a->getId()) != std::string::npos)
                return a;
        }
        return nullptr;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_ncurses;
        }
    }

}