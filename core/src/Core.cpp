/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"
#include "../../games/IGameInterface.hpp"// tmp

Core::Core(const std::string &defaultLibPath)
    : m_libManager(new LibraryManagor)
{
    if (!m_libManager || CheckLibName(defaultLibPath) == -1)
        throw std::logic_error("Argument line: invalid library name");
    m_graphLibHand = DLLoader<graphical::IGraphicalInterface>::LoadLib(defaultLibPath);
    m_graphLib = DLLoader<graphical::IGraphicalInterface>::GetInstance(m_graphLibHand);
    m_coreMenu = new games::CoreMenu();
    m_step = MAIN_MENU;
}

Core::~Core()
{
    if (m_graphLib != nullptr)
        delete m_graphLib;
    if (m_gameLib != nullptr)
        delete m_gameLib;
    if (m_graphLibHand)
        DLLoader<graphical::IGraphicalInterface>::UnloadLib(m_graphLibHand);
    if (m_gameLibHand)
        DLLoader<games::IGameInterface>::UnloadLib(m_gameLibHand);
    if (m_coreMenu)
        delete m_coreMenu;
}

int Core::CheckLibName(const std::string &defaultLibPath)
{
    int i = 0;

    for (auto ite : m_libManager->GetGraphicalLibraryInformation()) {
        if (defaultLibPath.compare(ite.m_path) == 0) {
            m_libManager->SetGraphLibIte(i);
            return 1;
        }
        i += 1;
    }
    return -1;
}

int Core::MenuStep()
{
    int value = 0;

    value = m_coreMenu->applyInput(m_input);

    if (m_graphLib->draw(m_coreMenu->compute()) == false)
        return -1;

    switch (value) {
        case -1: m_input = EXIT; break;
        case 0: m_step = GAME; break;
        default: break;
    }

    return 1;
}

int Core::GameStep()
{
    // m_gameLib->applyInput(m_input);

    // m_graphLib->draw(m_gameLib->compute());

    return 1;
}

int Core::loop()
{
    m_gameLibHand = DLLoader<games::IGameInterface>::LoadLib("./games/lib_arcade_SolarFox.so");
    m_gameLib = DLLoader<games::IGameInterface>::GetInstance(m_gameLibHand);
    m_graphLib->initAssets((m_coreMenu->getAssets()));

    m_graphLib->initAssets(m_gameLib->getAssets());
    m_gameLib->start();
    m_graphLib->init();

    while (1)
    {
        m_gameLib->applyInput(m_graphLib->getInput());
        m_graphLib->draw(m_gameLib->compute());
    }

    // while (m_input != EXIT)
    // {
    //     m_input = m_graphLib->getInput();
    //     switch (m_step) {
    //         case MAIN_MENU: MenuStep(); break;
    //         case GAME: GameStep(); break;
    //         default: break;
    //     }
    //     switch (m_input) {
    //         case PREV_GRAPH: ChangeGraphLib(m_libManager->GetPrevGraphLib().m_path); break;
    //         case NEXT_GRAPH: ChangeGraphLib(m_libManager->GetNextGraphLib().m_path); break;
    //         case PREV_GAME: ChangeGameLib(m_libManager->GetPrevGameLib().m_path); break;
    //         case NEXT_GAME: ChangeGameLib(m_libManager->GetNextGameLib().m_path); break;
    //         default:  break;
    //     }
    // }
    return 1;
}

int Core::ChangeGraphLib(std::string libPath)
{
    std::cout << "getting previous graph lib: " << libPath << std::endl;
    if (m_graphLib != nullptr)
        delete m_graphLib;
    m_graphLib = nullptr;
    DLLoader<graphical::IGraphicalInterface>::UnloadLib(m_graphLibHand);
    m_graphLibHand = DLLoader<graphical::IGraphicalInterface>::LoadLib(libPath);
    m_graphLib = DLLoader<graphical::IGraphicalInterface>::GetInstance(m_graphLibHand);
    m_graphLib->initAssets((m_coreMenu->getAssets()));
    return 1;
}

int Core::ChangeGameLib(std::string libPath)
{
    std::cout << "getting previous game lib" << std::endl;
    if (m_gameLib != nullptr)
        delete m_gameLib;
    m_gameLib = nullptr;
    DLLoader<games::IGameInterface>::UnloadLib(m_gameLibHand);
    std::cout << "here" << std::endl;

    m_gameLibHand = DLLoader<games::IGameInterface>::LoadLib(libPath);
    m_gameLib = DLLoader<games::IGameInterface>::GetInstance(m_gameLibHand);
    return 1;
}