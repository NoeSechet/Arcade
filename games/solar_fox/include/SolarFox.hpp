/*
** EPITECH PROJECT, 2020
** SOLAR_FOX
** File description:
** SOLAR_FOX
*/

#ifndef SOLAR_FOX
#define SOLAR_FOX

#include "IGameInterface.hpp"
#include "Entities.hpp"

namespace games {

    class SolarFox : public IGameInterface {
        private:
            std::vector <IObjectToDraw *> m_objectToDraw;
            Player* m_player;
        public:
            SolarFox();
            ~SolarFox();

            bool start();
            bool end();
            std::vector <IObjectToDraw *> getAssets() const;
            int applyInput (COMMAND userInput);
            std::vector <IObjectToDraw *> compute();
            void loadClassFromChar(char c, long int x, long int y);
    };

}

#endif /* !SOLAR_FOX */