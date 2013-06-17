#include "menu.h"

Menu::Menu(SDL_Surface *game_screen, Input game_input) {
    screen = game_screen;
    input = game_input;
}

void Menu::loop() {
    bool show_press_enter = true;
    running = true;
    Uint32 start_time, end_time, elapsed_time, tick, blink;
    tick = 1000/FPS;

    TTF_Font *main_title_font = TTF_OpenFont("data/fonts/zerothre.ttf", 60);
    TTF_Font *small_font = TTF_OpenFont("data/fonts/zerothre.ttf", 20);

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

        SDL_Color white = {255, 255, 255};
        SDL_Surface *main_title = TTF_RenderText_Solid(main_title_font, "AsteroidSDL", white);
        int w, h;
        TTF_SizeText(main_title_font, "AsteroidSDL", &w, &h);
        SDL_Rect title_rect = {(screen->w - w)/2, 200};
        SDL_BlitSurface(main_title, NULL, screen, &title_rect);

        // Blink the "Press Enter" text
        if (blink >= 10) {
            blink = 0;
            show_press_enter = !show_press_enter;
        }

        if (show_press_enter) {
            SDL_Surface *press_enter = TTF_RenderText_Solid(small_font, "Press ENTER", white);
            TTF_SizeText(small_font, "Press ENTER", &w, &h);
            SDL_Rect press_enter_rect = {(screen->w - w)/2, 300};
            SDL_BlitSurface(press_enter, NULL, screen, &press_enter_rect);
        }


        SDL_Flip(screen);
        end_time = SDL_GetTicks();
        elapsed_time = end_time - start_time;
        blink++;

        if (tick > elapsed_time)
            SDL_Delay(tick - elapsed_time);
    }
}
