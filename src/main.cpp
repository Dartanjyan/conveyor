#include "console_app.h"

int main(int argc, char *argv[]) {
    ConsoleApp* app = new ConsoleApp("My application");
    int result = app->run();
    delete app;
    return result;
}

