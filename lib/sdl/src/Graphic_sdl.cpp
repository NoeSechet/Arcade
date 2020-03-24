/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Graphic_sdl
*/

#include "Graphic_sdl.hpp"

namespace graphical {

    Graphic_sdl::Graphic_sdl()
        : m_name("sdl"), m_winSize(std::make_pair<uint, uint>(1000, 800))
    {
        init();
    }

    Graphic_sdl::~Graphic_sdl()
    {
        std::cout << "Terminated sdl lib" << std::endl;
    }

    bool Graphic_sdl::init()
    {
        std::cout << "Initialized sdl lib" << std::endl;

        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
        SDL_CreateWindowAndRenderer(m_winSize.first, m_winSize.second, SDL_WINDOW_SHOWN, &m_window, &renderer);
        return true;
    }

    bool Graphic_sdl::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset)) {
                std::cout << "already loaded" << std::endl;
                continue;
            }
            if (asset->getId().compare("level") == 0) {
                if ((m_winSize.first = asset->getCoords().first * m_mapScale.first) == 0 ||
                (m_winSize.second = asset->getCoords().second * m_mapScale.second) == 0)
                    throw std::logic_error("Invalid map size.");
                SDL_SetWindowSize(m_window, m_mapScale.first, m_mapScale.second);
            } else if (CheckAssetPath(asset->getPath()) == true) {
                m_assetList.push_back(new AssetSDL(asset->getId(), asset->getType(), asset->getPath(), asset->getSpritePos(), renderer));
            }
        }
        return true;
    }

    bool Graphic_sdl::destroyAssets()
    {
        return true;
    }

    bool Graphic_sdl::destroy()
    {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(renderer);
        TTF_Quit();
        SDL_Quit();
        return true;
    }

    COMMAND Graphic_sdl::getInput()
    {
        // std::cout << "getting user input" << std::endl;

        SDL_WaitEvent(&m_event);
        if (m_event.window.event == SDL_WINDOWEVENT_CLOSE)
               return EXIT;

        if (m_event.key.keysym.sym == SDLK_UP)
            return UP;
        if (m_event.key.keysym.sym == SDLK_DOWN)
            return DOWN;
        if (m_event.key.keysym.sym == SDLK_LEFT)
            return LEFT;
        if (m_event.key.keysym.sym == SDLK_RIGHT)
            return RIGHT;
        if (m_event.key.keysym.sym == SDLK_RETURN)
            return ACTION;
        if (m_event.key.keysym.sym == SDLK_q)
            return PREV_GRAPH;
        if (m_event.key.keysym.sym == SDLK_e)
            return NEXT_GRAPH;
        if (m_event.key.keysym.sym == SDLK_a)
            return PREV_GAME;
        if (m_event.key.keysym.sym == SDLK_d)
            return NEXT_GAME;
        return NO_INPUT;
    }

    bool Graphic_sdl::draw(std::vector<IObjectToDraw *> objectList)
    {
        SDL_RenderClear(renderer);
        AssetSDL *asset = nullptr;
        std::pair<uint, uint> objCoord = {0,0};
        SDL_Rect texr;

        for (auto &obj : objectList)
        {
            if ((asset = getObjectContent(obj)) == nullptr) {
                // std::cerr << "Asset not found" << std::endl;
                continue;
            }
            if ((m_textHolder = asset->getTex()) == nullptr) {
                // std::cerr << "Sprite not found" << std::endl;
                continue;
            }
            if (obj->getId().find("SEL") != std::string::npos) {
                SDL_SetTextureColorMod(m_textHolder, 100, 100, 255);
            } else {
                SDL_SetTextureColorMod(m_textHolder, 255, 255, 255);
            }
            objCoord = obj->getCoords();
            texr.x = objCoord.first * m_mapScale.first;
            texr.y = objCoord.second * m_mapScale.second;
            texr.w = asset->getRect().w;
            texr.h = asset->getRect().h;
            SDL_RenderCopy(renderer, m_textHolder, NULL, &texr);
        }

        SDL_RenderPresent(renderer);
        return true;
    }

    bool Graphic_sdl::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &asset : m_assetList) {
            if (object->getId().find(asset->getId()) == 0) {
                return true;
            }
        }
        return false;
    }

    AssetSDL *Graphic_sdl::getObjectContent(IObjectToDraw *object) const
    {
        // std::cout << object->getId() << std::endl;
        for (auto asset : m_assetList) {
            if (object->getId().find(asset->getId()) == 0) {
                return asset;
            }
        }
        return nullptr;
    }

    bool Graphic_sdl::CheckAssetPath(std::string path)
    {
        struct stat buffer;

        if (stat (path.append("texture.png").c_str(), &buffer) == 0) {
            return true;
        }
        return false;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_sdl();
        }
    }
}