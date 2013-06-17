#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdlib.h>
#include <iostream>
#include <map>
#include "SDL.h"

using namespace std;

const int ESCAPE = 27;
const int ENTER = 13;

class Input {
    private:
        map<int, bool> pressed_keys;
        map<int, bool> bound_keys;
        map<int, bool> repeat_keys;

        map<int, bool> clicked_mouse_buttons;
        map<int, bool> bound_mouse_buttons;
        map<int, bool> repeat_mouse_buttons;
        bool running;
        void reset();
    public:
        static const int MOUSE_LEFT_BUTTON = 1;
        static const int MOUSE_MIDDLE_BUTTON = 2;
        static const int MOUSE_RIGHT_BUTTON = 3;

        void init();
        void handle_events();
        void register_key(int key, bool repeat = false);
        void register_mouse_button(int button);
        bool keystroke(int key);
        bool mouse_button(int button);
        bool quit();
};

#endif

