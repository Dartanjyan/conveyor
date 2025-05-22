#include <iostream>

#include "sfml_app.h"

SFMLApp::SFMLApp(std::string name, unsigned int width, unsigned int height) : name(name), width(width), height(height) {}

SFMLApp::~SFMLApp() {
}

int SFMLApp::run() {
    int inc=1;
    std::cout<<inc++<<"\n";
    sf::RenderWindow window(sf::VideoMode(width, height), name);
    std::cout<<inc++<<"\n";
    sf::CircleShape shape(100.f);
    std::cout<<inc++<<"\n";
    shape.setFillColor(sf::Color::Green);
    std::cout<<inc++<<"\n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

