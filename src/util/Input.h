#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>

class Input
{
  public:
    static bool isKeyDown(sf::Keyboard::Key key)
    {
        return sf::Keyboard::isKeyPressed(key);
    }
    static bool isMouseButtonDown(sf::Mouse::Button key)
    {
        return sf::Mouse::isButtonPressed(key);
    }
    static sf::Vector2i getMousePos(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }

    Input() = delete;
};
#endif