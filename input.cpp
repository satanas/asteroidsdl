#include "input.h"

void Input::init() {
    for (int i=0; i < SDL_NumJoysticks(); i++) {
        cout << SDL_JoystickName(i) << endl;
    }
}

void Input::clear() {
    for (map<int, bool>::iterator it = pressed_keys.begin(); it != pressed_keys.end(); it++) {
        int key = it->first;
        map<int, bool>::iterator rt = repeat_keys.find(key);
        if (rt == repeat_keys.end() || !rt->second) {
            pressed_keys.erase(key);
        }
    }
}

void Input::bind_key(int key, bool repeat) {
    bound_keys[key] = true;
    repeat_keys[key] = repeat;
}

void Input::handle() {
    SDL_Event event;

    clear();
    running = true;

    while(SDL_PollEvent(&event)) {
        int key = event.key.keysym.sym;

        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == KEY_DOWN) {
            map<int, bool>::iterator it = bound_keys.find(key);
            if (it != bound_keys.end()) {
                pressed_keys.insert(make_pair(key, true));
            }
        }
        if (event.type == KEY_UP) {
            map<int, bool>::iterator it = pressed_keys.find(key);
            if (it != pressed_keys.end()) {
                pressed_keys.erase(key);
            }
        }
    }
}

bool Input::lookup(int key) {
    map<int, bool>::iterator it = pressed_keys.find(key);
    if (it != pressed_keys.end()) {
        return it->second;
    }
    return false;
}

bool Input::quit() {
    return !running;
}
