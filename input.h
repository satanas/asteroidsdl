#include <stdlib.h>
#include <iostream>
#include <map>
#include "SDL.h"

using namespace std;

const int KEY_DOWN = SDL_KEYDOWN;
const int KEY_UP = SDL_KEYUP;

class Input {
    private:
        map<int, bool> pressed_keys;
        map<int, bool> bound_keys;
        map<int, bool> repeat_keys;
        bool running;
        bool any;
        void clear();
    public:
        void init();
        void handle();
        void bind_key(int key, bool repeat = false);
        bool lookup(int key);
        bool quit();
};

