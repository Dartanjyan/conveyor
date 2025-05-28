#ifndef ICLI_H
#define ICLI_H

#include <memory>
#include "SpaceManager.h"

class ICLI {
public:
    virtual ~ICLI() = default;

    // Initialization
    virtual int Init() = 0;

    // This function is responsible for running the CLI interface.
    virtual int Run() = 0;

    virtual void setSpaceManager(std::unique_ptr<SpaceManager> space_manager) = 0;

    virtual void ShowHelp() = 0;
    virtual void ShowVersion() = 0;
};

#endif
