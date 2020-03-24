/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <iostream>

template<typename T_Lib>
class DLLoader {
    public:
        DLLoader();
        ~DLLoader();

        static void *LoadLib(const std::string &defaultLib)
        {
            void *handle = dlopen(defaultLib.c_str(), RTLD_LAZY);

            if (!handle) {
                fprintf(stderr, "nope wrong lib name\n");
                exit (EXIT_FAILURE);
            }
            return handle;
        }

        static T_Lib *GetInstance(void *handle)
        {
            char *error = nullptr;
            T_Lib *(*LoadLib)() = nullptr;
            LoadLib = (T_Lib *(*)())dlsym(handle, "entryPoint");

            if ((error = dlerror()) != NULL)
                throw std::logic_error(error);

            T_Lib *dyLib = (T_Lib *)LoadLib();

            return dyLib;
        }

        static void UnloadLib(void *handle)
        {
            if (handle == nullptr) {
                throw std::logic_error("Can't close unexistent lib");
            }
            dlclose(handle);
            handle = nullptr;
        }

};

#endif /* !DLLOADER_HPP_ */
