#include <iostream>
#include "ConsoleApp.h"
#include "Conveyor.h"
#include "Transform.h"
#include "Size.h"

ConsoleApp::ConsoleApp(std::string name): name(name) {}

void ConsoleApp::setSpaceManager(std::unique_ptr<SpaceManager> space_manager) {
    this->spaceManager = std::move(space_manager);
}

int ConsoleApp::Init() {
    std::cout<<"\n\n\nWelcome to my application!\n\nApp name is \""<<name<<"\".\n\n";
    return 0;
}

int ConsoleApp::Run() {
    std::cout<<"Creating a Conveyor.\n";
    
    Conveyor* conv = new Conveyor(Transform(0, 0, 0), Size(), 1);

    std::cout<<"Created conveyor! Pos: ("<<conv->getTransform().getX()<<", "<<conv->getTransform().getY()<<"), rotation: "<<conv->getTransform().getAngle()<<", level: "<<(int)conv->getLevel()<<", size: ("<<(int)conv->getSize().getWidth()<<", "<<(int)conv->getSize().getHeight()<<").\n";

    delete conv;

    return 0;
}

