#ifndef SFML_APP_H
#define SFML_APP_H

#include <string>
#include <SFML/Graphics.hpp>

class SFMLApp {
    std::string name;
    unsigned width, height;
public:
    SFMLApp(std::string name = "Application", unsigned int width = 200, unsigned int height = 200);
    ~SFMLApp();

    int run();
};

#endif
