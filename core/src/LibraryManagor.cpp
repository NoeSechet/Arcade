/*
** EPITECH PROJECT, 2020
** LIBRARY_MANAGOR
** File description:
** LIBRARY_MANAGOR
*/

#include "../include/LibraryManagor.hpp"


LibraryManagor::LibraryManagor()
{
    LoadLibraryInformation(m_GameLibrary, F_GAME_PATH, T_Game);
    LoadLibraryInformation(m_GraphicalLibrary, F_GRAPHICAL_PATH, T_Graphical);
}

LibraryManagor::~LibraryManagor()
{
}

void LibraryManagor::LoadLibraryInformation(std::vector <LibraryInformation> &Dest, std::string path, T_Library Type)
{
    std::string Input = "";
    std::ifstream File(path);

    if (!File) {
        std::cout << "Could not open the information files" << std::endl;
        exit(84);
    }
    while (getline(File, Input)) {
        Dest.push_back((LibraryInformation) {Input, FindNameLibrary(Input, Type)});

    }
    File.close();
}

std::string LibraryManagor::FindNameLibrary(std::string str, T_Library Type)
{
    switch (Type) {
        case T_Game: str = ReplaceSentences(str, "./games/lib_arcade_", ""); break;
        case T_Graphical: str = ReplaceSentences(str, "./lib/lib_arcade_", ""); break;
        default: break;
    }
    str = ReplaceSentences(str, ".so", "");
    return str;
}

std::string LibraryManagor::ReplaceSentences(std::string src, std::string search, std::string replace)
{
    std::string str = src;
    size_t p = str.find(search);

    while (p != std::string::npos) {
		str.replace(p, search.size(), replace);
		p = str.find(search, p + replace.size());
	}
    return (str);
}

std::vector <LibraryInformation> &LibraryManagor::GetGraphicalLibraryInformation(void)
{
    return m_GraphicalLibrary;
}

std::vector <LibraryInformation> &LibraryManagor::GetGameLibraryInformation(void)
{
    return m_GameLibrary;
}

LibraryInformation LibraryManagor::GetPrevGraphLib()
{
    if ((int)m_graphLibIte - 1 < 0) {
        m_graphLibIte = m_GraphicalLibrary.size() - 1;
    } else {
        m_graphLibIte -= 1;
    }
    return m_GraphicalLibrary[m_graphLibIte];
}

LibraryInformation LibraryManagor::GetNextGraphLib()
{
    if (m_graphLibIte + 1 > m_GraphicalLibrary.size() - 1) {
        m_graphLibIte = 0;
    } else {
        m_graphLibIte += 1;
    }
    return m_GraphicalLibrary[m_graphLibIte];
}

LibraryInformation LibraryManagor::GetPrevGameLib()
{
    if ((int)m_graphLibIte - 1 < 0) {
        m_graphLibIte = m_GameLibrary.size() - 1;
    } else {
        m_graphLibIte -= 1;
    }
    return m_GameLibrary[m_graphLibIte];
}

LibraryInformation LibraryManagor::GetNextGameLib()
{
    if (m_graphLibIte + 1 > m_GameLibrary.size() - 1) {
        m_graphLibIte = 0;
    } else {
        m_graphLibIte += 1;
    }
    return m_GameLibrary[m_graphLibIte];
}