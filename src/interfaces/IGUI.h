#ifndef IGUI_H
#define IGUI_H

#include <memory>
#include "SpaceManager.h"

class IGUI {
public:
    virtual ~IGUI() = default;

    // This function is responsible for running the GUI interface.
    virtual int Run() = 0;
    virtual int Init() = 0;
    virtual void setSpaceManager(std::unique_ptr<SpaceManager> space_manager) = 0;
};

#endif
