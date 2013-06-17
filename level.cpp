#include "level.h"

Level::Level(SDL_Surface *game_screen, Input game_input) {
    screen = game_screen;
    input = game_input;
}

void Level::loop() {
    running = true;
    Uint32 start_time, end_time, elapsed_time, tick;
    tick = 1000/FPS;

    SDL_Surface *spaceship = IMG_Load("data/images/spaceship.png");
    if (spaceship == NULL) {
        fprintf(stderr, "Couldn't load spaceship %s\n", IMG_GetError());
        return;
    }
    SDL_Rect dest;
    dest.x = screen->w/2 - 16;
    dest.y = screen->h/2 - 16;
    dest.w = spaceship->w;
    dest.h = spaceship->h;

    while (running) {
        start_time = SDL_GetTicks();

        input.handle_events();
        if (input.quit())
            break;

        if (input.keystroke(ESCAPE))
            break;

        if (input.keystroke(ENTER))
            cout << "Starting game..." << endl;

        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));

        SDL_BlitSurface(spaceship, NULL, screen, &dest);
        SDL_UpdateRects(screen, 1, &dest);

        SDL_Flip(screen);
        //SDL_FreeSurface(spaceship);
        end_time = SDL_GetTicks();
        elapsed_time = end_time - start_time;

        if (tick > elapsed_time)
            SDL_Delay(tick - elapsed_time);
    }
}
