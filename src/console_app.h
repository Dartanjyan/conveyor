#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <string>

class ConsoleApp {
    std::string name;
public:
    ConsoleApp(std::string name = "Application");

    int run();
};

#endif
