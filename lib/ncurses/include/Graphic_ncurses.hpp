/*
** EPITECH PROJECT, 2020
** GRAPHIC_NCURSES
** File description:
** GRAPHIC_NCURSES
*/

#ifndef GRAPHIC_NCURSES
#define GRAPHIC_NCURSES

#include <ncurses.h>
#include "../include/AssetNcurses.hpp"
#include "IGraphicalInterface.hpp"

namespace graphical {

    class Graphic_ncurses : public IGraphicalInterface {
        private:
            std::string m_name;
            std::vector<AssetNcurses *> m_assets;
        public:
            Graphic_ncurses();
            ~Graphic_ncurses();

            bool init();
            bool initAssets(std::vector<IObjectToDraw *> assets);
            bool destroyAssets();
            bool destroy();
            COMMAND getInput();
            bool draw(std::vector<IObjectToDraw *> objects);
            std::string GetName() const { return m_name; }

        private:
            std::string getObjectContent(IObjectToDraw *object) const;
            std::string getFileContent(std::string path);
            bool isAlreadyLoaded(IObjectToDraw *object) const;
    };

}

// si objet on prend la position 0, si text on prend tout le contenu

#endif /* !GRAPHIC_NCURSES */