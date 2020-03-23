/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** description
*/

#ifndef OOP_ARCADE_2019_IGRAPHICALINTERFACE_HPP
#define OOP_ARCADE_2019_IGRAPHICALINTERFACE_HPP

#include <vector>

#include "../GlobalHeaders.hpp"


namespace graphical {

    class IGraphicalInterface
    {
    public:
        virtual ~IGraphicalInterface() = default;
        virtual bool init() = 0;                                            // initialize window
        virtual bool initAssets(std::vector<IObjectToDraw *> assets) = 0;   // initialize assets for each type of object
        virtual bool destroyAssets() = 0;                                   // destroy assets for each type of object
        virtual bool destroy() = 0;                                         // destroy window
        virtual COMMAND getInput() = 0;                                     // get User Input
        virtual bool draw(std::vector<IObjectToDraw *> objects) = 0;        // draw next frame
    };

} // namespace graphical

#endif //OOP_ARCADE_2019_IGRAPHICALINTERFACE_HPP
