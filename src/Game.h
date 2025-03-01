#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "util/Input.h"
#include "util/ResourceManager.h"

#include "GameObject.h"

class Game
{
    typedef sf::Keyboard::Key Keys;

  public:
    void init();
    void run();

    inline bool is_open()
    {
        return window->isOpen();
    };

  private:
    void process_events();
    void update();
    void render();

    float deltaTime;

    sf::RenderWindow *window;
};
#endif