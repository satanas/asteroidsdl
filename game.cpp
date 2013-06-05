#include "game.h"

Game::Game() {
    Init();
    Loop();
}

bool Game::Init() {
    running = true;
    screenWidth = 640;
    screenHeight = 480;

    input.init();
    input.bind_key(32, false);

    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 ) {
        cout << "Unable to init SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    //Initialize all standard SDL subsystems
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1)
        return false;

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
        return false;

    //Initialize SDL_mixer
    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 1024) == -1)
        return false;

    //Create the screen
    SDL_SetVideoMode(screenWidth, screenHeight, 0, SDL_HWSURFACE);

    //Set the window caption
    SDL_WM_SetCaption("Asteroids SDL", NULL);

    //If everything initialized fine
    return true;
}

int Game::Loop() {

    while (running) {
        input.handle();
        if (input.quit())
            break;
        if (input.lookup(32))
            cout << "espacio" << endl;
    }
    return 0;
}
