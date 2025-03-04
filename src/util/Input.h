#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>

class Input
{
  public:
    static bool is_key_down(sf::Keyboard::Key key)
    {
        return sf::Keyboard::isKeyPressed(key);
    }
    static bool is_mouse_button_down(sf::Mouse::Button key)
    {
        return sf::Mouse::isButtonPressed(key);
    }
    static sf::Vector2i get_mouse_pos(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }

    Input() = delete;
};
#endif