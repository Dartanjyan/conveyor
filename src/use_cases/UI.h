#ifndef UI_H
#define UI_H

#include <iostream>
#include <memory>
#include "ICLI.h"
#include "IGUI.h"
#include "SpaceManager.h"

class UI {
private:
    IGUI* gui_;
    ICLI* cli_;
    std::unique_ptr<SpaceManager> spaceManager;
public:
    UI(IGUI* gui, ICLI* cli);

    int Run(bool gui);
    void setSpaceManager(std::unique_ptr<SpaceManager> spaceManager);
};

#endif
