#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <string>
#include "ICLI.h"

class ConsoleApp: public ICLI {
    std::string name;
public:
    ConsoleApp(std::string name = "Application");

    int Run() override;
    int Init() override;

    void ShowHelp() override {}
    void ShowVersion() override {}
};

#endif
