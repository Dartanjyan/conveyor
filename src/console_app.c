#include <stdlib.h>
#include <stdio.h>
#include "console_app.h"
#include "conveyor.h"
#include "pos.h"
#include "enums.h"
#include "size.h"

ConsoleApp *cgConsoleAppNew(char* name) {
    struct ConsoleApp* app = (struct ConsoleApp*)malloc(sizeof(ConsoleApp));
    if (app == NULL) {
        return NULL;
    }
    app->name = name;
    return app;
}

void cgConsoleAppFree(ConsoleApp *app)  {
    free(app);
}

int cgConsoleAppRun(ConsoleApp *app) {
    printf("\n\n\nWelcome to my application!\n\nApp name is \"%s\".\n\n", app->name);
    printf("Creating a Conveyor.\n");
    
    Pos pos = {0, 0};
    Size size = {1, 1};
    Conveyor* conv = cgConveyorNew(pos, ROT_NORTH, 1, size);

    if (conv == NULL) {
        printf("Couldn't create conveyor\n");
        return -1;
    }

    printf("Created conveyor! Pos: (%d, %d), rotation: %d, level: %d, size: (%d, %d).\n",
            conv->pos.x, conv->pos.y, conv->rotation, conv->level, conv->size.width, conv->size.height);

    cgConveyorFree(conv);

    return 0;
}

