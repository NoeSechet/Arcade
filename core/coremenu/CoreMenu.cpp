/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreMenu
*/

#include "CoreMenu.hpp"

namespace games {

    CoreMenu::CoreMenu() {
        start();
    }

    CoreMenu::~CoreMenu() {}

    void CoreMenu::LoadClassFromChar(char c, long int x, long int y)
    {
        std::pair <long int, long int> coord = {x, y};
        menu::MenuElem *newObj = nullptr;

        switch (c) {
            case 'A':
                newObj = new menu::ArcadeButton(coord);
                m_objects.push_back(newObj);
                break;
            case 'F':
                newObj = new menu::SolarFoxButton(coord);
                m_selectableList.push_back(newObj);
                m_objects.push_back(newObj);
                break;
            case 'C':
                newObj = new menu::CentipedButton(coord);
                m_selectableList.push_back(newObj);
                m_objects.push_back(newObj);
                break;
            case 'N':
                newObj = new menu::NCursesButton(coord);
                m_selectableList.push_back(newObj);
                m_objects.push_back(newObj);
                break;
            case 'S':
                newObj = new menu::SFMLButton(coord);
                m_selectableList.push_back(newObj);
                m_objects.push_back(newObj);
                break;
            case 'D':
                newObj = new menu::SDLButton(coord);
                m_selectableList.push_back(newObj);
                m_objects.push_back(newObj);
                break;
            case '#':
                newObj = new menu::Border(coord);
                m_objects.push_back(newObj);
                break;
            default: break;
        }
    }

    bool CoreMenu::start()
    {
        size_t x = 0;
        size_t y = 0;
        std::string input = "";
        std::ifstream file("./core/coremenu/assets/menu");

        if (!file)
            throw std::logic_error("Could not open the level file : Core Menu");

        for (; getline(file, input); y += 1) {
            x = 0;
            for (; x < input.size(); x += 1)
                LoadClassFromChar(input[x], x, y);
        }
        m_levelSize.first = x;
        m_levelSize.second = y;
        file.close();
        SetDefaultSelection();
        return true;
    }

    bool CoreMenu::end()
    {
        return true;
    }

    std::vector<IObjectToDraw *> CoreMenu::getAssets() const
    {
        std::vector <IObjectToDraw *> assets;
        std::pair <long int, long int> d_coord = {0,0};

        assets.push_back(new menu::ArcadeButton(d_coord, "arcadebutton", "./core/coremenu/assets/arcadebutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::SolarFoxButton(d_coord, "solarfoxbutton", "./core/coremenu/assets/solarfoxbutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::CentipedButton(d_coord, "centipedbutton", "./core/coremenu/assets/centipedbutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::NCursesButton(d_coord, "ncursesbutton", "./core/coremenu/assets/ncursesbutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::SFMLButton(d_coord, "sfmlbutton", "./core/coremenu/assets/sfmlbutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::SDLButton(d_coord, "sdlbutton", "./core/coremenu/assets/sdlbutton/", std::make_tuple(0, 0, 200, 100)));
        assets.push_back(new menu::Border(d_coord, "border", "./games/solar_fox/assets/border/"));
        assets.push_back(new menu::MenuLevel(m_levelSize)); // push the levelSize object

        return assets;
    }

    int CoreMenu::applyInput(COMMAND userInput)
    {
        (void)userInput;

        switch (userInput) {
            case DOWN: MoveSelection(1); break;
            case RIGHT: MoveSelection(1); return 1; break;
            case UP: MoveSelection(-1); return 2; break;
            case LEFT: MoveSelection(-1); return 2; break;
            case ACTION: return 0; break;
            case EXIT: return -1;
            default: break;
        }

        return 1;
    }

    void CoreMenu::MoveSelection(int selDir)
    {
        size_t spot = 0;
        menu::MenuElem *em = m_selectableList[m_selPar];

        if ((spot = em->getId().find("SEL")) == std::string::npos)
            return;

        if (selDir > 0) {
            (m_selPar + selDir) > (m_selectableList.size() - 1) ? m_selPar = 0 : m_selPar += selDir;
        } else {
            ((int)m_selPar + selDir) < 0 ? m_selPar = (m_selectableList.size() - 1) : m_selPar += selDir;
        }

        em->SetSelected(false);
        em->setId(em->getId().substr(0, spot));
        em = m_selectableList[m_selPar];
        em->SetSelected(true);
        em->setId(em->getId() + "SEL");
    }

    void CoreMenu::SetDefaultSelection()
    {
        for (auto &o : m_selectableList)
        {
            if (o->getId().find("button") != std::string::npos)
            {
                o->SetSelected(true);
                o->setId(o->getId() + "SEL");
                return;
            }
            m_selPar += 1;
        }
    }

    std::vector<IObjectToDraw *> CoreMenu::compute()
    {
        return m_objects;
    }

}