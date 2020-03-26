/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MenuElem
*/

#ifndef MENUBUTTON_HPP_
#define MENUBUTTON_HPP_

#include "../../GlobalHeaders.hpp"

namespace menu {

    class MenuElem : public IObjectToDraw
    {
        private:
            std::pair<long int, long int> m_coord;
            std::string m_id;
            std::string m_path = "";
            std::tuple<uint, uint, uint, uint> m_sprPos;
            bool m_selected = false;
            std::tuple<uint, uint, uint, uint> m_color = {0,0,0,0};

        public:
            MenuElem(std::pair<uint, uint> coord, std::string id, std::string path,
            std::tuple<uint, uint, uint, uint> sprPos, bool selected)
                : m_coord(coord), m_id(id), m_path(path), m_sprPos(sprPos), m_selected(selected) {}
            ~MenuElem() {}

            virtual std::string getId() const { return m_id; }
            void setId(std::string id) { m_id = id; };
            std::string getPath() const { return m_path; }
            virtual Type getType() const { return objects; }
            virtual std::string getValue() const { return "val"; }
            std::pair<long int, long int> getCoords() const { return m_coord; }
            std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }

            std::tuple<uint, uint, uint, uint> getSpritePos() const { return m_sprPos; }
            void SetSelected(bool selected) { m_selected = selected; }

    };

    class MenuLevel : public MenuElem {
        public:
            MenuLevel(std::pair <long int, long int> levelSize, std::string id = "level", std::string path = "",
                std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(levelSize, id, path, sprPos, selected) {};
    };

    class Border : public MenuElem {
        public:
            Border(std::pair <long int, long int> coord, std::string id = "border", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {};
            ~Border() {};
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class ArcadeButton : public MenuElem
    {
        public:
            ArcadeButton(std::pair <long int, long int> coord, std::string id = "arcadebutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class CentipedButton : public MenuElem
    {
        public:
            CentipedButton(std::pair <long int, long int> coord, std::string id = "centipedbutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class SolarFoxButton : public MenuElem
    {
        public:
            SolarFoxButton(std::pair <long int, long int> coord, std::string id = "solarfoxbutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class NCursesButton : public MenuElem
    {
        public:
            NCursesButton(std::pair <long int, long int> coord, std::string id = "ncursesbutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class SFMLButton : public MenuElem
    {
        public:
            SFMLButton(std::pair <long int, long int> coord, std::string id = "sfmlbutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

    class SDLButton : public MenuElem
    {
        public:
            SDLButton(std::pair <long int, long int> coord, std::string id = "sdlbutton", std::string path = "",
            std::tuple<uint, uint, uint, uint> sprPos = { 0,0,0,0 }, bool selected = false)
                : MenuElem(coord, id, path, sprPos, selected) {}
            Type getType() const { return objects; };
            std::string getValue() const { return ""; };
    };

}

#endif /* !MENUBUTTON_HPP_ */
