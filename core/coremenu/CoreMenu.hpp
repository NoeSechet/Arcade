/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreMenu
*/

#ifndef COREMENU_HPP_
#define COREMENU_HPP_

#include <fstream>
#include <iostream>
#include <tuple>

#include "../../games/IGameInterface.hpp"
#include "../../lib/IGraphicalInterface.hpp"
#include "MenuButton.hpp"

namespace games {

    class CoreMenu : public games::IGameInterface
    {
        private:
            std::pair<unsigned int, unsigned int> m_winDim;
            std::vector<menu::MenuElem *> m_selectableList;
            std::vector<IObjectToDraw *> m_objects;

            std::pair<uint, uint> m_levelSize = {0,0};
            size_t m_selPar = 0;

        public:
            CoreMenu();
            ~CoreMenu();

            // -- Interface functions
            bool start();
            bool end();
            std::vector<IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector<IObjectToDraw *> compute();
            // --

        private:
            void LoadClassFromChar(char c, long int x, long int y);
            void SetDefaultSelection();
            void MoveSelection(int selDir);

    };

}
#endif /* !COREMENU_HPP_ */
