/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Graphic_sdl
*/

#include "Graphic_sdl.hpp"

namespace graphical {

    Graphic_sdl::Graphic_sdl(std::pair<uint, uint> winSize)
        : m_name("sdl"), m_winSize(winSize)
    {
        m_buttonSqr.w = 100;
        m_buttonSqr.h = 75;
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

    bool Graphic_sdl::initAssets(std::vector<IObjectToDraw *> assets)
    {
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

    bool Graphic_sdl::draw(std::vector<IObjectToDraw *> objects)
    {
        SDL_RenderClear(renderer);
/*
        for (auto &ite : objects) {
            // std::cout << ite->getCoords().first << " " << ite->getCoords().second << std::endl;
            m_buttonSqr.setPosition(ite->getCoords().first, ite->getCoords().second);
            m_buttonSqr.setFillColor(sf::Color(rand()));
            m_window.draw(m_buttonSqr);
            // std::cout << "salut" << std::endl;
        }
*/
        SDL_RenderPresent(renderer);
        return true;
    }

    extern "C" {
        IGraphicalInterface *LoadLibrary()
        {
            return new Graphic_sdl(std::make_pair(1000, 800));
        }
    }

}