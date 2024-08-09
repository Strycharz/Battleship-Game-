#include "Input.h"

#include <SFML/Graphics.hpp>

Input::Input()
{
}

void Input::update()
{
    lastFrameKeys.setMask(thisFrameKeys); // 1
    thisFrameKeys.setBit((int)Key::MOUSE_LEFT,
                         (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
    thisFrameKeys.setBit((int)Key::MOUSE_RIGHT,
                         (sf::Mouse::isButtonPressed(sf::Mouse::Right)));
    thisFrameKeys.setBit((int)Key::UP,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)));
    thisFrameKeys.setBit((int)Key::DOWN,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)));
    thisFrameKeys.setBit((int)Key::RETURN,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)));
}


bool Input::isKeyDown(Key keycode)
{
    bool lastFrame = lastFrameKeys.getBit((int)keycode);
    bool thisFrame = thisFrameKeys.getBit((int)keycode);
    
    return thisFrame && !lastFrame;
}

bool Input::isKeyPressed(Key keycode)
{
    return thisFrameKeys.getBit((int)keycode);
}

bool Input::isKeyUp(Key keycode)
{
    bool lastFrame = lastFrameKeys.getBit((int)keycode);
    bool thisFrame = thisFrameKeys.getBit((int)keycode);
    
    return !thisFrame && lastFrame;
}