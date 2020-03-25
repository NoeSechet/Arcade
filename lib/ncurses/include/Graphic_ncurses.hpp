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
            WINDOW *m_win = nullptr;
            std::pair<uint, uint> m_winSize;
            std::vector<AssetNcurses *> m_assetList;

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
            bool InitWindow(uint width, uint height);
            void PrintAsset(AssetNcurses &asset, uint x_coord, uint y_coord, bool selected);
            AssetNcurses *getObjectAsset(IObjectToDraw *object);
            std::string getFileContent(std::string path, uint &x_size, uint &y_size);
            bool isAlreadyLoaded(IObjectToDraw *object) const;
            void TurnOnHighlight();
            void TurnOffHighlight();
    };

}

// si objet on prend la position 0, si text on prend tout le contenu

#endif /* !GRAPHIC_NCURSES */