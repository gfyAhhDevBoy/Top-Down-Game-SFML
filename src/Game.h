#include <SFML/Graphics.hpp>

#include <iostream>

#include "util/Input.h"
#include "Entity.h"

class Game
{
    typedef sf::Keyboard::Key Keys;

public:
    void init();
    void update();
    void render();

    bool should_close();

private:
    void process_events();

    sf::RenderWindow window;
};