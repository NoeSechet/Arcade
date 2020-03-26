/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centiped
*/

#ifndef CENTIPED_HPP_
#define CENTIPED_HPP_

#include <string>

#include "IGameInterface.hpp"

namespace games {

    class Centiped : public IGameInterface {
        private:
            std::vector <IObjectToDraw *> m_objectToDraw;
        public:
            Centiped();
            ~Centiped();

            bool start();
            bool end();
            std::vector <IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector <IObjectToDraw *> compute();
    };

}

#endif /* !CENTIPED_HPP_ */
