#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

typedef struct ConsoleApp {
    char *name;
} ConsoleApp;

ConsoleApp* cgConsoleAppNew(char *name);

void cgConsoleAppFree(ConsoleApp *app);

int cgConsoleAppRun(ConsoleApp *app);

#endif
