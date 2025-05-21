#include <stdio.h>

#include "console_app.h"

int main(int argc, char *argv[]) {
    ConsoleApp *app = cgConsoleAppNew("My application");
    cgConsoleAppRun(app);
    cgConsoleAppFree(app);
    return 0;
}

