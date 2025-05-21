#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

class ConsoleApp {
    char* name;
public:
    ConsoleApp();
    ConsoleApp(char* name);
    ~ConsoleApp();

    int run();
}

#endif
