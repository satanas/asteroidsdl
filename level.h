#ifndef __LEVEL_H_
#define _LEVEL_H_

#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "input.h"

using namespace std;


class Level {
    private:
        Input input;
        SDL_Surface *screen;
        static const int FPS = 30;
        bool running;

    public:
        Level(SDL_Surface *game_screen, Input game_input);
        void loop();
};

#endif
