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
            Player* m_player = nullptr;
        public:
            SolarFox();
            ~SolarFox();
            bool start();
            bool end();
            std::vector <IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector <IObjectToDraw *> compute();
            void loadClassFromChar(char c, long int x, long int y);
            void clearMemory(std::vector <IObjectToDraw *> &objects);
            bool isPlayer(std::string id) const;
    };

}

#endif /* !SOLAR_FOX */