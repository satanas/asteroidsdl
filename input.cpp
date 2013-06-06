#include "input.h"

void Input::init() {
    for (int i=0; i < SDL_NumJoysticks(); i++) {
        cout << SDL_JoystickName(i) << endl;
    }
}

void Input::reset() {
    running = true;

    for (map<int, bool>::iterator it = pressed_keys.begin(); it != pressed_keys.end(); it++) {
        int key = it->first;
        map<int, bool>::iterator rt = repeat_keys.find(key);
        if (rt == repeat_keys.end() || !rt->second) {
            pressed_keys.erase(key);
        }
    }

    clicked_mouse_buttons.clear();
}

void Input::register_key(int key, bool repeat) {
    bound_keys[key] = true;
    repeat_keys[key] = repeat;
}

void Input::register_mouse_button(int button) {
    bound_mouse_buttons[button] = true;
}

void Input::handle_events() {
    SDL_Event event;

    reset();

    while(SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            int key = event.key.keysym.sym;
            map<int, bool>::iterator it = bound_keys.find(key);
            if (it != bound_keys.end()) {
                pressed_keys.insert(make_pair(key, true));
            }
        }
        if (event.type == SDL_KEYUP) {
            int key = event.key.keysym.sym;
            map<int, bool>::iterator it = pressed_keys.find(key);
            if (it != pressed_keys.end()) {
                pressed_keys.erase(key);
            }
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int button = event.button.button;
            map<int, bool>::iterator it = bound_mouse_buttons.find(button);
            if (it != bound_mouse_buttons.end()) {
                clicked_mouse_buttons.insert(make_pair(button, true));
            }
        }

        if (event.type == SDL_MOUSEBUTTONUP) {
            int button = event.button.button;
            map<int, bool>::iterator it = clicked_mouse_buttons.find(button);
            if (it != clicked_mouse_buttons.end()) {
                clicked_mouse_buttons.erase(button);
            }
        }
    }
}

bool Input::keystroke(int key) {
    map<int, bool>::iterator it = pressed_keys.find(key);
    if (it != pressed_keys.end()) {
        return it->second;
    }
    return false;
}

bool Input::mouse_button(int button) {
    map<int, bool>::iterator it = clicked_mouse_buttons.find(button);
    if (it != clicked_mouse_buttons.end()) {
        return it->second;
    }
    return false;
}

bool Input::quit() {
    return !running;
}
