#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <optional>
#include <vector>

#include "util/Input.h"
#include "util/ResourceManager.h"

#include "Camera.h"
#include "GameObject.h"
#include "Player.h"

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

    sf::Clock deltaclock;
    sf::Time deltatime;

    std::vector<GameObject *> gameobjs;
    Player *player;
    GameObject *test;

    sf::RenderWindow *window;
};
#endif