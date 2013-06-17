#include "game.h"

Game::Game() {
    if (!init())
        exit(-1);
    loop();
}

bool Game::init() {
    input.init();
    input.register_key(ESCAPE, false);
    input.register_key(ENTER, false);

    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 ) {
        cout << "Unable to init SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    //Initialize all standard SDL subsystems
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1)
        return false;

    //Initialize SDL_mixer
    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 1024) == -1)
        return false;

    if (!load_fonts())
        return false;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWSURFACE);
    SDL_WM_SetCaption("Asteroids SDL", NULL);

    return true;
}

bool Game::load_fonts() {
    //Initialize SDL_ttf
    if (TTF_Init() == -1) {
        cout << "Unable to init SDL_ttf: " << TTF_GetError() << endl;
        return false;
    }

    //main_title_font = TTF_OpenFont("data/fonts/zerothre.ttf", 30);

    //if (main_title_font == NULL) {
    //    cout << "Coudn't load fonts";
    //    return false;
    //}
    return true;
}

int Game::loop() {
    Menu menu(screen, input);
    menu.loop();
    return 0;
}
