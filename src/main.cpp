#include <iostream>

#include "console_app.h"

int main(int argc, char *argv[]) {
    bool gui = true;
    for (int i = 1; i < argc; ++i) {
        auto arg = static_cast<std::string>(argv[i]);
        std::cout << "Got arg \""<<arg<<"\". ";
        
        if (arg == "--nogui") {
            gui = false;
            std::cout << "Set gui bool to "<<gui<<".\n";
        }
        else {
            std::cout << "This does not mean anything.\n";
        }
    }
    
    std::cout<<"-----------------------------------\n\n";

    int result = 0;
    if (gui == false) {
        std::cout << "Launching application in CLI mode...\n";
        ConsoleApp* app = new ConsoleApp("My application");
        result = app->run();
        delete app;
    } else {
        std::cout << "Launching application in GUI mode...\n";
        std::cout << "Na razie nie jest zrobione to więc kręć się jak chcesz\n";
    }

    return result;
}

