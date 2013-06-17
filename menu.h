#ifndef __MENU_H_
    #define _MENU_H_

#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

#include "input.h"

using namespace std;


class Menu {
    private:
        Input input;
        SDL_Surface *screen;
        static const int FPS = 30;
        bool running;

    public:
        Menu(SDL_Surface *game_screen, Input game_input);
        void loop();
};

#endif
