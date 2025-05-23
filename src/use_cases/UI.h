#ifndef UI_H
#define UI_H

#include <iostream>
#include "ICLI.h"
#include "IGUI.h"
#include "IUI.h"

class UI : public IUI
{
public:
    UI(IGUI* gui, ICLI* cli);
    ~UI() override;

    int Run(bool gui) override;
private:
    IGUI* gui_;
    ICLI* cli_;
};

#endif
