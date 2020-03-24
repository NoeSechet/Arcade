/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sdl
*/

#ifndef GRAPHIC_SDL_HPP_
#define GRAPHIC_SDL_HPP_

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "IGraphicalInterface.hpp"

namespace graphical {

    class Graphic_sdl : public IGraphicalInterface {
        private:
            std::string m_name;
            std::pair<uint, uint> m_winSize;

            COMMAND m_command;
            SDL_Window *m_window;
            SDL_Renderer *renderer;
            SDL_Event m_event;
            SDL_Rect m_buttonSqr;

        public:
            Graphic_sdl(std::pair<uint, uint> winSize);
            ~Graphic_sdl();

            bool init();
            bool initAssets(std::vector<IObjectToDraw *> assets);
            bool destroyAssets();
            bool destroy();
            COMMAND getInput();
            bool draw(std::vector<IObjectToDraw *> objects);

            std::string GetName() const { return m_name; }
    };
}

#endif
