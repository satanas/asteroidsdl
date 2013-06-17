#ifndef _GAME_H_
#define _GAME_H_

#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "global.h"
#include "input.h"
#include "menu.h"

using namespace std;


class Game {
    private:
        Input input;
        SDL_Surface *screen;

        bool init();
        int loop();
        bool load_fonts();

    public:
        Game();

};

#endif

