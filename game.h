#ifndef __GAME_H_
    #define _GAME_H_

#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "input.h"

using namespace std;


class Game {
    private:
        bool running;
        int screenWidth, screenHeight;
        Input input;
        bool Init();
        int Loop();

    public:
        Game();


};

#endif

