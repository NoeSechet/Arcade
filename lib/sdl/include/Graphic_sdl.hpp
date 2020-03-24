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
#include <unistd.h>
#include <sys/stat.h>

#include "IGraphicalInterface.hpp"
#include "AssetsSDL.hpp"

namespace graphical {

    class Graphic_sdl : public IGraphicalInterface {
        private:
            std::string m_name;
            std::pair<uint, uint> m_winSize;
            std::vector<AssetSDL *> m_assetList;
            std::pair<uint, uint> m_mapScale = {10,20};

            COMMAND m_command;
            SDL_Window *m_window;
            SDL_Renderer *renderer;
            SDL_Event m_event;
            SDL_Texture *m_textHolder = nullptr;

        public:
            Graphic_sdl();
            ~Graphic_sdl();

            bool init();
            bool initAssets(std::vector<IObjectToDraw *> assets);
            bool destroyAssets();
            bool destroy();
            COMMAND getInput();
            bool draw(std::vector<IObjectToDraw *> objects);
            bool isAlreadyLoaded(IObjectToDraw *object) const;
            std::string GetName() const { return m_name; }
            bool CheckAssetPath(std::string path);
            AssetSDL *getObjectContent(IObjectToDraw *object) const;

    };
}

#endif
