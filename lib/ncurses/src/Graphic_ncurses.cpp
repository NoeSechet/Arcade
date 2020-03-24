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
        noecho();
        nodelay(stdscr, true);
        keypad(stdscr, true);
        return true;
    }

    bool Graphic_ncurses::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset)) continue;
            if (!asset->getPath().empty())
                m_assets.push_back(new AssetNcurses(asset->getId(), asset->getType(),
                    getFileContent(asset->getPath() + "terminal.txt")));
        }

        return true;
    }

    bool Graphic_ncurses::destroyAssets()
    {
        // for (size_t i = 0; i < m_assets.size(); i++) {
        //     if (m_assets[i])
        //         delete m_assets[i];
        // }
        m_assets.clear();
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
            case KEY_BACKSPACE: return ACTION;
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
        for (size_t i = 0; i < objects.size(); i++) {
            move(objects[i]->getCoords().second, objects[i]->getCoords().first);
            printw("%s", getObjectContent(objects[i]).c_str());
        }
        refresh();

        return true;
    }

    std::string Graphic_ncurses::getFileContent(std::string path)
    {
        std::string Input = "";
        std::ifstream File(path);
        std::string Content = "";

        std::cout << path << std::endl;

        if (!File) {
            std::cout << "NCurses library : Could not get the file content" << std::endl;
            exit(84);
        }
        while (getline(File, Input)) {
            Content.append(Input);
        }
        File.close();
        return Content;
    }

    bool Graphic_ncurses::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &a : m_assets) {
            if (object->getId().find(a->getId()) != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    std::string Graphic_ncurses::getObjectContent(IObjectToDraw *obj) const
    {
        for (auto &a : m_assets) {
            if (obj->getId().find(a->getId()) != std::string::npos)
                return a->getValue();
        }
        return std::string("");
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_ncurses;
        }
    }

}