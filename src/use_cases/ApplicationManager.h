#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <string>
#include <memory>
#include "IUI.h"

namespace ApplicationManager
{
    // This function is the entry point for the application manager.
    // It takes command line arguments and a UI interface as parameters.
    // The function is responsible for managing the application lifecycle and rendering.
    int Run(int argc, char** argv, std::unique_ptr<IUI> ui);
}

#endif
