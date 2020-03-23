/*
** EPITECH PROJECT, 2020
** LIBRARY_MANAGOR
** File description:
** LIBRARY_MANAGOR
*/

#ifndef LIBRARY_MANAGOR
#define LIBRARY_MANAGOR

#include <iostream>
#include <fstream>
#include <vector>

#define F_GAME_PATH "./core/libraries_information/game_information"
#define F_GRAPHICAL_PATH "./core/libraries_information/graphical_information"

typedef enum T_Library {
    T_Game,
    T_Graphical
} T_Library;

typedef struct LibraryInformation {
    std::string m_path;
    std::string m_name;
} LibraryInformation;

class LibraryManagor {
    private:
        std::vector <LibraryInformation> m_GraphicalLibrary;
        std::vector <LibraryInformation> m_GameLibrary;
        uint m_graphLibIte = -1;
        uint m_gameLibIte = -1;
    public:
        LibraryManagor();
        ~LibraryManagor();
        std::vector <LibraryInformation> &GetGraphicalLibraryInformation(void);
        std::vector <LibraryInformation> &GetGameLibraryInformation(void);

        void SetGraphLibIte(uint ite) { m_graphLibIte = ite; }
        void SetGameLibIte(uint ite) { m_gameLibIte = ite; }
        LibraryInformation GetPrevGraphLib();
        LibraryInformation GetNextGraphLib();
        LibraryInformation GetPrevGameLib();
        LibraryInformation GetNextGameLib();

    private:
        void LoadLibraryInformation(std::vector <LibraryInformation> &Dest, std::string path, T_Library Type);
        std::string FindNameLibrary(std::string str, T_Library Type);
        std::string ReplaceSentences(std::string src, std::string search, std::string replace);
};

#endif /* !LIBRARY_MANAGOR */
