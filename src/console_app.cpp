#include <iostream>
#include "console_app.h"
#include "conveyor.h"
#include "pos.h"
#include "enums.h"
#include "size.h"

ConsoleApp::ConsoleApp(std::string name): name(name) {}

int ConsoleApp::run() {
    std::cout<<"\n\n\nWelcome to my application!\n\nApp name is \""<<name<<"\".\n\n";
    std::cout<<"Creating a Conveyor.\n";
    
    Pos pos(0, 0);
    Size size(1, 1);
    Conveyor* conv = new Conveyor(pos, ROT_NORTH, 1, size);

    std::cout<<"Created conveyor! Pos: ("<<conv->pos.x<<", "<<conv->pos.y<<"), rotation: "<<(int)conv->rotation<<", level: "<<(int)conv->level<<", size: ("<<(int)conv->size.width<<", "<<(int)conv->size.height<<").\n";

    delete conv;

    return 0;
}

