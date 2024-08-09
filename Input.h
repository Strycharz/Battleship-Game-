#ifndef INPUT_H
#define INPUT_H

#include "Bitmask.h"

class Input
{
    public:
        enum class Key
        {
            MOUSE_LEFT = 0,
            MOUSE_RIGHT = 1,
            UP = 3, 
            DOWN = 4,
            RETURN = 5
        };

        Input();

        void update();

        bool isKeyPressed(Key keycode); // Returns true if the key is pressed.
        bool isKeyDown(Key keycode); // Returns true if the key was just pressed.
        bool isKeyUp(Key keycode); // Returns true if the key was just released.

    private:
        Bitmask thisFrameKeys;
        Bitmask lastFrameKeys;
};

#endif